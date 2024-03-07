#pragma once

#include "non_copyable_object.h"
#include "enums.h"
#include "i_comparable.h"


//
#include <memory>
#include <cstdint>

namespace mxPiglets {


typedef    std::uint32_t    timeout_t;




#include "warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct IWindowTimer : public NonCopyableObject
                    , public IComparable
{

    // virtual int compare(const IComparable *pOther) const override
    // virtual int compare(const IWindowTimer *pTimer) const = 0;

    virtual bool restart(timeout_t timeoutMs) = 0;

    virtual bool restart() = 0;

    virtual bool stop() = 0;

    virtual bool isStopped() const = 0;

    virtual timeout_t getTimeout() const = 0;

}; // struct IWindowTimer


#include "warnings/pop.h"


} // namespace mxPiglets


