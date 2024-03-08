#pragma once

#include "i_window_timer.h"
#include "comparable.h"
#include "checked_pimpl.h"
#include "defs.h"




namespace mxPiglets {



struct WindowTimer : public Comparable<WindowTimer>
                   , public CheckedPimpl<WindowTimer>
{

    friend class Comparable<WindowTimer>;
    friend class CheckedPimpl<WindowTimer>;

    WindowTimer() = default;

    explicit WindowTimer(std::shared_ptr<IWindowTimer> pimpl) : m_pImpl(pimpl) {}

    // MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DEFAULT(WindowTimer);
    // MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DEFAULT(WindowTimer);

    bool restart(timeout_t timeoutMs)
    {
        return getCheckedRawPtr("WindowTimer::restart")->restart(timeoutMs);
    }

    bool restart()
    {
        return getCheckedRawPtr("WindowTimer::restart")->restart();
    }

    bool stop()
    {
        return getCheckedRawPtr("WindowTimer::stop")->stop();
    }

    bool isStopped() const
    {
        return getCheckedRawPtr("WindowTimer::isStopped")->isStopped();
    }

    timeout_t getTimeout() const
    {
        return getCheckedRawPtr("WindowTimer::getTimeout")->getTimeout();
    }


protected:

    std::shared_ptr<IWindowTimer>  m_pImpl;

};


} // namespace mxPiglets


