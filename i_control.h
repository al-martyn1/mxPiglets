#pragma once

#include "i_object.h"
//
#include "i_host_window.h"
//

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

    virtual IHostWindow*       getHostWindow() = 0;
    virtual const IHostWindow* getHostWindow() const = 0;
    virtual IHostWindow*       setHostWindow(IHostWindow* phw) = 0; //!< Возвращает старый указатель IHostWindow*


    //------------------------------
    // TabOrder
    virtual taborder_t getControlTabOrder() const = 0;
    virtual taborder_t setControlTabOrder(taborder_t newTabOrder) = 0;


    //------------------------------
    // Текст контрола - заголовок/метка, или содержимое (редактора) - зависит от типа контрола
    virtual String getControlText() const = 0;    //!< Получение текста контрола. Способ использования текста зависит от типа контрола
    virtual void setControlText(String text) = 0; //!< Установка текста контрола. Способ использования текста зависит от типа контрола

    //------------------------------
    // Имя типа, стиля, состояния, id - для использования в отрисовщике, потом на этой базе можно будет сделать недо-CSS
    virtual String getControlTypeString() const = 0;  //!< Возвращает имя типа контрола - button/pushbutton/checkbox/radiobutton/listbox etc. Определяется конкретным типом контрола, снаружи не задать
    virtual String getControlStateString() const = 0; //!< Возвращает имя/название состояния контрола - pushed/unpushed, checked/unchecked, selected/unselected, и тп. Определяется конкретным типом контрола, снаружи не задать.

    virtual String getControlStyleString() const = 0; //!< Возвращает имя стиля контрола
    virtual void setControlStyleString(String styString) = 0; //!< Задаёт имя стиля контрола

    virtual String getControIdString() const = 0; //!< Возвращает идентификатор контрола
    virtual void setControlIdString(String idString) = 0; //!< Задаёт идентификатор контрола


    //------------------------------
    // Флаги контрола

    // Флаги храним в одном слове - смысл разносить по отдельным bool переменым?
    // Зато можно получить/установить/изменить сразу пачкой по маске
    // Для удобства для каждого флага будут хелперы

    //! Установка всех флагов (assign). Возвращает старое значение флагов
    virtual ControlFlags setControlFlags(ControlFlags flags) = 0;

    //! Получение всех флагов
    virtual ControlFlags getControlFlags() const = 0;

    //! Получение флагов по маске
    virtual ControlFlags getControlFlagsByMask(ControlFlags mask) const = 0;

    //! Сначала очищаются resetFlags-флаги (and), потом устанавливаются setFlags-флаги (or). Возвращает старое значение флагов
    virtual ControlFlags setResetControlFlags(ControlFlags setFlags, ControlFlags resetFlags) = 0;


    //------------------------------
    // Обёртки для конкретных флагов

    virtual bool getControlFlagTabStop() const = 0; //!< Получение значения флага ControlFlags::tabStop
    virtual bool setControlFlagTabStop(bool f) = 0; //!< Установка значения флага ControlFlags::tabStop


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


