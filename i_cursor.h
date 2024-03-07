#pragma once

#include "non_copyable_object.h"

#include "enums.h"

//
#include <memory>

namespace mxPiglets {



#include "warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct ICursor : public NonCopyableObject
{

    // Имея один курсор, через него можно создать другой, но вообще, для этого будет фабричный метод у окна
    // Или нафик?
    //virtual std::shared_ptr<ICursor> createStockCursor(StockCursor sc) = 0;

}; // struct ICursor


#include "warnings/pop.h"



} // namespace mxPiglets


