#pragma once

#include "non_copyable_object.h"
#include "i_comparable.h"


namespace mxPiglets {



#include "warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct IElapsedTimer : public NonCopyableObject
                     , public IComparable
{

    virtual bool restart() = 0;
    virtual timeout_t getElapsedTime() const = 0;

}; // struct IElapsedTimer


#include "warnings/pop.h"


} // namespace mxPiglets


