#pragma once

#include "i_object.h"

namespace mxPiglets {

struct IWindowTimer : 
                    

struct IControl : public NonCopyableObject
                , public IComparable
{

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


    // Хелперы для флагов

    bool getControlFlagTabStop() const = 0; //!< Получение значения флага ControlFlags::tabStop
    bool setControlFlagTabStop(bool f) = 0; //!< Установка значения флага ControlFlags::tabStop



}; // struct IControl


} // namespace mxPiglets


