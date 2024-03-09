#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//

#include "../../i_elapsed_timer.h"
//
#include "../../elapsed_timer.h"

//
#include <memory>
#include <string>
#include <exception>
#include <stdexcept>
#include <utility>


namespace mxPiglets {



#include "../../warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct ElapsedTimerImpl : public IElapsedTimer
{

    timeout_t   startTick = 0;


    ElapsedTimerImpl()
    {
        startTick = (timeout_t)::GetTickCount();
    }

    virtual bool isValid() const override
    {
        return true;
    }

    //virtual int compare(const IWindowTimer *pTimer) const override
    virtual int compare(const IComparable *pComparable) const override
    {
        const ElapsedTimerImpl* pOther = dynamic_cast<const ElapsedTimerImpl*>(pComparable);
        if (!pOther)
        {
            throw std::runtime_error("IElapsedTimer::compare: pTimerOther is not compatible IElapsedTimer object implementation");
        }

        // Тут у нас нечего сравнивать, поэтому просто сравниваем указатели
        if (this==pOther)
            return 0;

        return this<pOther ? -1 : 1;
    }

    virtual bool restart() override
    {
        startTick = (timeout_t)::GetTickCount();
        return true;
    }


    virtual timeout_t getElapsedTime() const override
    {
        auto curTick = (timeout_t)::GetTickCount();
        return curTick - startTick;
    }


}; // struct ElapsedTimerImpl


#include "../../warnings/pop.h"


inline 
ElapsedTimer createElapsedTimer()
{
    auto pSharedImpl = std::make_shared<ElapsedTimerImpl>();
    return ElapsedTimer(std::static_pointer_cast<IElapsedTimer>(pSharedImpl));
}




} // namespace mxPiglets


