#pragma once

#include "i_object.h"

namespace mxPiglets {


struct IComparable : virtual public IObject
{

    virtual int compare(const IComparable *pOther) const = 0;

}; // struct NonCopyableObject


} // namespace mxPiglets

