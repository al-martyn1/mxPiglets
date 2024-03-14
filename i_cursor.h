#pragma once

#include "non_copyable_object.h"
#include "i_comparable.h"


namespace mxPiglets {



#include "warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct ICursor : public NonCopyableObject
               , public IComparable
{

    // Имея один курсор, через него можно создать другой, но вообще, для этого будет фабричный метод у окна
    // Или нафик?
    //virtual std::shared_ptr<ICursor> createStockCursor(StockCursor sc) = 0;

    virtual bool isUserCursor() const = 0;
    virtual bool isStockCursor() const = 0;
    virtual EStockCursor getCursorKind() const = 0;

}; // struct ICursor


#include "warnings/pop.h"



} // namespace mxPiglets


