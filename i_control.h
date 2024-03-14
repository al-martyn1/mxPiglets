#pragma once

#include "i_object.h"
//
#include "i_host_window.h"
//

namespace mxPiglets {

struct IWindowTimer : 
                    

struct IControl : public NonCopyableObject
                , public IComparable
{

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


    // Хелперы для флагов

    bool getControlFlagTabStop() const = 0; //!< Получение значения флага ControlFlags::tabStop
    bool setControlFlagTabStop(bool f) = 0; //!< Установка значения флага ControlFlags::tabStop



}; // struct IControl


} // namespace mxPiglets


