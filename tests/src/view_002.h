// View.h : interface of the CBitmapView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __VIEW_H__
#define __VIEW_H__

#include "umba/umba.h"
#include "umba/simple_formatter.h"
#include "umba/time_service.h"

//
#include "marty_dc_impl_win32/gdi_draw_context.h"
#include "marty_dc_impl_win32/gdiplus_draw_context.h"
//
#include <array>
//
#include "mxPiglets/impl/win32/host_window_impl.h"
#include "mxPiglets/impl/win32/elapsed_timer_impl.h"


#define CRACK_ON_KEY_UPDOWN_FLAGS_GET_REPETITION_STATE_FLAG(nFlags) (((nFlags)>>(30-16))&0x01)
#define CRACK_ON_KEY_UPDOWN_FLAGS_GET_PREV_DOWN_STATE_FLAG(nFlags)  CRACK_ON_KEY_UPDOWN_FLAGS_GET_REPETITION_STATE_FLAG((nFlags))



typedef marty_draw_context::DrawCoord                         DrawCoord                 ;
typedef marty_draw_context::DrawSize                          DrawSize                  ;
typedef marty_draw_context::DrawScale                         DrawScale                 ;
typedef marty_draw_context::GradientParams                    GradientParams            ;
typedef marty_draw_context::ColorRef                          ColorRef                  ;
typedef marty_draw_context::GradientType                      GradientType              ;
typedef marty_draw_context::GradientRoundRectFillFlags        GradientRoundRectFillFlags;
typedef marty_draw_context::SmoothingMode                     SmoothingMode             ;
typedef marty_draw_context::BkMode                            BkMode                    ;
typedef marty_draw_context::LineEndcapStyle                   LineEndcapStyle           ;
typedef marty_draw_context::LineJoinStyle                     LineJoinStyle             ;
typedef marty_draw_context::ColorRef                          ColorRef                  ;
typedef marty_draw_context::PenParamsWithColor                PenParamsWithColor        ;
typedef marty_draw_context::IDrawContext                      IDrawContext              ;
typedef marty_draw_context::HorAlign                          HorAlign                  ;
typedef marty_draw_context::FontStyleFlags                    FontStyleFlags            ;
typedef marty_draw_context::FontParamsA                       FontParamsA               ;
typedef marty_draw_context::FontWeight                        FontWeight                ;

typedef marty_draw_context::GdiDrawContext                    GdiDrawContext    ;
typedef marty_draw_context::GdiPlusDrawContext                GdiPlusDrawContext;



class CBitmapView : public mxPiglets::HostWindowImpl< CScrollWindowImpl<CBitmapView> >
// public CScrollWindowImpl<CBitmapView>
{

    typedef mxPiglets::HostWindowImpl< CScrollWindowImpl<CBitmapView> >   HostWindowImplBase;

    mxPiglets::WindowTimer timer1;
    mxPiglets::WindowTimer timer2;
    mxPiglets::WindowTimer timerCursorChange;

    mxPiglets::EStockCursor  curStockCursor = mxPiglets::EStockCursor::normal;
    mxPiglets::Cursor        defaultCursor;

    mxPiglets::ElapsedTimer  elapsedTimer;

public:
    DECLARE_WND_CLASS_EX(NULL, 0, -1)

    //CBitmap m_bmp;
    //SIZE m_size;

    CBitmapView() : elapsedTimer(mxPiglets::createElapsedTimer())
    {
    }

    CBitmapView(const CBitmapView&) : HostWindowImplBase() // = delete;
    {
    
    }

    virtual void onWindowCreate() override
    {
        using umba::lout;
        using namespace umba::omanip;


        timer1 = createTimer(100);
        timer2 = createTimer(200);
        timerCursorChange = createTimer(1000);

        if (timer1==timer1)
        {
            lout << "timer1==timer1\n";
        }
        else
        {
            lout << "timer1!=timer1\n";
        }

        if (timer1==timer2)
        {
            lout << "timer1==timer2\n";
        }
        else
        {
            lout << "timer1!=timer2\n";
        }
        
    }

    virtual void onWindowClose() override
    {
        setCursor(defaultCursor);
        HostWindowImplBase::onWindowClose();
    }
    

    virtual void onTimerEvent(const mxPiglets::WindowTimer timer) override
    {
        if (timer==timerCursorChange)
        {
            const std::uint32_t end    = (std::uint32_t)mxPiglets::EStockCursor::end;
            std::uint32_t curCursorU32 = (std::uint32_t)curStockCursor;
            ++curCursorU32;
            if (curCursorU32>=end)
            {
                curStockCursor = mxPiglets::EStockCursor::normal;
            }
            else
            {
                curStockCursor = (mxPiglets::EStockCursor)curCursorU32;
            }

            auto prevCursor = setCursor(createStockCursor(curStockCursor));
            if (!defaultCursor.isValid())
            {
                defaultCursor = prevCursor;
            }

            //mxPiglets::EStockCursor  curStockCursor = mxPiglets::EStockCursor::normal;
        }
    }


    BOOL PreTranslateMessage(MSG* pMsg)
    {
        MARTY_ARG_USED(pMsg);
        return FALSE;
    }

    void SetBitmap(HBITMAP hBitmap)
    {
        MARTY_ARG_USED(hBitmap);
    }

    BEGIN_MSG_MAP(CBitmapView)
        MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
        //CHAIN_MSG_MAP(CScrollWindowImpl<CBitmapView>);
        CHAIN_MSG_MAP(HostWindowImplBase);
    END_MSG_MAP()

    void toggleFullScreen()
    {}

    LRESULT OnEraseBackground(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
    {
        RECT rect;
        GetClientRect(&rect);
        int x = 0;
        int y = 0;
        /*
        if(!m_bmp.IsNull())
        {
            x = m_size.cx + 1;
            y = m_size.cy + 1;
        }
        */
        CDCHandle dc = (HDC)wParam;
        if(rect.right > m_sizeAll.cx)
        {
            RECT rectRight = rect;
            rectRight.left = x;
            rectRight.bottom = y;
            dc.FillRect(&rectRight, COLOR_WINDOW);
        }
        if(rect.bottom > m_sizeAll.cy)
        {
            RECT rectBottom = rect;
            rectBottom.top = y;
            dc.FillRect(&rectBottom, COLOR_WINDOW);
        }
        /*
        if(!m_bmp.IsNull())
        {
            dc.MoveTo(m_size.cx, 0);
            dc.LineTo(m_size.cx, m_size.cy);
            dc.LineTo(0, m_size.cy);
        }
        */
        return 0;
    }

    void DoPaint(CDCHandle dc)
    {
        using umba::lout;
        using namespace umba::omanip;

        #ifdef TEST_DC_USE_GDIPLUS
        GdiPlusDrawContext idc = dc;
        #else
        GdiDrawContext     idc = dc;
        #endif

        //auto scale = 1.4;
        //auto scale = 8;
        auto scale = 6;
        //idc.setScale(DrawScale(30,30));
        //idc.setScale(DrawScale(10,10));

        IDrawContext *pDc = &idc;

        pDc->setOffset(DrawScale(1.4,1.4));
        pDc->setScale(DrawScale(scale,scale));
        pDc->setPenScale(scale);

        auto startTick = umba::time_service::getCurTimeMs();

        DoPaintImpl(pDc);

        auto endTick = umba::time_service::getCurTimeMs();

        lout << "OnPaint times: " << (endTick-startTick) << "\n";

    }

    void DoPaintImpl( marty_draw_context::IDrawContext *pDc )
    {
        using umba::lout;
        using namespace umba::omanip;

        MARTY_ARG_USED(pDc);

    }

};

#endif // __VIEW_H__
