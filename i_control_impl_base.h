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
    EDialogResult                m_controlDialogResult    = EDialogResult::none;

    String                       m_controlTypeString      ; //!< Строка с именем типа контрола
    mutable ETokenType           m_controlTypeToken       = ETokenType::tokenTypeNone; //!< Кешированный токен типа контрола

    String                       m_controlStyleString     ; //!< Строка с именем стиля контрола
    mutable ETokenType           m_controlStyleToken      = ETokenType::tokenTypeNone; //!< Кешированный токен стиля контрола

    String                       m_controlIdString        ; //!< Строка с идентификатором контрола
    mutable ETokenType           m_controlIdToken         = ETokenType::tokenTypeNone; //!< Кешированный токен идентификатор контрола

    taborder_t                   m_controlTabOrder        = tabOrderInvalid;

    Point                        m_position               = {0,0};
    Size                         m_size                   = {0,0};


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

    auto getCheckedHostWindowPtr(const char* methodName)
    {
        if (m_pHostWindow)
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": host window pointer not initialized");
        }

        return m_pHostWindow;
    }

    auto getCheckedHostWindowPtr(const char* methodName) const
    {
        if (m_pHostWindow)
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": host window pointer not initialized");
        }

        return m_pHostWindow;
    }


    //------------------------------
    //! Возвращает токен по строке, при необходимости добавляя
    virtual ETokenType getTokenForString(const String &name) const override
    {
        return getCheckedHostWindowPtr("IControlImplBase::getTokenForString")->getTokenForString(name);
    }

    //! Возвращает строку по токену, или пустую строку, если токен не найден
    virtual String getStringForToken(ETokenType tk) const override
    {
        return getCheckedHostWindowPtr("IControlImplBase::getStringForToken")->getStringForToken(tk);
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
    // DialogResult
    //! Закрывает ли интеракция с данным контролом диалог. Стили контрола должны содержать одно из значений ControlStyleFlags::DialogResult*, кроме DialogResultNone, и код результата не должен быть EDialogResult::invalid или EDialogResult::none
    virtual bool isControlCloseDialog() const override
    {
        auto controlStyleDialogResultFlags = getControlStyleDialogResultFlags();

        if (controlStyleDialogResultFlags==ControlStyleFlags::dialogResultNone) // является ли контрол таким контролом, который закрывает диалог?
        {
            return false; // контрол не закрывает диалог
        }

        if (m_controlDialogResult==EDialogResult::invalid || m_controlDialogResult==EDialogResult::none)
        {
            return false; // для контрола не установлен корректный код возврата диалога - контрол не закрывает диалог
        }

        return true;
    }

    //! Если на форме/в диалоге нажимается Enter, ищется первый контрол, который при вызове данной функции вернёт true
    virtual bool isControlCloseDialogDefaultOk() const override
    {
        auto controlStyleDialogResultFlags = getControlStyleDialogResultFlags();
        return controlStyleDialogResultFlags==ControlStyleFlags::dialogDefButton; // контрол имеет стиль defButton - это работает по нажатию Enter 
    }

    //! Если на форме/в диалоге нажимается Escape, ищется первый контрол, который при вызове данной функции вернёт true
    virtual bool isControlCloseDialogDefaultCancel() const override
    {
        auto controlStyleDialogResultFlags = getControlStyleDialogResultFlags();
        return controlStyleDialogResultFlags==ControlStyleFlags::dialogCancelButton; // контрол имеет стиль dialogCancelButton - это работает по нажатию Escape
    }

    //! Возвращает код возврата модального диалога. Если данный контрол является закрывающим диалог (стили ControlStyleFlags::DialogResult*, кроме DialogResultNone), то при интеракции с контролом возвращается данный код
    virtual EDialogResult getControlDialogResult() const override
    {
        return m_controlDialogResult;
    }

    //! Устанавливает код возврата модального диалога.
    virtual void setControlDialogResult(EDialogResult dlgRes) override
    {
        m_controlDialogResult = dlgRes;
    }


    //------------------------------
    // // Имя типа, стиля, состояния, id - для использования в отрисовщике, потом на этой базе можно будет сделать недо-CSS


    //! Возвращает имя типа контрола - button/pushbutton/checkbox/radiobutton/listbox etc. Определяется конкретным типом контрола, снаружи не задать
    virtual String getControlTypeString() const override
    {
        return m_controlTypeString;
    }

    //! Возвращает токен имени типа контрола. Определяется конкретным типом контрола, снаружи не задать. При этом строка типа контрола первична.
    virtual ETokenType getControlType() const override
    {
        if (m_controlTypeToken!=ETokenType::tokenTypeNone) // есть валидный токен имени типа
        {
            return m_controlTypeToken;
        }

        m_controlTypeToken = getTokenForString(m_controlTypeString); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено

        return m_controlTypeToken;
    }


    //! Возвращает имя стиля контрола
    virtual String getControlStyleString() const override
    {
        return m_controlStyleString;
    }

    //! Задаёт имя стиля контрола
    virtual void setControlStyleString(const String &styString) override
    {
        m_controlStyleToken  = ETokenType::tokenTypeNone; // сбрасываем кешированный токен стиля
        m_controlStyleString = styString;
    }

    //! Возвращает токен имени стиля контрола. При этом строка стиля контрола первична.
    virtual ETokenType getControlStyle() const override
    {
        if (m_controlStyleToken!=ETokenType::tokenTypeNone) // есть валидный токен имени типа
        {
            return m_controlStyleToken;
        }

        m_controlStyleToken = getTokenForString(m_controlStyleString); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено

        return m_controlStyleToken;
    }

    //! Задаёт стиль контрола используя токен. При этом строка стиля контрола первична.
    virtual void setControlStyle(ETokenType sty) override
    {
        m_controlStyleString = getStringForToken(sty); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено
        m_controlStyleToken  = sty;
    }


    //! Возвращает идентификатор контрола
    virtual String getControIdString() const override
    {
        return m_controlIdString;
    }

    //! Задаёт идентификатор контрола
    virtual void setControlIdString(const String &idString) override
    {
        m_controlIdToken  = ETokenType::tokenTypeNone; // сбрасываем кешированный токен ID
        m_controlIdString = idString;
    }

    //! Возвращает токен идентификатора контрола. При этом строка идентификатора контрола первична.
    virtual ETokenType getControId() const override
    {
        if (m_controlIdToken!=ETokenType::tokenTypeNone) // есть валидный токен ID
        {
            return m_controlIdToken;
        }

        m_controlIdToken = getTokenForString(m_controlIdString); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено

        return m_controlIdToken;
    }
    //! Задаёт идентификатор контрола используя токен. При этом строка идентификатора контрола первична.
    virtual void setControlId(ETokenType idString) override
    {
        m_controlIdString = getStringForToken(idString); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено
        m_controlIdToken  = idString;
    }

    //! Возвращает токен имени/названия состояния контрола. Определяется конкретным типом контрола, снаружи не задать.
    virtual ETokenType getControlState() const override
    {
        return ETokenType::normal; // default state of generic control
    }

    //! Возвращает имя/название состояния контрола - pushed/unpushed, checked/unchecked, selected/unselected, и тп. Определяется конкретным типом контрола, снаружи не задать.
    virtual String getControlStateString() const override
    {
        return getStringForToken(ETokenType::normal); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено
    }

    //! Устанавливает состояние контрола (например, начальное состояние) по токену. Все возможные токены состояний любых контролов есть у нас в словаре, но каждый контрол поддерживает только малую часть. Для разных контролов состояния с одним именем могут означать разное. При ошибке возвращает false (если состояние не известно, или его нельзя установить по другой причине). В тч для использования в дизайнере форм
    virtual bool setControlState(ETokenType tk) override
    {
        return tk==ETokenType::normal; // В базовом контроле поддерживается только это состояние, поэтому ничего устанавливать не надо
    }

    //! Устанавливает состояние контрола (например, начальное состояние) по строке. Все возможные токены состояний любых контролов есть у нас в словаре, но каждый контрол поддерживает только малую часть. Для разных контролов состояния с одним именем могут означать разное. При ошибке возвращает false (если состояние не известно, или его нельзя установить по другой причине). В тч для использования в дизайнере форм
    virtual bool setControlStateString(const String &stateString) override
    {
        return setControlState(getTokenForString(stateString)); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено
    }

    //! Возвращает список допустимых состояний контрола
    virtual TokenString getControlStates() const override
    {
        TokenString res;
        res.append(1, ETokenType::normal);
        return res;
    }

    std::vector<String> tokenStringToStringVectorHelper(const TokenString &tkStr) const
    {
        std::vector<String> res; res.reserve(tkStr.size());
        for( auto tk : tkStr)
            res.emplace_back(getStringForToken(tk)); // тут будет проверка хост окна, и кинуто исключение, если оно не установлено
        return res;
    }

    //! Возвращает список допустимых состояний контрола (вектор строк)
    virtual std::vector<String> getControlStateStrings() const override
    {
        return tokenStringToStringVectorHelper(getControlStates());
    }


    // ControlStyleFlags            m_controlStyleFlags      = ControlStyleFlags::none;
    // mutable ControlStateFlags    m_controlStateFlags      = ControlStateFlags::none;

    //!< Возвращает список псевдо-классов контрола. Набор псевдо-классов фиксирован и токены для строк предопределены и первичны
    virtual TokenString getControlStylePseudoClasses() const override
    {
        TokenString tokens; // ничего не резервируем, это же просто строка токенов, small string оптимизация и всё такое

        // Тут обрабатываем установленные стили контрола - ETokenType:: closeDialog/defaultOk/defaultCancel (см ControlStyleFlags)

        if (isControlCloseDialog())
        {
            tokens.append(1, ETokenType::closeDialog);

            if (isControlCloseDialogDefaultOk())
            {
                tokens.append(1, ETokenType::defaultOk);
            }

            if (isControlCloseDialogDefaultCancel())
            {
                tokens.append(1, ETokenType::defaultCancel);
            }
        }


        if ((m_controlStateFlags&ControlStateFlags::disabled)!=0)
            tokens.append(1, ETokenType::disabled); // flag disabled!=0 - disabled
        else
            tokens.append(1, ETokenType::enabled);


        if ((m_controlStateFlags&ControlStateFlags::grayed)!=0)
            tokens.append(1, ETokenType::grayed);


        if ((m_controlStateFlags&ControlStateFlags::readOnly)!=0)
            tokens.append(1, ETokenType::readOnly);


        if ((m_controlStateFlags&ControlStateFlags::hasFocus)!=0)
            tokens.append(1, ETokenType::focus);


        if ((m_controlStateFlags&ControlStateFlags::groupFocus)!=0)
            tokens.append(1, ETokenType::groupFocus);


        if ((m_controlStateFlags&ControlStateFlags::hover)!=0)
            tokens.append(1, ETokenType::hover);


        if ((m_controlStateFlags&ControlStateFlags::visited)!=0)
            tokens.append(1, ETokenType::visited);


        if ((m_controlStateFlags&ControlStateFlags::hadFocus)!=0)
            tokens.append(1, ETokenType::hadFocus);


        // if ((m_controlStateFlags&ControlStateFlags::)!=0)
        //     tokens.append(1, ETokenType::);
        // else
        //     tokens.append(1, ETokenType::);

        return tokens;
    }


    // //!< Возвращает список псевдо-классов контрола (вектор строк). Набор псевдо-классов фиксирован и токены для строк предопределены и первичны
     virtual std::vector<String> getControlStylePseudoClassStrings() const override
     {
         return tokenStringToStringVectorHelper(getControlStylePseudoClasses());
     }



    //----------------------------------------------------------------------------
    // Флаги контрола

    //------------------------------
    virtual ControlStyleFlags getControlStyleDialogResultFlags() const override
    {
        // По умолчанию просто возвращаем то, что установлено во флагах, но контрол может переопределить данное поведение
        return m_controlStyleFlags & ControlStyleFlags::dialogResultFlagsMask;
    }

    //------------------------------
    virtual ControlStyleFlags getControlStyleWantKeyFlags() const override
    {
        // По умолчанию просто возвращаем то, что установлено во флагах, но контрол может переопределить данное поведение
        return m_controlStyleFlags & ControlStyleFlags::wantKeyFlagsMask;
    }


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




