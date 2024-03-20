#pragma once

#include "i_control.h"



namespace mxPiglets {


struct IControlImplBase : public IControl
{

protected:

    IHostWindow*                 m_pHostWindow            = 0;
    ControlStyleFlags            m_controlStyleFlags      = ControlStyleFlags::none;
    mutable ControlStateFlags    m_controlStateFlags      = ControlStateFlags::none;

    String                       m_controlText;
    String                       m_controlTypeString;
    String                       m_controlStyleString;
    String                       m_controlIdString;
    taborder_t                   m_controlTabOrder        = tabOrderInvalid;

    Point                        m_position;
    Size                         m_size;


public:


    MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DELETE(IControlImplBase);

    //----------------------------------------------------------------------------
    // Контролы сравнивать имеет смысл только по адресу объекта
    virtual int compare(const IComparable *pOther) const override
    {
        const IComparable *pCmpThis = static_cast<const IComparable*>(this);

        if (pCmpThis==pOther)
        {
            return 0;
        }

        return pCmpThis<pOther ? -1 : 1;
    }

    //----------------------------------------------------------------------------
    // HostWindow

    virtual IHostWindow*       getHostWindow() override
    {
        return m_pHostWindow;
    }

    virtual const IHostWindow* getHostWindow() const override
    {
        return m_pHostWindow;
    }

    virtual IHostWindow*       setHostWindow(IHostWindow* phw) override //!< Возвращает старый указатель IHostWindow*
    {
        // Также тут надо удалить контрол из текущего хост окна, если задано.

        // Надо также установить хост всем детям, если текущий m_pHostWindow равен нулю
        // При этом также надо задать taborder всем детям, которым требуется.
        // Такое поведение нужно, когда мы создаём групповой контрол, например, панель, и добавляем туда другие контролы, и собираемся это всё переиспользовать как отдельный контрол
        // Но это надо обдумать

        // После установки таб ордера добавляем контрол в хост окно

        return std::exchange(m_pHostWindow, phw);
    }

    //------------------------------
    // Текст контрола - заголовок/метка, или содержимое (редактора) - зависит от типа контрола
    virtual String getControlText() const override    //!< Получение текста контрола. Способ использования текста зависит от типа контрола
    {
        return m_controlText;
    }

    virtual void setControlText(String text) override //!< Установка текста контрола. Способ использования текста зависит от типа контрола
    {
        m_controlText = text;
    }

    //------------------------------
    // TabOrder
    virtual taborder_t getControlTabOrder() const override
    {
        return m_controlTabOrder;
    }

    virtual taborder_t setControlTabOrder(taborder_t newTabOrder) override
    {
        return std::exchange(m_controlTabOrder, newTabOrder);
    }
    

    //------------------------------
    // Имя типа, стиля, состояния, id - для использования в отрисовщике, потом на этой базе можно будет сделать недо-CSS
    virtual String getControlTypeString() const override  //!< Возвращает имя типа контрола - button/pushbutton/checkbox/radiobutton/listbox etc. Определяется конкретным типом контрола, снаружи не задать
    {
        return m_controlTypeString;
    }

    virtual String getControlStateString() const override //!< Возвращает имя/название состояния контрола - pushed/unpushed, checked/unchecked, selected/unselected, и тп. Определяется конкретным типом контрола, снаружи не задать.
    {
        return make_string<String>("default");
    }

    virtual String getControlStyleString() const override //!< Возвращает имя стиля контрола
    {
        return m_controlStyleString;
    }

    virtual void setControlStyleString(String styString) override //!< Задаёт имя стиля контрола
    {
        m_controlStyleString = styString;
    }

    virtual String getControIdString() const override //!< Возвращает идентификатор контрола
    {
        return m_controlIdString;
    }

    virtual void setControlIdString(String idString) override //!< Задаёт идентификатор контрола
    {
        m_controlIdString = idString;
    }


    //----------------------------------------------------------------------------
    // Флаги контрола

    //------------------------------
    //! Установка всех флагов (assign). Возвращает старое значение флагов
    virtual ControlStyleFlags setControlStyleFlags(ControlStyleFlags flags) override
    {
        return std::exchange(m_controlStyleFlags,flags);
    }

    //------------------------------
    //! Получение всех флагов
    virtual ControlStyleFlags getControlStyleFlags() const override
    {
        return m_controlStyleFlags;
    }

    //------------------------------
    //! Получение флагов по маске
    virtual ControlStyleFlags getControlStyleFlagsByMask(ControlStyleFlags mask) const override
    {
        return m_controlStyleFlags & mask;
    }

    //------------------------------
    //! Сначала очищаются resetFlags-флаги (and), потом устанавливаются setFlags-флаги (or). Возвращает старое значение флагов
    virtual ControlStyleFlags setResetControlStyleFlags(ControlStyleFlags setFlags, ControlStyleFlags resetFlags) override
    {
        ControlStyleFlags res = m_controlStyleFlags;
        m_controlStyleFlags &= ~resetFlags;
        m_controlStyleFlags |= setFlags;
        return res;
    }


    //------------------------------
    // Обёртки для конкретных флагов

    virtual bool getControlStyleFlagTabStop() const override //!< Получение значения флага ControlStyleFlags::tabStop
    {
        return getControlStyleFlagsByMask(ControlStyleFlags::tabStop)==0 ? false : true;
    }

    //------------------------------
    virtual bool setControlStyleFlagTabStop(bool f) override //!< Установка значения флага ControlStyleFlags::tabStop
    {
        auto prevFlags = f // Устанавливаем?
                       ? setResetControlStyleFlags(ControlStyleFlags::tabStop, ControlStyleFlags::none   ) // устанавливаем без сброса
                       : setResetControlStyleFlags(ControlStyleFlags::none   , ControlStyleFlags::tabStop) // сбрасываем без установки
                       ;
        return (prevFlags & ControlStyleFlags::tabStop)==0 ? false : true;
    }




    //------------------------------
    // Флаги состояния контрола, аналогично флагам стиля
    //------------------------------
    //! Установка всех флагов (assign). Возвращает старое значение флагов
    virtual ControlStateFlags setControlStateFlags(ControlStateFlags flags) override
    {
        return std::exchange(m_controlStateFlags,flags);
    }

    //------------------------------
    //! Получение всех флагов
    virtual ControlStateFlags getControlStateFlags() const override
    {
        return m_controlStateFlags;
    }

    //------------------------------
    //! Получение флагов по маске
    virtual ControlStateFlags getControlStateFlagsByMask(ControlStateFlags mask) const override
    {
        return m_controlStateFlags & mask;
    }

    //------------------------------
    //! Сначала очищаются resetFlags-флаги (and), потом устанавливаются setFlags-флаги (or). Возвращает старое значение флагов
    virtual ControlStateFlags setResetControlStateFlags(ControlStateFlags setFlags, ControlStateFlags resetFlags) override
    {
        ControlStateFlags res = m_controlStateFlags;
        m_controlStateFlags &= ~resetFlags;
        m_controlStateFlags |= setFlags;
        return res;
    }


    //------------------------------
    // Обёртки для конкретных флагов

    virtual bool getControlStateFlagNeedRepaint() const override //!< Получение значения флага ControlStateFlags::needRepaint
    {
        return getControlStateFlagsByMask(ControlStateFlags::needRepaint)==0 ? false : true;
    }

    virtual bool setControlStateFlagNeedRepaint(bool f) override //!< Установка значения флага ControlStateFlags::needRepaint
    {
        auto prevFlags = f // Устанавливаем?
                       ? setResetControlStateFlags(ControlStateFlags::needRepaint, ControlStateFlags::none   ) // устанавливаем без сброса
                       : setResetControlStateFlags(ControlStateFlags::none       , ControlStateFlags::needRepaint) // сбрасываем без установки
                       ;
        return (prevFlags & ControlStateFlags::needRepaint)==0 ? false : true;
    }

    // //------------------------------
    // // Обёртки для конкретных флагов
    //  
    // virtual bool getControlStyleFlagTabStop() const override //!< Получение значения флага ControlStyleFlags::tabStop
    // {
    //     return getControlStyleFlagsByMask(ControlStyleFlags::tabStop)==0 ? false : true;
    // }
    //  
    // //------------------------------
    // virtual bool setControlStyleFlagTabStop(bool f) override //!< Установка значения флага ControlStyleFlags::tabStop
    // {
    //     auto prevFlags = f // Устанавливаем?
    //                    ? setResetControlStyleFlags(ControlStyleFlags::tabStop, ControlStyleFlags::none   ) // устанавливаем без сброса
    //                    : setResetControlStyleFlags(ControlStyleFlags::none   , ControlStyleFlags::tabStop) // сбрасываем без установки
    //                    ;
    //     return (prevFlags & ControlStyleFlags::tabStop)==0 ? false : true;
    // }

    //------------------------------
    // Положение и координаты - относительно родителя

    virtual Point getPosition() const override
    {
        return m_position;
    }

    virtual Point setPosition(Point newPos) override
    {
        return std::exchange(m_position, newPos);
    }

    virtual Size  getSize() const override
    {
        return m_size;
    }

    virtual Size  setSize(Size newSize) override
    {
        return std::exchange(m_size, newSize);
    }

    virtual Rect  getBounds() const override
    {
        return Rect(m_position, m_size);
    }

    virtual Rect  setBounds(Rect r) override
    {
        Rect res   = getBounds();
        m_position = r.getPos();
        m_size     = r.getSize();
        return res;
    }

    virtual CoordValue getLeft() const override
    {
        return m_position.x;
    }

    virtual CoordValue setLeft(CoordValue v) override
    {
        return std::exchange(m_position.x, v);
    }

    virtual CoordValue getTop() const override
    {
        return m_position.y;
    }

    virtual CoordValue getTop(CoordValue v) override
    {
        return std::exchange(m_position.y, v);
    }

    virtual CoordValue getWidth() const override
    {
        return m_size.width;
    }

    virtual CoordValue setWidth(CoordValue v) override
    {
        return std::exchange(m_size.width, v);
    }

    virtual CoordValue getHeight() const override
    {
        return m_size.height;
    }

    virtual CoordValue getHeight(CoordValue v) override
    {
        return std::exchange(m_size.height, v);
    }

    virtual CoordValue getRight() const override
    {
        return m_position.x + m_size.width;
    }

    virtual CoordValue setRight(CoordValue v) override
    {
        auto res = getRight();
        m_size.width = v - m_position.x;
        return res;
    }

    virtual CoordValue getBottom() const override
    {
        return m_position.y + m_size.height;
    }

    virtual CoordValue getBottom(CoordValue v) override
    {
        auto res = getRight();
        m_size.height = v - m_position.x;
        return res;
    }





}; // struct IControlImplBase


} // namespace mxPiglets




