#pragma once

#include "i_object.h"
//
#include "i_host_window.h"
//
#include "i_control_painter.h"

namespace mxPiglets {

                    

struct IControl : public NonCopyableObject
                , public IComparable
{

    MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DELETE(IControl);

    //------------------------------
    // HostWindow
    // 1) Нет нужды оборачивать IHostWindow* в смарт поинтер
    // 2) Наша система контролов никак не управляет временем жизни хост окна, обычно все контролы 
    //    имеют время жизни меньше, чем хост окно.
    //    Хост окно может быть создано в хост программе на стеке, или глобально, или где угодно.
    //    Копирование без разрушения голенького указателя, не управляющего временем жизни, вполне 
    //    безопасно, даже если мы не знаем где и как он будет использоваться.
    // 3) Не обязательно прокидывать эти методы в скрипты, а если прокинули,
    //    и кто-то сохранил и хранит/использует отдельно от обработчиков событий и прочего временного,
    //    то он сам себе ССЗБ


    // Флаги, единожды установленные, после этого не могут быть сброшены
    static const s_controlStyleNonResetableFlags = ControlStyleFlags::controlContainer  // Acts as control container, not a single (possible compaund) control
                                                 | ControlStyleFlags::groupStart        // Starts the control group
                                                 | ControlStyleFlags::tabStop           // Allow the control to be in tab navigation list
                                                 | ControlStyleFlags::focusLess         // Control can't own the input focus
                                                 ;


    virtual IHostWindow*       getHostWindow() = 0;
    virtual const IHostWindow* getHostWindow() const = 0;
    virtual IHostWindow*       setHostWindow(IHostWindow* phw) = 0; //!< Возвращает старый указатель IHostWindow*

    //! Возвращает токен по строке, при необходимости добавляя
    virtual ETokenType getTokenForString(const String &name) const = 0;
    //! Возвращает строку по токену, или пустую строку, если токен не найден
    virtual String getStringForToken(ETokenType tk) const = 0;


    //------------------------------
    // TabOrder
    //! Возвращает целочисленный идентификатор таб-ордера
    virtual taborder_t getControlTabOrder() const = 0;
    //! Задаёт идентификатор таб-ордера. Следует вызывать только до добавления контрола в контейнер. В противном случае результаты не определены
    virtual taborder_t setControlTabOrder(taborder_t newTabOrder) = 0;


    //------------------------------
    // DialogResult
    //! Закрывает ли интеракция с данным контролом диалог. Стили контрола должны содержать одно из значений ControlStyleFlags::DialogResult*, кроме DialogResultNone, и код результата не должен быть EDialogResult::invalid или EDialogResult::none
    virtual bool isControlCloseDialog() const = 0;
    //! Если на форме/в диалоге нажимается Enter, ищется первый контрол, который при вызове данной функции вернёт true
    virtual bool isControlCloseDialogDefaultOk() const = 0;
    //! Если на форме/в диалоге нажимается Escape, ищется первый контрол, который при вызове данной функции вернёт true
    virtual bool isControlCloseDialogDefaultCancel() const = 0;
    //! Возвращает код возврата модального диалога. Если данный контрол является закрывающим диалог (стили ControlStyleFlags::DialogResult*, кроме DialogResultNone), то при интеракции с контролом возвращается данный код
    virtual EDialogResult getControlDialogResult() const = 0;
    //! Устанавливает код возврата модального диалога.
    virtual void setControlDialogResult(EDialogResult dlgRes) = 0;


    //------------------------------
    // Текст контрола - заголовок/метка, или содержимое (редактора) - зависит от типа контрола
    virtual String getControlText() const = 0;    //!< Получение текста контрола. Способ использования текста зависит от типа контрола
    virtual void setControlText(String text) = 0; //!< Установка текста контрола. Способ использования текста зависит от типа контрола


    //------------------------------
    // Имя типа, стиля, состояния, id - для использования в отрисовщике, потом на этой базе можно будет сделать недо-CSS
    // При использовании токенов используется указатель на хост окно, через которое производится конвертация строк в идентификаторы.
    // Изачально указатель на хост окно может быть не установлен, и тогда при установке строкового свойства кеширование токена не производится.
    // Но при получении строкового свойства надо кидать исключение - значения свойств нужны в основном для отрисовки, тогда 
    // хост окно уже должно быть установлено


    //! Возвращает имя типа контрола - button/pushbutton/checkbox/radiobutton/listbox etc. Определяется конкретным типом контрола, снаружи не задать
    virtual String getControlTypeString() const = 0;
    //! Возвращает токен имени типа контрола. Определяется конкретным типом контрола, снаружи не задать. При этом строка типа контрола первична.
    virtual ETokenType getControlType() const = 0;


    //! Возвращает имя стиля контрола
    virtual String getControlStyleString() const = 0;
    //! Задаёт имя стиля контрола
    virtual void setControlStyleString(const String &styString) = 0;
    //! Возвращает токен имени стиля контрола. При этом строка стиля контрола первична.
    virtual ETokenType getControlStyle() const = 0;
    //! Задаёт стиль контрола используя токен. При этом строка стиля контрола первична.
    virtual void setControlStyle(ETokenType sty) = 0;


    //! Возвращает идентификатор контрола
    virtual String getControIdString() const = 0;
    //! Задаёт идентификатор контрола
    virtual void setControlIdString(const String &idString) = 0;
    //! Возвращает токен идентификатора контрола. При этом строка идентификатора контрола первична.
    virtual ETokenType getControId() const = 0;
    //! Задаёт идентификатор контрола используя токен. При этом строка идентификатора контрола первична.
    virtual void setControlId(ETokenType idString) = 0;


    //! Возвращает токен имени/названия состояния контрола. Определяется конкретным типом контрола, снаружи не задать.
    virtual ETokenType getControlState() const = 0;
    //! Возвращает имя/название состояния контрола - pushed/unpushed, checked/unchecked, selected/unselected, и тп. Определяется конкретным типом контрола, снаружи не задать.
    virtual String getControlStateString() const = 0;

    //! Устанавливает состояние контрола (например, начальное состояние) по токену. Все возможные токены состояний любых контролов есть у нас в словаре, но каждый контрол поддерживает только малую часть. Для разных контролов состояния с одним именем могут означать разное. При ошибке возвращает false (если состояние не известно, или его нельзя установить по другой причине). В тч для использования в дизайнере форм
    virtual bool setControlState(ETokenType tk) = 0;
    //! Устанавливает состояние контрола (например, начальное состояние) по строке. Все возможные токены состояний любых контролов есть у нас в словаре, но каждый контрол поддерживает только малую часть. Для разных контролов состояния с одним именем могут означать разное. При ошибке возвращает false (если состояние не известно, или его нельзя установить по другой причине). В тч для использования в дизайнере форм
    virtual bool setControlStateString(const String &stateString) = 0;

    //! Возвращает список допустимых состояний контрола (в тч для использования в дизайнере форм)
    virtual TokenString getControlStates() const = 0;
    //! Возвращает список допустимых состояний контрола (вектор строк, в тч для использования в дизайнере форм)
    virtual std::vector<String> getControlStateStrings() const = 0;


    //!< Возвращает список псевдо-классов контрола. Набор псевдо-классов фиксирован и токены для строк предопределены и первичны
    virtual TokenString getControlStylePseudoClasses() const = 0;
    //!< Возвращает список псевдо-классов контрола (вектор строк). Набор псевдо-классов фиксирован и токены для строк предопределены и первичны
    virtual std::vector<String> getControlStylePseudoClassStrings() const = 0;


    //------------------------------
    // Флаги стиля контрола

    // Флаги храним в одном слове - смысл разносить по отдельным bool переменым?
    // Зато можно получить/установить/изменить сразу пачкой по маске
    // Для удобства для каждого флага будут хелперы

    //! Флаги (на самом деле enum, внутри флагов) dialogResult* хранятся вместе с остальными флагами стиля контрола, но контрол может ситуативно по разному отвечать, перегрузив данную функцию. Не следует брать значение dialogResult* непосредственно из флагов контрола
    virtual ControlStyleFlags getControlStyleDialogResultFlags() const = 0;

    //! Флаги (на самом деле enum, внутри флагов) want* хранятся вместе с остальными флагами стиля контрола, но контрол может ситуативно по разному отвечать, перегрузив данную функцию. Не следует брать значение want* непосредственно из флагов контрола
    virtual ControlStyleFlags getControlStyleWantKeyFlags() const = 0;

    //! Установка всех флагов (assign). Возвращает старое значение флагов
    virtual ControlStyleFlags setControlStyleFlags(ControlStyleFlags flags) = 0;

    //! Получение всех флагов
    virtual ControlStyleFlags getControlStyleFlags() const = 0;

    //! Получение флагов по маске
    virtual ControlStyleFlags getControlStyleFlagsByMask(ControlStyleFlags mask) const = 0;

    //! Сначала очищаются resetFlags-флаги (and), потом устанавливаются setFlags-флаги (or). Возвращает старое значение флагов
    virtual ControlStyleFlags setResetControlStyleFlags(ControlStyleFlags setFlags, ControlStyleFlags resetFlags) = 0;


    //------------------------------
    // Обёртки для конкретных флагов

    virtual bool getControlStyleFlagTabStop() const = 0; //!< Получение значения флага ControlStyleFlags::tabStop
    virtual bool setControlStyleFlagTabStop(bool f) = 0; //!< Установка значения флага ControlStyleFlags::tabStop


    //------------------------------
    // Флаги состояния контрола, аналогично флагам стиля
    //! Установка всех флагов (assign). Возвращает старое значение флагов
    virtual ControlStateFlags setControlStateFlags(ControlStateFlags flags) = 0;

    //! Получение всех флагов
    virtual ControlStateFlags getControlStateFlags() const = 0;

    //! Получение флагов по маске
    virtual ControlStateFlags getControlStateFlagsByMask(ControlStateFlags mask) const = 0;

    //! Сначала очищаются resetFlags-флаги (and), потом устанавливаются setFlags-флаги (or). Возвращает старое значение флагов
    virtual ControlStateFlags setResetControlStateFlags(ControlStateFlags setFlags, ControlStateFlags resetFlags) = 0;


    //------------------------------
    // Обёртки для конкретных флагов

    virtual bool getControlStateFlagNeedRepaint() const = 0; //!< Получение значения флага ControlStateFlags::needRepaint
    virtual bool setControlStateFlagNeedRepaint(bool f) = 0; //!< Установка значения флага ControlStateFlags::needRepaint




    //------------------------------
    // Положение и координаты - относительно родителя

    virtual Point getPosition() const = 0;
    virtual Point setPosition(Point newPos) = 0;

    virtual Size  getSize() const = 0;
    virtual Size  setSize(Size newSize) = 0;

    virtual Rect  getBounds() const = 0;
    virtual Rect  setBounds(Rect r) = 0;

    virtual CoordValue getLeft() const = 0;
    virtual CoordValue setLeft(CoordValue v) = 0;

    virtual CoordValue getTop() const = 0;
    virtual CoordValue getTop(CoordValue v) = 0;

    virtual CoordValue getWidth() const = 0;
    virtual CoordValue setWidth(CoordValue v) = 0;

    virtual CoordValue getHeight() const = 0;
    virtual CoordValue getHeight(CoordValue v) = 0;

    virtual CoordValue getRight() const = 0;
    virtual CoordValue setRight(CoordValue v) = 0;

    virtual CoordValue getBottom() const = 0;
    virtual CoordValue getBottom(CoordValue v) = 0;
    


}; // struct IControl


} // namespace mxPiglets


