#pragma once

#include "i_control.h"



namespace mxPiglets {


struct IControlImplBase : public IControl
{

protected:

    ControlFlags         m_controlFlags = ControlFlags::none;


public:

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
    //! Установка всех флагов (assign). Возвращает старое значение флагов
    virtual ControlFlags setControlFlags(ControlFlags flags) override
    {
        return std::excange(m_controlFlags,flags);
    }

    //------------------------------
    //! Получение всех флагов
    virtual ControlFlags getControlFlags() const override
    {
        return m_controlFlags;
    }

    //------------------------------
    //! Получение флагов по маске
    virtual ControlFlags getControlFlagsByMask(ControlFlags mask) const override
    {
        return m_controlFlags & mask;
    }

    //------------------------------
    //! Сначала очищаются resetFlags-флаги (and), потом устанавливаются setFlags-флаги (or). Возвращает старое значение флагов
    virtual ControlFlags setResetControlFlags(ControlFlags setFlags, ControlFlags resetFlags) override
    {
        ControlFlags res = m_controlFlags;
        m_controlFlags &= ~resetFlags;
        m_controlFlags |= setFlags;
        return res;
    }


    //----------------------------------------------------------------------------
    // Хелперы для флагов

    bool getControlFlagTabStop() const override //!< Получение значения флага ControlFlags::tabStop
    {
        return getControlFlagsByMask(ControlFlags::tabStop) ? true : false;
    }

    //------------------------------
    bool setControlFlagTabStop(bool f) override //!< Установка значения флага ControlFlags::tabStop
    {
        auto prevFlags = f // Устанавливаем?
                       ? setResetControlFlags(ControlFlags::tabStop, 0                    ) // устанавливаем без сброса
                       : setResetControlFlags(0                    , ControlFlags::tabStop) // сбрасываем без установки
                       ;
        return (prevFlags & ControlFlags::tabStop) ? true : false;
    }



}; // struct IControlImplBase


} // namespace mxPiglets




