#pragma once

#include "marty_draw_context/i_draw_context.h"
#include "marty_draw_context/i_image_list.h"

#include "non_copyable_object.h"
#include "cursor.h"
#include "window_timer.h"
//
#include "marty_vk/VkCode.h"



namespace mxPiglets {


using namespace marty_draw_context;




#include "warnings/push_disable_copy_ctor_implicitly_deleted.h"



struct IHostWindow : public NonCopyableObject
{

protected:

    // Обработчики событий, которые вызываются изнутри

    virtual void onConfigureDrawContextOffsetScale(IDrawContext *pdc) const = 0;
    // getDrawingContext() - возвращает не указатель, а экземпляр DC для рисования не в OnPaint. Это не в базе, а в реализации

    virtual void onWindowCreate() = 0; // вызываем при создании окна, объект класса уже создан и проинициализирован
    virtual void onWindowResize() = 0; // вызываем при изменении размера окна !!!

    virtual bool onWindowCloseQuery() = 0; // возвращает true, если закрытие разрешено
    virtual void onWindowClose() = 0;
    virtual void onWindowDestroy() = 0;

    virtual void onWindowMouseCaptureChanged(bool bCaptured) = 0;

    virtual void onWindowTimerEvent(const WindowTimer timer) = 0;

    virtual void onWindowKeyEvent(marty_vk::KeyEventFlags keyEventFlags, marty_vk::VkCode vkCode, std::uint32_t nRepCnt) = 0;

    virtual void onWindowMouseButtonEvents( MouseButton mouseButton, MouseButtonEvent buttonEvent, MouseButtonStateFlags mbStateFlags, const WindowPoint &point) = 0;
    virtual void onWindowMouseMoveEvents( MouseMoveEventType moveEventType, MouseButtonStateFlags mbStateFlags, const WindowPoint &point) = 0;
    virtual void onWindowMouseWheel(MouseButtonStateFlags mbStateFlags, int zDelta, const WindowPoint &point) = 0;

    virtual taborder_t getAutoTabOrderIncrement() const = 0;


public:

    virtual WindowTimer createTimer(timeout_t timeoutMs, bool bRunning = true) const = 0;

    virtual taborder_t getAutoTabOrder() const = 0;

    virtual Cursor createStockCursor(EStockCursor cursorKind) const = 0;
    virtual Cursor setCursor(Cursor cursor) = 0;
    virtual Cursor setCursor(EStockCursor cursorKind) = 0;
    virtual bool   showCursor(bool bShow) = 0;

    // In window client area coords
    virtual WindowPoint getWindowCursorPos() const = 0;
    virtual bool  setWindowCursorPos(WindowPoint pos) const = 0;

    // window client area coords
    virtual WindowSize getWindowClientSize() const = 0;

    virtual bool setWindowMouseCapture() = 0; // return mouse previously captured or not
    virtual bool clrWindowMouseCapture() = 0;
    virtual bool isMouseCaptured() const = 0; // any window
    virtual bool isWindowMouseCaptured() const = 0; // this window

    virtual WindowSize getDialogBaseUnits() const = 0;
    virtual WindowSize mapDbuSizeToPixelSize(WindowSize size) const = 0;



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


    //virtual bool stopTimer(WindowTimer t) = 0;
    //virtual bool removeTimer(WindowTimer t) = 0;

    // virtual void setWindowMouseCapture(bool bSet) = 0;
    // virtual void clrWindowMouseCapture() = 0;
    // virtual bool getWindowMouseCapture() = 0;
    //  
    // virtual Cursor createStockCursor(EStockCursor sc) = 0;
    // virtual Cursor setCursor(Cursor c) = 0;
    // virtual bool setShowCursor(bool bShow) = 0;
    // virtual bool getShowCursor() = 0;
    // virtual int  getShowCursorCounter() = 0;


    // Coords getClietntSize()
    // void setClietntSize(Coords)


    // virtual void setVisible(bool visible) - ShowWindow
    // virtual void close()
    // virtual void setVerticalSyncEnabled(bool enabled)
    // virtual void setMouseCursorVisible(bool visible)

    // virtual void requestFocus() - Request the current window to be made the active foreground window. Подробнее...
    // virtual bool hasFocus () const - Check whether the window has the input focus. Подробнее...
    
    
    // virtual bool setShowCaret(bool bShow)
    // virtual bool getShowCaret(bool bShow)
    
    
    //virtual Coords mapMousePosToDrawingContextCoords(Coords mousePos) - 
    //virtual Coords mapDrawingContextCoordsToMousePos(Coords coords) - 


 






//VirtualKeyStates HostWindow::getCurrentKeyState	(	VirtualKey 	virtualKey	)	




}; // struct IHostWindow


#include "warnings/pop.h"




} // namespace mxPiglets




