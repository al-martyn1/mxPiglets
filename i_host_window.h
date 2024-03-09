#pragma once

#include "marty_draw_context/i_draw_context.h"
#include "marty_draw_context/i_image_list.h"

//
#include "types.h"
//
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


    virtual void onConfigureDrawContextOffsetScale(IDrawContext *pdc) const = 0;
    // getDrawingContext() - возвращает не указатель, а экземпляр DC для рисования не в OnPaint. Это не в базе, а в реализации

    virtual void onWindowCreate() = 0; // вызываем при создании окна, объект класса уже создан и проинициализирован
    virtual void onWindowResize() = 0; // вызываем при изменении размера окна !!!


    virtual bool onWindowCloseQuery() = 0; // возвращает true, если закрытие разрешено
    virtual void onWindowClose() = 0;
    virtual void onWindowDestroy() = 0;

    virtual void onTimerEvent(const WindowTimer timer) = 0;

    virtual void onKeyEvent(marty_vk::KeyEventFlags keyEventFlags, marty_vk::VkCode vkCode, std::uint32_t nRepCnt) = 0;

    virtual WindowTimer createTimer(timeout_t timeoutMs, bool bRunning = true) const = 0;

    virtual Cursor createStockCursor(EStockCursor cursorKind) const = 0;
    virtual Cursor setCursor(Cursor cursor) = 0;
    virtual Cursor setCursor(EStockCursor cursorKind) = 0;
    virtual bool showCursor(bool bShow) = 0;


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




