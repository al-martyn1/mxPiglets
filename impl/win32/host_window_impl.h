#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//
#include <atlframe.h>
#include <atlmisc.h>
#include <atlctrls.h>
#include <atlctrlw.h>
#include <atldlgs.h>
#include <atlscrl.h>
#include <atlprint.h>
#include <atlcrack.h>

//
#include <memory>

//
#include "../../i_host_window.h"
#include "../../checked_pimpl.h"
#include "../../cursor.h"
#include "../../token_dictionary.h"
//
#include "window_timer_impl.h"
#include "cursor_handles_holder.h"
#include "cursor_impl.h"
//
#include "marty_dc_impl_win32/multi_dc.h"

namespace mxPiglets {


#include "../../warnings/push_disable_copy_ctor_implicitly_deleted.h"



template<typename TParent>
class HostWindowImpl : public TParent
                     , public IHostWindow
{

    mutable UINT_PTR                          m_curTimerId          = 1; // Переделать на атомики???
    bool                                      m_bMouseTracking      = false;
    //bool                m_mouseCaptured       = false;

    // Чтобы постоянно думми не создавать, создадим заранее всё, что нужно, в OnCreate, а в OnTimer просто будем менять идентификатор таймера
    mutable std::shared_ptr<WindowTimerImpl>  m_pWindowTimerImplForOnTimer;
    mutable std::shared_ptr<IWindowTimer>     m_pIWindowTimerForOnTimer;

    mutable taborder_t                        m_autoTabOrderCounter = 0;

    std::shared_ptr<ITokenDictionary>         m_pTokenDictionary;
    
    mutable HDC                               m_hdcOnPaintSaved = 0; //!< тут мы сохраняем HDC, котоый был передан в DoPaint



public:

    HostWindowImpl()
    {
    }

    void setMsgHandled(BOOL bHandled = TRUE)
    {
        static_cast<TParent*>(this)->SetMsgHandled(bHandled);
    }

    void setMsgNotHandled()
    {
        setMsgHandled(FALSE);
    }

    HWND getHwnd() const
    {
        return static_cast<const TParent*>(this)->m_hWnd;
    }

    virtual bool isValid() const override
    {
        auto hWnd = getHwnd();
        return hWnd!=0 && (::IsWindow(hWnd)?true:false);
    }


protected:

    void trackMouseEvent()
    {
        TRACKMOUSEEVENT trme;
        trme.cbSize      = sizeof(trme);
        trme.dwFlags     = TME_HOVER | TME_LEAVE;
        trme.hwndTrack   = m_hWnd;
        trme.dwHoverTime = (DWORD)HOVER_DEFAULT;

        if (_TrackMouseEvent(&trme))
        {
            m_bMouseTracking = true;
        }
    }

public:

    // Обработка оконных сообщений

    BEGIN_MSG_MAP(CBitmapView)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_CLOSE(OnClose)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_TIMER(OnTimer)
        MSG_WM_KEYDOWN(OnKeyDown)
        MSG_WM_KEYUP(OnKeyUp)
        MSG_WM_CAPTURECHANGED(OnCaptureChanged)

        // //MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
        // MSG_WM_SIZE(OnSize)
        // MSG_WM_SIZING(OnSizing)
        //  
        // MSG_WM_CAPTURECHANGED(OnCaptureChanged)
        //  
        MSG_WM_MOUSEHOVER(OnMouseHover)
        MSG_WM_MOUSELEAVE(OnMouseLeave)

        MSG_WM_MOUSEWHEEL(OnMouseWheel)

        MSG_WM_MOUSEMOVE(OnMouseMove)

        MSG_WM_LBUTTONDOWN(OnLButtonDown)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_LBUTTONDBLCLK(OnLButtonDblClk)
         
        MSG_WM_RBUTTONDOWN(OnRButtonDown)
        MSG_WM_RBUTTONUP(OnRButtonUp)
        MSG_WM_RBUTTONDBLCLK(OnRButtonDblClk)
         
        MSG_WM_MBUTTONDOWN(OnMButtonDown)
        MSG_WM_MBUTTONUP(OnMButtonUp)
        MSG_WM_MBUTTONDBLCLK(OnMButtonDblClk)
         
        MSG_WM_XBUTTONDOWN(OnXButtonDown)
        MSG_WM_XBUTTONUP(OnXButtonUp)
        MSG_WM_XBUTTONDBLCLK(OnXButtonDblClk)

        CHAIN_MSG_MAP(TParent);

    END_MSG_MAP()

protected:

    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getdc
    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getdcex
    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-releasedc
    // GetDC/GetDCEx - ReleaseDC

    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowdc
    // GetWindowDC - ReleaseDC

    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-beginpaint
    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-endpaint
    // BeginPaint - EndPaint

    // https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-createdca
    // https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-deletedc
    // CreateDC - DeleteDC

    // enum class HdcReleaseMode : std::uint32_t
    // {
    //     invalid     = (std::uint32_t)(-1),
    //     unknown     = (std::uint32_t)(-1),
    //     doNothing   = 0,
    //     endPaint    = 1,
    //     releaseDc   = 2,
    //     deleteDc    = 3
    //  
    // }; // enum class HdcReleaseMode : std::uint32_t


    void configureCanvas(std::shared_ptr<mxPiglets::ICanvas> pCanvas) const
    {
        pCanvas->setStringEncoding("UTF-8");
        pCanvas->setBkMode( marty_draw_context::BkMode::transparent );
        pCanvas->setSmoothingMode(marty_draw_context::SmoothingMode::antiAlias); // highSpeed highQuality antiAlias defMode none
    }


    std::shared_ptr<mxPiglets::ICanvas> createCanvasImpl(bool useHdcSaved) const
    {
        #if !defined(MARTY_DRAW_CONTEXT_NO_MULTIDC)

            auto pdc = marty_draw_context::makeSharedMultiDrawContextGdi( useHdcSaved ? m_hdcOnPaintSaved : ::GetDC(getHwnd())
                                                                        #if !defined(MARTY_DRAW_CONTEXT_NO_GDIPLUS)
                                                                        , false // not prefferGdiPlus
                                                                        #else
                                                                        , true // prefferGdiPlus
                                                                        #endif
                                                                        , useHdcSaved ? marty_draw_context::HdcReleaseMode::doNothing /* endPaint */ : marty_draw_context::HdcReleaseMode::releaseDc
                                                                        , getHwnd()
                                                                        );
            configureCanvas(pdc);
            return pdc;

        #else

            #if !defined(MARTY_DRAW_CONTEXT_NO_GDIPLUS)
                auto pdc = std::make_shared<GdiPlusDrawContext>( useHdcSaved ? m_hdcOnPaintSaved : ::GetDC(getHwnd())
                                                               , useHdcSaved ? marty_draw_context::HdcReleaseMode::doNothing /* endPaint */ : marty_draw_context::HdcReleaseMode::releaseDc
                                                               , getHwnd()
                                                               );
            #else
                auto pdc = std::make_shared<GdiDrawContext>    ( useHdcSaved ? m_hdcOnPaintSaved : ::GetDC(getHwnd())
                                                               , useHdcSaved ? marty_draw_context::HdcReleaseMode::doNothing /* endPaint */ : marty_draw_context::HdcReleaseMode::releaseDc
                                                               , getHwnd()
                                                               );
            #endif

            configureCanvas(pdc);
            return std::static_pointer_cast<mxPiglets::ICanvas>(pdc);

        #endif
    }

    std::shared_ptr<mxPiglets::ICanvas> createCanvasDeleteDcImpl(HDC hdc) const
    {
        #if !defined(MARTY_DRAW_CONTEXT_NO_MULTIDC)

            auto pdc = marty_draw_context::makeSharedMultiDrawContextGdi( hdc
                                                                        #if !defined(MARTY_DRAW_CONTEXT_NO_GDIPLUS)
                                                                        , false // not prefferGdiPlus
                                                                        #else
                                                                        , true // prefferGdiPlus
                                                                        #endif
                                                                        , marty_draw_context::HdcReleaseMode::deleteDc
                                                                        , getHwnd()
                                                                        );
            configureCanvas(pdc);
            return pdc;

        #else

            #if !defined(MARTY_DRAW_CONTEXT_NO_GDIPLUS)
                auto pdc = std::make_shared<GdiPlusDrawContext>( useHdcSaved ? hdc : ::GetDC(getHwnd())
                                                               , marty_draw_context::HdcReleaseMode::deleteDc
                                                               , getHwnd()
                                                               );
            #else
                auto pdc = std::make_shared<GdiDrawContext>    ( useHdcSaved ? hdc : ::GetDC(getHwnd())
                                                               , marty_draw_context::HdcReleaseMode::deleteDc
                                                               , getHwnd()
                                                               );
            #endif

            configureCanvas(pdc);
            return std::static_pointer_cast<mxPiglets::ICanvas>(pdc);

        #endif
    }

    virtual std::shared_ptr<mxPiglets::ICanvas> getCanvas() const override
    {
        return createCanvasImpl(false /* not useHdcSaved */ );
    }


    virtual std::shared_ptr<mxPiglets::ICanvas> getCanvasForPaintEvent() const override
    {
        if (m_hdcOnPaintSaved==0)
        {
            return std::shared_ptr<mxPiglets::ICanvas>();
        }

        return createCanvasImpl(true /* useHdcSaved */ );
    }

    CPoint getClientSizePoint() const
    {
        RECT clientRect{0,0};
        ::GetClientRect(getHwnd(), &clientRect);

        auto cx = clientRect.right  - clientRect.left; // + 1;
        auto cy = clientRect.bottom - clientRect.top ; // + 1;

        return CPoint(cx,cy);
    }


    marty_draw_context::IHdc* getIHdcFromCanvas(ICanvas *pCanvas) const
    {
        marty_draw_context::IHdc *pIHdc = 0;

        // GdiDrawContext
        // GdiPlusDrawContext
        // MultiDrawContextGdi

        if (!pIHdc && dynamic_cast<marty_draw_context::GdiDrawContext*>(pCanvas))
        {
            auto pImplBase = dynamic_cast<marty_draw_context::GdiDrawContext*>(pCanvas);
            pIHdc = dynamic_cast<marty_draw_context::IHdc*>(pImplBase);
        }

        if (!pIHdc && dynamic_cast<marty_draw_context::GdiPlusDrawContext*>(pCanvas))
        {
            auto pImplBase = dynamic_cast<marty_draw_context::GdiPlusDrawContext*>(pCanvas);
            pIHdc = dynamic_cast<marty_draw_context::IHdc*>(pImplBase);
        }

        if (!pIHdc && dynamic_cast<marty_draw_context::MultiDrawContextGdi*>(pCanvas))
        {
            auto pImplBase = dynamic_cast<marty_draw_context::MultiDrawContextGdi*>(pCanvas);
            pIHdc = dynamic_cast<marty_draw_context::IHdc*>(pImplBase);
        }

        return pIHdc;
    }

    //! Создаёт "теневой" канвас для оффскрин отрисовки, чтобы отображение не сильно мерцало.
    virtual std::shared_ptr<ICanvas> createOffscreenCanvas(std::shared_ptr<ICanvas> pCanvas) const override
    {
        auto pRawCanvas = pCanvas.get();
        if (!pRawCanvas)
        {
            return pCanvas;
        }

        marty_draw_context::IHdc *pIHdc = getIHdcFromCanvas(pRawCanvas);
        if (pIHdc==0)
        {
            return pCanvas;
        }

        HDC hScreenDc = pIHdc->getHdc();
        if (hScreenDc==0)
        {
            return pCanvas;
        }

        CPoint clientSize = getClientSizePoint();

        HDC hMemDc = ::CreateCompatibleDC(hScreenDc);
        if (hMemDc==0)
        {
            return pCanvas;
        }

        HBITMAP hMemBmp    = ::CreateCompatibleBitmap(hScreenDc, clientSize.x, clientSize.y );
        HBITMAP hOldMemBmp = (HBITMAP)::SelectObject(hMemDc, (HGDIOBJ)hMemBmp);

        RECT clRect;
        clRect.left   = 0;
        clRect.top    = 0;
        clRect.right  = clientSize.x;
        clRect.bottom = clientSize.y;
        ::FillRect(hMemDc, &clRect, (HBRUSH)COLOR_WINDOW);

        pIHdc->setHbmpDelete(hOldMemBmp);
    // virtual HBITMAP getHbmpDelete() const = 0;
    // virtual void    setHbmpDelete(HBITMAP hbmp) const = 0;

        auto pSharedOffscreenCanvas = createCanvasDeleteDcImpl(hMemDc);
        return pSharedOffscreenCanvas;
    }

    //! Копирует содержимое теневого канвас в экранный. По умолчанию - ничего не делает
    virtual void copyOffsceenToScreenCanvas(std::shared_ptr<ICanvas> pCanvasCopyFrom, std::shared_ptr<ICanvas> pCanvasCopyTo) const override
    {
        ICanvas *pRawCanvasCopyFrom = pCanvasCopyFrom.get();
        ICanvas *pRawCanvasCopyTo   = pCanvasCopyTo.get();

        if (!pRawCanvasCopyFrom || !pRawCanvasCopyTo || pRawCanvasCopyFrom==pRawCanvasCopyTo)
        {
            return;
        }

        marty_draw_context::IHdc *pIHdcFrom = getIHdcFromCanvas(pRawCanvasCopyFrom);
        marty_draw_context::IHdc *pIHdcTo   = getIHdcFromCanvas(pRawCanvasCopyTo);
        if (!pIHdcFrom || !pIHdcTo)
        {
            return;
        }

        HDC hdcFrom = pIHdcFrom->getHdc();
        HDC hdcTo   = pIHdcTo  ->getHdc();
        if (!hdcFrom || !hdcTo)
        {
            return;
        }

        CPoint clientSize = getClientSizePoint();

        ::BitBlt( hdcTo       // A handle to the destination device context.
                , 0, 0           //dstX, dstY   // The x/y-coordinates, in logical units, of the upper-left corner of the destination rectangle.
                , clientSize.x, clientSize.y         // The width/height, in logical units, of the source and destination rectangles.
                , hdcFrom    // hdcCopyFrom  // A handle to the source device context.
                , 0, 0           // The x/y-coordinate, in logical units, of the upper-left corner of the source rectangle.
                , SRCCOPY        // A raster-operation code - Copies the source rectangle directly to the destination rectangle.
                );

        // Исходный HBITMAP разрушается
        HBITMAP hFromSavedBitmap = pIHdcFrom->getHbmpDelete(); // Получаем тут сохранённый hbmp
        if (hFromSavedBitmap!=0) // не нулевой
        {
            HBITMAP hBmpDelete = (HBITMAP)::SelectObject(hdcFrom, (HGDIOBJ)hFromSavedBitmap); // восстановили исходный hbmp, который был изначально в HDC
            ::DeleteObject((HGDIOBJ)hBmpDelete); // Удаляем битмап, который был использован, как поверхность для рисования
            pIHdcFrom->setHbmpDelete(0); // не надо ничего удалять
        }

    }

    //marty_draw_context::IHdc

    // //! Копирует содержимое теневого канвас в экранный. По умолчанию - ничего не делает
    // virtual void copyOffsceenToScreenCanvas(std::shared_ptr<ICanvas> pCanvasCopyFrom, std::shared_ptr<ICanvas> pCanvasCopyTo) const 
    // {
    //     // Просто ничего не делаем
    //     MARTY_ARG_USED(pCanvasCopyFrom);
    //     MARTY_ARG_USED(pCanvasCopyTo);
    // }
    //  



public:

    void DoPaint(CDCHandle dc)
    {
        m_hdcOnPaintSaved = dc;
        onWindowPaintEvent();
        m_hdcOnPaintSaved = 0;
    }


protected:

    int OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        MARTY_ARG_USED(lpCreateStruct);
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события

        m_pWindowTimerImplForOnTimer = std::make_shared<WindowTimerImpl>(getHwnd(), 0, 0, false);
        m_pIWindowTimerForOnTimer    = std::static_pointer_cast<IWindowTimer>(m_pWindowTimerImplForOnTimer);

    // mutable std::shared_ptr<WindowTimerImpl>  m_pWindowTimerImplForOnTimer;
    // mutable std::shared_ptr<IWindowTimer>     m_pIWindowTimerForOnTimer;

        // auto pSharedImpl = std::make_shared<WindowTimerImpl>(getHwnd(), m_curTimerId++, timeoutMs, bRunning);
        // return WindowTimer(std::static_pointer_cast<IWindowTimer>(pSharedImpl));

        onWindowCreate();

        return 0;
    }

    void OnClose()
    {
        if (onWindowCloseQuery())
        {
            onWindowClose();
        }
    }

    void OnDestroy()
    {
        onWindowDestroy();
    }

    void OnCaptureChanged(const CWindow &wnd)
    {
        if (wnd.m_hWnd!=getHwnd())
        {
            //m_mouseCaptured = false;
            onWindowMouseCaptureChanged(false);
        }
    }

    void forceProcessWmTimerMessages()
    {
        MSG msg;

        while(PeekMessage(&msg, m_hWnd, WM_TIMER, WM_TIMER, PM_REMOVE)!=FALSE)
        {
            //this->SetMsgHandled(TRUE);
            OnTimer((UINT_PTR)msg.wParam);
        }
    }

    void OnTimer(UINT_PTR nIDEvent)
    {
        m_pWindowTimerImplForOnTimer->idTimerEvent = nIDEvent;
        onWindowTimerEvent(WindowTimer(m_pIWindowTimerForOnTimer));
    }

    void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
    {
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события

        marty_vk::KeyEventFlags keyEventFlags = marty_vk::KeyEventFlags::KeyDown;

        // https://learn.microsoft.com/en-us/windows/win32/inputdev/wm-keydown
        // https://learn.microsoft.com/en-us/windows/win32/inputdev/wm-keyup
        // Отнимаем 16 от номера бита, так как WTL сама извлекает repeat count и сдвигает флаги на 16 бит

        // 30 The previous key state. The value is always 1 for a WM_KEYUP message.
        // 30 The previous key state. The value is 1 if the key is down before the message is sent, or it is zero if the key is up (for WM_KEYDOWN).
        if (((nFlags)>>(30-16))&0x01)
        {
            keyEventFlags |= marty_vk::KeyEventFlags::PrevKeyStateDown;
        }

        // 24 Indicates whether the key is an extended key, such as the right-hand ALT and CTRL keys that appear on an enhanced 
        // 101- or 102-key keyboard. The value is 1 if it is an extended key; otherwise, it is 0.
        if (((nFlags)>>(24-16))&0x01)
        {
            keyEventFlags |= marty_vk::KeyEventFlags::ExtendedKey;
        }

        onWindowKeyEvent(keyEventFlags, (marty_vk::VkCode)nChar, (std::uint32_t)nRepCnt);
    }

// namespace marty_vk{
//  
// enum class KeyEventFlags : std::uint32_t
// {
//     Invalid            = (std::uint32_t)(-1),
//     Unknown            = (std::uint32_t)(-1),
//     None               = 0x0000,
//     NoFlags            = 0x0000,
//     Extended           = 0x0100,
//     ExtendedKey        = 0x0100,
//     AltDown            = 0x2000,
//     Repeat             = 0x4000,
//     Up                 = 0x8000,
//     PrevKeyStateDown   = 0x10000,
//     KeyDown            = 0x20000
//  
// }; // enum class KeyEventFlags : std::uint32_t

    void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
    {
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события

        marty_vk::KeyEventFlags keyEventFlags = marty_vk::KeyEventFlags::KeyUp; // Единственное отличие от WM_KEYDOWN

        // https://learn.microsoft.com/en-us/windows/win32/inputdev/wm-keydown
        // https://learn.microsoft.com/en-us/windows/win32/inputdev/wm-keyup
        // Отнимаем 16 от номера бита, так как WTL сама извлекает repeat count и сдвигает флаги на 16 бит

        // 30 The previous key state. The value is always 1 for a WM_KEYUP message.
        // 30 The previous key state. The value is 1 if the key is down before the message is sent, or it is zero if the key is up (for WM_KEYDOWN).
        if (((nFlags)>>(30-16))&0x01)
        {
            keyEventFlags |= marty_vk::KeyEventFlags::PrevKeyStateDown;
        }

        // 24 Indicates whether the key is an extended key, such as the right-hand ALT and CTRL keys that appear on an enhanced 
        // 101- or 102-key keyboard. The value is 1 if it is an extended key; otherwise, it is 0.
        if (((nFlags)>>(24-16))&0x01)
        {
            keyEventFlags |= marty_vk::KeyEventFlags::ExtendedKey;
        }

        onWindowKeyEvent(keyEventFlags, (marty_vk::VkCode)nChar, (std::uint32_t)nRepCnt);
    }

    BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint point)
    {
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события
        forceProcessWmTimerMessages();
        MouseButtonStateFlags mbStateFlags = (MouseButtonStateFlags)nFlags;
        onWindowMouseWheel(mbStateFlags, (int)zDelta, WindowPoint{(int)point.x,(int)point.y}); // ? TRUE : FALSE;
        return TRUE;
    }

    void OnMouseHover(WPARAM wParam /* MK_* */ , CPoint point)
    {
        m_bMouseTracking = false;
        OnMouseMoveEvents(MouseMoveEventType::hover, (MouseButtonStateFlags)wParam, WindowPoint{(int)point.x,(int)point.y});
    }

    void OnMouseLeave()
    {
        m_bMouseTracking = false;
        OnMouseMoveEvents(MouseMoveEventType::leave, MouseButtonStateFlags::none, WindowPoint{0,0});
    }

    // https://learn.microsoft.com/en-us/windows/win32/gdi/drawing-with-the-mouse
    void OnMouseMove(UINT nFlags, CPoint point)
    {
        if (!m_bMouseTracking)
        {
            trackMouseEvent();
        }

        OnMouseMoveEvents(MouseMoveEventType::move, (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y});
    }


    void OnLButtonDown(UINT nFlags, CPoint point)   { OnMouseButtonEvents( MouseButton::leftButton  , MouseButtonEvent::pressed    , (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnLButtonUp(UINT nFlags, CPoint point)     { OnMouseButtonEvents( MouseButton::leftButton  , MouseButtonEvent::released   , (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnLButtonDblClk(UINT nFlags, CPoint point) { OnMouseButtonEvents( MouseButton::leftButton  , MouseButtonEvent::doubleClick, (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnRButtonDown(UINT nFlags, CPoint point)   { OnMouseButtonEvents( MouseButton::rightButton , MouseButtonEvent::pressed    , (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnRButtonUp(UINT nFlags, CPoint point)     { OnMouseButtonEvents( MouseButton::rightButton , MouseButtonEvent::released   , (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnRButtonDblClk(UINT nFlags, CPoint point) { OnMouseButtonEvents( MouseButton::rightButton , MouseButtonEvent::doubleClick, (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnMButtonDown(UINT nFlags, CPoint point)   { OnMouseButtonEvents( MouseButton::middleButton, MouseButtonEvent::pressed    , (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnMButtonUp(UINT nFlags, CPoint point)     { OnMouseButtonEvents( MouseButton::middleButton, MouseButtonEvent::released   , (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }
    void OnMButtonDblClk(UINT nFlags, CPoint point) { OnMouseButtonEvents( MouseButton::middleButton, MouseButtonEvent::doubleClick, (MouseButtonStateFlags)nFlags, WindowPoint{(int)point.x,(int)point.y} ); }

    void OnXButtonDown(int fwButton, int dwKeys, CPoint point)
    {
        if (fwButton&XBUTTON1)
        {
            OnMouseButtonEvents( MouseButton::xButton1, MouseButtonEvent::pressed    , (MouseButtonStateFlags)dwKeys, WindowPoint{(int)point.x,(int)point.y} );
        }
        if (fwButton&XBUTTON2)
        {
            OnMouseButtonEvents( MouseButton::xButton2, MouseButtonEvent::pressed    , (MouseButtonStateFlags)dwKeys, WindowPoint{(int)point.x,(int)point.y} );
        }
    }

    void OnXButtonUp(int fwButton, int dwKeys, CPoint point)
    {
        if (fwButton&XBUTTON1)
        {
            OnMouseButtonEvents( MouseButton::xButton1, MouseButtonEvent::released   , (MouseButtonStateFlags)dwKeys, WindowPoint{(int)point.x,(int)point.y} );
        }
        if (fwButton&XBUTTON2)
        {
            OnMouseButtonEvents( MouseButton::xButton2, MouseButtonEvent::released   , (MouseButtonStateFlags)dwKeys, WindowPoint{(int)point.x,(int)point.y} );
        }
    }

    void OnXButtonDblClk(int fwButton, int dwKeys, CPoint point)
    {
        if (fwButton&XBUTTON1)
        {
            OnMouseButtonEvents( MouseButton::xButton1, MouseButtonEvent::doubleClick, (MouseButtonStateFlags)dwKeys, WindowPoint{(int)point.x,(int)point.y} );
        }
        if (fwButton&XBUTTON2)
        {
            OnMouseButtonEvents( MouseButton::xButton2, MouseButtonEvent::doubleClick, (MouseButtonStateFlags)dwKeys, WindowPoint{(int)point.x,(int)point.y} );
        }
    }

    void OnMouseButtonEvents( MouseButton           mouseButton
                            , MouseButtonEvent      buttonEvent
                            , MouseButtonStateFlags mbStateFlags
                            , const WindowPoint &point
                            )
    {
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события
        forceProcessWmTimerMessages();
        onWindowMouseButtonEvents(mouseButton, buttonEvent, mbStateFlags, point);
    }

    void OnMouseMoveEvents( MouseMoveEventType    moveEventType
                          , MouseButtonStateFlags mbStateFlags
                          , const WindowPoint &point
                          )
    {
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события
        forceProcessWmTimerMessages();
        onWindowMouseMoveEvents(moveEventType, mbStateFlags, point);
    }

    //------------------------------
    // Дефолтные виртуальные обработчики событий
    //------------------------------

    virtual void onConfigureDrawContextOffsetScale(IDrawContext *pdc) const override
    {
        MARTY_ARG_USED(pdc);
    }

    // вызываем при создании окна, объект класса уже создан и проинициализирован
    virtual void onWindowCreate() override
    {
    }

    // вызываем при изменении размера окна !!!
    virtual void onWindowResize() override
    {
    }

    virtual void onWindowMouseButtonEvents(MouseButton mouseButton, MouseButtonEvent buttonEvent, MouseButtonStateFlags mbStateFlags, const WindowPoint &point) override
    {
        MARTY_ARG_USED(mouseButton);
        MARTY_ARG_USED(buttonEvent);
        MARTY_ARG_USED(mbStateFlags);
        MARTY_ARG_USED(point);
    }

    virtual void onWindowMouseMoveEvents(MouseMoveEventType moveEventType, MouseButtonStateFlags mbStateFlags, const WindowPoint &point) override
    {
        MARTY_ARG_USED(moveEventType);
        MARTY_ARG_USED(mbStateFlags);
        MARTY_ARG_USED(point);
    }

    virtual void onWindowMouseWheel(MouseButtonStateFlags mbStateFlags, int zDelta, const WindowPoint &point) override
    {
        MARTY_ARG_USED(mbStateFlags);
        MARTY_ARG_USED(zDelta);
        MARTY_ARG_USED(point);
    }

    virtual bool onWindowCloseQuery() override // возвращает true, если закрытие разрешено
    {
        return true;
    }

    virtual void onWindowClose() override
    {
        ::DestroyWindow(getHwnd());
    }

    virtual void onWindowDestroy() override
    {
        PostQuitMessage(0);
    }

    virtual void onWindowTimerEvent(const WindowTimer timer) override
    {
        MARTY_ARG_USED(timer);
    }

    virtual void onWindowKeyEvent(marty_vk::KeyEventFlags keyEventFlags, marty_vk::VkCode vkCode, std::uint32_t nRepCnt) override
    {
        MARTY_ARG_USED(keyEventFlags);
        MARTY_ARG_USED(vkCode);
        MARTY_ARG_USED(nRepCnt);
    }

    virtual void onWindowMouseCaptureChanged(bool bCaptured) override
    {
        MARTY_ARG_USED(bCaptured);
    }


    //------------------------------
    // Виртуальные методы
    //------------------------------

    virtual taborder_t getAutoTabOrderIncrement() const override
    {
        return tabOrderDefAutoIncrement ? tabOrderDefAutoIncrement : 1;
    }


    

public:

    virtual taborder_t getAutoTabOrder() const override
    {
        if (m_autoTabOrderCounter==0)
        {
            m_autoTabOrderCounter = getAutoTabOrderIncrement();
            return m_autoTabOrderCounter;
        }

        m_autoTabOrderCounter += getAutoTabOrderIncrement();
        return m_autoTabOrderCounter;
    }

    virtual WindowTimer createTimer(timeout_t timeoutMs, bool bRunning = true) const override
    {
        // auto pSharedImpl = std::make_shared<WindowTimerImpl>(WindowTimerImpl::create(getHwnd(), m_curTimerId++, timeoutMs, bRunning)); // Not working
        auto pSharedImpl = std::make_shared<WindowTimerImpl>(getHwnd(), m_curTimerId++, timeoutMs, bRunning);
        return WindowTimer(std::static_pointer_cast<IWindowTimer>(pSharedImpl));
    }

    virtual TokenDictionary getTokenDictionary() const override
    {
        return TokenDictionary(m_pTokenDictionary);
    }

    virtual TokenDictionary setTokenDictionary(TokenDictionary dict) override
    {
        return TokenDictionary(std::exchange(m_pTokenDictionary, dict.getPimpl()));
    }

    //! Возвращает токен по строке, при необходимости добавляя
    virtual ETokenType getTokenForString(const String &name) const override
    {
        if (!m_pTokenDictionary)
        {
            throw std::runtime_error("HostWindow::getTokenForString: TokenDictionary not set");
        }

        return m_pTokenDictionary->getTokenForString(name);
    }

    //! Возвращает строку по токену, или пустую строку, если токен не найден
    virtual String getStringForToken(ETokenType tk) const override
    {
        if (!m_pTokenDictionary)
        {
            throw std::runtime_error("HostWindow::getStringForToken: TokenDictionary not set");
        }

        return m_pTokenDictionary->getStringForToken(tk);
    }

    virtual Cursor createStockCursor(EStockCursor cursorKind) const override
    {
        auto &cursorsHolder = getCursorHandlesHolder();
        auto pSharedImpl = std::make_shared<CursorImpl>(cursorKind, &cursorsHolder);
        return Cursor(std::static_pointer_cast<ICursor>(pSharedImpl));
    }

    virtual Cursor setCursor(Cursor cursor) override
    {
        if (!cursor.isValid())
        {
            return setCursor(EStockCursor::normal);
        }

        auto pCursorImpl = cursor.getCheckedCastedRawPtr<CursorImpl>("HostWindow::setCursor");

        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursor
        HCURSOR hPrevCursor = ::SetCursor(pCursorImpl->hCursor);

        auto &cursorsHolder = getCursorHandlesHolder();
        auto pSharedImpl = std::make_shared<CursorImpl>(hPrevCursor, &cursorsHolder);
        return Cursor(std::static_pointer_cast<ICursor>(pSharedImpl));
    }

    virtual Cursor setCursor(EStockCursor cursorKind) override
    {
        return setCursor(createStockCursor(cursorKind));
    }

    virtual bool showCursor(bool bShow) override
    {
        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-showcursor
        int showCounter = ::ShowCursor(bShow?TRUE:FALSE);
        return showCounter>=0;
    }

protected:

    static
    POINT p2p(WindowPoint p)
    {
        POINT pntRes;
        pntRes.x = (LONG)p.x;
        pntRes.y = (LONG)p.y;
        return pntRes;
    }

    static
    WindowPoint p2p(POINT p)
    {
        WindowPoint pntRes;
        pntRes.x = (int)p.x;
        pntRes.y = (int)p.y;
        return pntRes;
    }

    WindowPoint screenToWindowClientAreaPos(WindowPoint pos) const
    {
        POINT p = p2p(pos);

        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-clienttoscreen
        auto bRes = ::ScreenToClient(getHwnd(), &p);
        if (!bRes)
        {
            throw std::runtime_error("HostWindow::screenToWindowClientAreaPos: ScreenToClient failed");
        }

        return p2p(p);
    }

    WindowPoint windowClientAreaToScreenPos(WindowPoint pos) const
    {
        POINT p = p2p(pos);

        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-screentoclient
        auto bRes = ::ClientToScreen(getHwnd(), &p);
        if (!bRes)
        {
            throw std::runtime_error("HostWindow::windowClientAreaToScreenPos: ScreenToClient failed");
        }

        return p2p(p);
    }


public:

    // In window client area coords
    virtual WindowPoint getWindowCursorPos() const override
    {
        POINT pos{0,0};
        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getcursorpos
        if (!::GetCursorPos(&pos))
        {
            throw std::runtime_error("HostWindow::getWindowCursorPos: GetCursorPos failed");
        }

        return screenToWindowClientAreaPos(p2p(pos));
    }

    virtual bool  setWindowCursorPos(WindowPoint pos) const override
    {
        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcursorpos
        auto screenPos = p2p(windowClientAreaToScreenPos(pos));
        return ::SetCursorPos(screenPos.x,screenPos.y) ? true : false;
    }

    // window client area coords
    virtual WindowSize getWindowClientSize() const override
    {
        RECT r{0,0,0,0}; // https://learn.microsoft.com/en-us/windows/win32/api/windef/ns-windef-rect
        if (!::GetClientRect(getHwnd(), &r))
        {
            throw std::runtime_error("HostWindow::getClientSize: GetCursorPos failed");
        }

        WindowSize szRes;
        szRes.width  = (int)(r.right-r.left);
        szRes.height = (int)(r.bottom-r.top);

        return szRes;
    }

    virtual bool setWindowMouseCapture() override // return mouse previously captured or not
    {
        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setcapture
        HWND hwndPrevCapture = ::SetCapture(getHwnd());
        //m_mouseCaptured = true;
        onWindowMouseCaptureChanged(true);
        return hwndPrevCapture!=0;
    }

    virtual bool clrWindowMouseCapture() override
    {
        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-releasecapture
        //m_mouseCaptured = false;
        onWindowMouseCaptureChanged(false);
        return ::ReleaseCapture() ? true : false;
    }

    virtual bool isMouseCaptured() const override // any window
    {
        HWND hwndCapture = ::GetCapture();
        return hwndCapture!=0;
    }

    virtual bool isWindowMouseCaptured() const override // this window
    {
        HWND hwndCapture = ::GetCapture();
        if (hwndCapture==0)
        {
            return false; // not captured at all
        }
    
        return hwndCapture==getHwnd();
    }

    virtual WindowSize getDialogBaseUnits() const override
    {
         long dbu = ::GetDialogBaseUnits();
      
         // The low-order word of the return value contains the horizontal dialog box base unit,
         // and the high-order word contains the vertical dialog box base unit.
         int cx = (int)LOWORD(dbu);
         int cy = (int)HIWORD(dbu);

         return WindowSize{cx,cy};
    }

    virtual WindowSize mapDbuSizeToPixelSize(WindowSize size) const override
    {
         WindowSize dbu = getDialogBaseUnits();
         auto pixelX = ::MulDiv(size.width , dbu.width , 4);
         auto pixelY = ::MulDiv(size.height, dbu.height, 8);

         return WindowSize{pixelX,pixelY};
    
    }



    // virtual marty_draw_context::DrawSize getDialigBaseUnits() override
    // {
    //     long dbu = ::GetDialogBaseUnits();
    //  
    //     // The low-order word of the return value contains the horizontal dialog box base unit,
    //     // and the high-order word contains the vertical dialog box base unit.
    //     unsigned cx = LOWORD(dbu);
    //     unsigned cy = HIWORD(dbu);
    //  
    //     return mapRawToLogicSize(DrawCoord{cx,cy});
    // }


}; // class HostWindowImpl



#include "../../warnings/pop.h"



} // namespace mxPiglets


