#pragma once

#include "marty_draw_context/i_draw_context.h"
#include "marty_draw_context/i_image_list.h"

#include "non_copyable_object.h"
#include "cursor.h"
#include "window_timer.h"
#include "i_token_dictionary.h"
#include "token_dictionary.h"
#include "i_control_painter_factory.h"
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

    virtual void onWindowPaintEvent() //!< Вызывается в обработчике WM_PAINT (DoPaint WTL)
    {
        auto pScreenCanvas = getCanvasForPaintEvent();
        auto pCanvas = createOffscreenCanvas(pScreenCanvas);
        prepareCanvasScaleOffset  (pCanvas);

        drawSceneBackground       (pCanvas);
        cacheSceneBackground      (pCanvas);

        drawSceneAnimation        (pCanvas);
        drawSceneControls         (pCanvas);
        drawSceneControlsAnimation(pCanvas);
        drawDragItems             (pCanvas);
        drawMouseState            (pCanvas);

        copyOffsceenToScreenCanvas(pCanvas, pScreenCanvas); // from -> to
    }

    virtual taborder_t getAutoTabOrderIncrement() const = 0;


public:

    virtual std::shared_ptr<ICanvas> getCanvas() const = 0; //!< Возвращает канвас для рисования вне onWindowPaintEvent
    virtual std::shared_ptr<ICanvas> getCanvasForPaintEvent() const = 0; //!< Возвращает канвас для рисования в обработчике onWindowPaintEvent
    virtual void prepareCanvasScaleOffset(std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); }; //!< Настройка канваса, переопределяет пользователь

    // Поддержка дабл буферинга
    //! Создаёт "теневой" канвас для оффскрин отрисовки, чтобы отображение не сильно мерцало. По умолчанию - ничего не делает
    virtual std::shared_ptr<ICanvas> createOffscreenCanvas(std::shared_ptr<ICanvas> pCanvas) const { return pCanvas; }
    //! Копирует содержимое теневого канвас в экранный. По умолчанию - ничего не делает. Повторный вызов данного метода с теми же объектами недопустим - содержимое pCanvasCopyFrom разрушается.
    virtual void                     copyOffsceenToScreenCanvas(std::shared_ptr<ICanvas> pCanvasCopyFrom, std::shared_ptr<ICanvas> pCanvasCopyTo) const { MARTY_ARG_USED(pCanvasCopyFrom); MARTY_ARG_USED(pCanvasCopyTo); }

    virtual bool selectCachedBackground    (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); return false; } //!< Устанавливает в канвасе кешированный background, возвращает false, если background не был установлен, и требуется перерисовка
    virtual void cacheSceneBackground      (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Кеширование background'а сцены
    virtual void drawSceneBackground       (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Отрисовка background'а сцены
    virtual void drawSceneAnimation        (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Отрисовка анимаций сцены
    virtual void drawSceneControls         (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Отрисовка контролов
    virtual void drawSceneControlsAnimation(std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Отрисовка анимации контролов
    virtual void drawDragItems             (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Отрисовка перетаскиваний
    virtual void drawMouseState            (std::shared_ptr<ICanvas> pCanvas) const { MARTY_ARG_USED(pCanvas); } //!< Отрисовка выделений мышкой

    virtual void drawScene() //!< Отрисовка сцены по 
    {
        auto pScreenCanvas = getCanvas();
        auto pCanvas = createOffscreenCanvas(pScreenCanvas);
        prepareCanvasScaleOffset  (pCanvas);

        if (!selectCachedBackground(pCanvas))
        {
            drawSceneBackground(pCanvas);
            cacheSceneBackground(pCanvas);
        }

        drawSceneAnimation        (pCanvas);
        drawSceneControls         (pCanvas);
        drawSceneControlsAnimation(pCanvas);
        drawDragItems             (pCanvas);
        drawMouseState            (pCanvas);

        copyOffsceenToScreenCanvas(pCanvas, pScreenCanvas); // from -> to
    }

    virtual WindowTimer createTimer(timeout_t timeoutMs, bool bRunning = true) const = 0;

    virtual taborder_t getAutoTabOrder() const = 0;

    virtual TokenDictionary getTokenDictionary() const = 0;
    virtual TokenDictionary setTokenDictionary(TokenDictionary dict) = 0;

    //virtual addControl

    //! Возвращает токен по строке, при необходимости добавляя
    virtual ETokenType getTokenForString(const String &name) const = 0;
    //! Возвращает строку по токену, или пустую строку, если токен не найден
    virtual String getStringForToken(ETokenType tk) const = 0;


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




