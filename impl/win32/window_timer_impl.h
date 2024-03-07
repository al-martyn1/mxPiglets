#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//

#include "../../i_window_timer.h"

//
#include <memory>
#include <string>
#include <exception>
#include <stdexcept>
#include <utility>


namespace mxPiglets {



#include "../../warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct WindowTimerImpl : public IWindowTimer
{

    HWND         hWnd           = 0;
    UINT_PTR     idTimerEvent   = 0;
    timeout_t    timerTimeoutMs = 0;
    bool         running        = false;


    //WindowTimerImpl(HWND h, UINT_PTR id) : hWnd(h), idTimerEvent(id) {}

    // WindowTimerImpl() : hWnd(0), idTimerEvent(0), timerTimeoutMs(0), running(false) {}

    WindowTimerImpl(HWND h, UINT_PTR id, timeout_t timeoutMs, bool bRunning) : hWnd(h), idTimerEvent(id), timerTimeoutMs(timeoutMs), running(bRunning)
    {
        if (running)
        {
            restart();
        }
    }

    WindowTimerImpl(WindowTimerImpl&& other)
    : hWnd          (std::exchange(other.hWnd, (HWND)0))
    , idTimerEvent  (std::exchange(other.idTimerEvent, 0u))
    , timerTimeoutMs(std::exchange(other.timerTimeoutMs, 0u))
    , running       (std::exchange(other.running, false))
    {
    }

    WindowTimerImpl& operator=(WindowTimerImpl&& other)
    {
        hWnd           = std::exchange(other.hWnd, (HWND)0);
        idTimerEvent   = std::exchange(other.idTimerEvent, 0u);
        timerTimeoutMs = std::exchange(other.timerTimeoutMs, 0u);
        running        = std::exchange(other.running, false);
        return *this;
    }


protected:


public:

    static
    WindowTimerImpl create(HWND h, UINT_PTR requestedId, timeout_t timeoutMs=0)
    {
        return WindowTimerImpl(h, requestedId, timeoutMs, true);
    }

    virtual bool isValid() const override
    {
        return hWnd!=0 && idTimerEvent!=0 && (::IsWindow(hWnd)?true:false);
    }

    #if 0
    static
    WindowTimerImpl createStopped(HWND h, UINT_PTR requestedId, timeout_t timeoutMs=0)
    {
        return WindowTimerImpl(h, requestedId, timeoutMs, false);
    }

    static
    WindowTimerImpl create(HWND h, UINT_PTR requestedId, timeout_t timeoutMs)
    {
        //auto res = WindowTimerImpl(h, 0);
        //res.idTimerEvent = ::SetTimer(h, requestedId, timeoutMs, 0);

        auto id = ::SetTimer(h, requestedId, timeoutMs, 0);

        if (id==0)
        {
            throw std::runtime_error("IWindowTimer::create: Failed to create WindowTimer");
        }

        // res.timerTimeoutMs = timeoutMs;
        // res.running = true;
        //  
        // // RVO/NRVO в MSVC2019 что-то не работает, поэтому втуляем std::move
        // return std::move(res);

        return WindowTimerImpl(h, id, timeoutMs, true);
        //return std::move(WindowTimerImpl(h, id, timeoutMs, true));
    }
    #endif

    ~WindowTimerImpl()
    {
        stop();
    }


    //virtual int compare(const IWindowTimer *pTimer) const override
    virtual int compare(const IComparable *pComparable) const override
    {
        const WindowTimerImpl* pOther = dynamic_cast<const WindowTimerImpl*>(pComparable);
        if (!pOther)
        {
            throw std::runtime_error("IWindowTimer::compare: pTimerOther is not compatible timer object implementation");
        }

        if (hWnd!=pOther->hWnd)
        {
            return hWnd<pOther->hWnd ? -1 : 1;
        }

        if (idTimerEvent!=pOther->idTimerEvent)
        {
            return idTimerEvent<pOther->idTimerEvent ? -1 : 1;
        }

        return 0;
    }

    virtual bool restart(timeout_t timeoutMs) override
    {
        if (!isValid())
        {
            return false;
        }

        auto res = ::SetTimer(hWnd, idTimerEvent, timeoutMs, 0);

        if (res!=0)
        {
            timerTimeoutMs = timeoutMs;
            running        = true;
            return true;
        }

        return false;
    }

    virtual bool restart() override
    {
        if (timerTimeoutMs==0)
        {
            throw std::runtime_error("IWindowTimer::restart: Failed to restart WindowTimer: timeout is zero");
        }

        if (!isValid())
        {
            return false;
        }

        auto res = ::SetTimer(hWnd, idTimerEvent, timerTimeoutMs, 0);

        if (res!=0)
        {
            running        = true;
            return true;
        }

        return false;
    }

    virtual bool stop() override
    {
        if (!isValid())
        {
            return false;
        }

        if (running)
        {
            running = false;
            return ::KillTimer(hWnd, idTimerEvent)!=0;
        }
        
        return true; // Остановленный таймер всегда останавливается 
    }

    virtual bool isStopped() const override
    {
        if (!isValid())
        {
            return true;
        }

        return !running;
    }


    virtual timeout_t getTimeout() const override
    {
        return timerTimeoutMs;
    }

}; // struct WindowTimerImpl


#include "../../warnings/pop.h"




} // namespace mxPiglets


