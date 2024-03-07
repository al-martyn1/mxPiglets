#pragma once

#include "i_object.h"

namespace mxPiglets {


struct NonCopyableObject : virtual public IObject
{
    NonCopyableObject() = default;

    NonCopyableObject(const NonCopyableObject&) = delete;
    NonCopyableObject& operator=(const NonCopyableObject&) = delete;

    NonCopyableObject(NonCopyableObject&&) = default;
    NonCopyableObject& operator=(NonCopyableObject&&) = default;

}; // struct NonCopyableObject


} // namespace mxPiglets

