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
//
#include "window_timer_impl.h"
#include "cursor_handles_holder.h"
#include "cursor_impl.h"


namespace mxPiglets {


#include "../../warnings/push_disable_copy_ctor_implicitly_deleted.h"



template<typename TParent>
class HostWindowImpl : public TParent
                     , public IHostWindow
{

    mutable UINT_PTR    curTimerId  = 1; // Переделать на атомики

    // Чтобы постоянно думми не создавать, создадим заранее всё, что нужно, в OnCreate, а в OnTimer просто будем менять идентификатор таймера
    mutable std::shared_ptr<WindowTimerImpl>  pWindowTimerImplForOnTimer;
    mutable std::shared_ptr<IWindowTimer>     pIWindowTimerForOnTimer;
    


public:

    HostWindowImpl()
    {
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

    void setMsgHandled(BOOL bHandled = TRUE)
    {
        static_cast<TParent*>(this)->SetMsgHandled(bHandled);
    }

    void setMsgNotHandled()
    {
        setMsgHandled(FALSE);
    }

    // Обработка оконных сообщений

    BEGIN_MSG_MAP(CBitmapView)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_CLOSE(OnClose)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_TIMER(OnTimer)
        MSG_WM_KEYDOWN(OnKeyDown)
        MSG_WM_KEYUP(OnKeyUp)

        // //MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
        // MSG_WM_SIZE(OnSize)
        // MSG_WM_SIZING(OnSizing)
        //  
        // MSG_WM_CAPTURECHANGED(OnCaptureChanged)
        //  
        // MSG_WM_MOUSEHOVER(OnMouseHover)
        // MSG_WM_MOUSELEAVE(OnMouseLeave)
        //  
        // MSG_WM_MOUSEWHEEL(OnMouseWheel)
        //  
        // MSG_WM_MOUSEMOVE(OnMouseMove)
        //  
        // MSG_WM_LBUTTONDOWN(OnLButtonDown)
        // MSG_WM_LBUTTONUP(OnLButtonUp)
        // MSG_WM_LBUTTONDBLCLK(OnLButtonDblClk)
        //  
        // MSG_WM_RBUTTONDOWN(OnRButtonDown)
        // MSG_WM_RBUTTONUP(OnRButtonUp)
        // MSG_WM_RBUTTONDBLCLK(OnRButtonDblClk)
        //  
        // MSG_WM_MBUTTONDOWN(OnMButtonDown)
        // MSG_WM_MBUTTONUP(OnMButtonUp)
        // MSG_WM_MBUTTONDBLCLK(OnMButtonDblClk)
        //  
        // MSG_WM_XBUTTONDOWN(OnXButtonDown)
        // MSG_WM_XBUTTONUP(OnXButtonUp)
        // MSG_WM_XBUTTONDBLCLK(OnXButtonDblClk)

        CHAIN_MSG_MAP(TParent);

    END_MSG_MAP()

    int OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        MARTY_ARG_USED(lpCreateStruct);
        setMsgHandled(FALSE); // Пусть продолжает обработку, мало ли, кто-то ещё захочет обработать эти события

        pWindowTimerImplForOnTimer = std::make_shared<WindowTimerImpl>(getHwnd(), 0, 0, false);
        pIWindowTimerForOnTimer    = std::static_pointer_cast<IWindowTimer>(pWindowTimerImplForOnTimer);

    // mutable std::shared_ptr<WindowTimerImpl>  pWindowTimerImplForOnTimer;
    // mutable std::shared_ptr<IWindowTimer>     pIWindowTimerForOnTimer;

        // auto pSharedImpl = std::make_shared<WindowTimerImpl>(getHwnd(), curTimerId++, timeoutMs, bRunning);
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
        pWindowTimerImplForOnTimer->idTimerEvent = nIDEvent;
        onTimerEvent(WindowTimer(pIWindowTimerForOnTimer));
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

        onKeyEvent(keyEventFlags, (marty_vk::VkCode)nChar, (std::uint32_t)nRepCnt);
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

        onKeyEvent(keyEventFlags, (marty_vk::VkCode)nChar, (std::uint32_t)nRepCnt);
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

    //------------------------------
    // Виртуальные методы
    //------------------------------

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

    virtual void onTimerEvent(const WindowTimer timer) override
    {
        MARTY_ARG_USED(timer);
    }

    virtual void onKeyEvent(marty_vk::KeyEventFlags keyEventFlags, marty_vk::VkCode vkCode, std::uint32_t nRepCnt) override
    {
        MARTY_ARG_USED(keyEventFlags);
        MARTY_ARG_USED(vkCode);
        MARTY_ARG_USED(nRepCnt);
    }


    virtual WindowTimer createTimer(timeout_t timeoutMs, bool bRunning = true) const override
    {
        // auto pSharedImpl = std::make_shared<WindowTimerImpl>(WindowTimerImpl::create(getHwnd(), curTimerId++, timeoutMs, bRunning)); // Not working
        auto pSharedImpl = std::make_shared<WindowTimerImpl>(getHwnd(), curTimerId++, timeoutMs, bRunning);
        return WindowTimer(std::static_pointer_cast<IWindowTimer>(pSharedImpl));
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


    //virtual bool stopTimer(WindowTimer t) override
    //virtual bool removeTimer(WindowTimer t) override


}; // class HostWindowImpl



#include "../../warnings/pop.h"



} // namespace mxPiglets


