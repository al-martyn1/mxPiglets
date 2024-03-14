#pragma once

#include "i_elapsed_timer.h"
#include "comparable.h"
#include "checked_pimpl.h"



namespace mxPiglets {



struct ElapsedTimer : public Comparable<ElapsedTimer>
                    , public CheckedPimpl<ElapsedTimer>
{

    friend class Comparable<ElapsedTimer>;
    friend class CheckedPimpl<ElapsedTimer>;

    ElapsedTimer() = default;

    explicit ElapsedTimer(std::shared_ptr<IElapsedTimer> pimpl) : m_pImpl(pimpl) {}

    bool restart()
    {
        return getCheckedRawPtr("WindowTimer::restart")->restart();
    }

    timeout_t getElapsedTime() const
    {
        return getCheckedRawPtr("WindowTimer::getElapsedTime")->getElapsedTime();
    }


protected:

    std::shared_ptr<IElapsedTimer>  m_pImpl;

}; // struct WindowTimer


} // namespace mxPiglets


