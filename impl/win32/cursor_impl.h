#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//

#include "../../i_cursor.h"
#include "cursor_handles_holder.h"

//
#include <memory>
#include <string>
#include <exception>
#include <stdexcept>
#include <utility>


namespace mxPiglets {



#include "../../warnings/push_disable_copy_ctor_implicitly_deleted.h"


struct CursorImpl : public ICursor
{

    HCURSOR                     hCursor  = 0;
    const CursorHandlesHolder  *pHolder  = 0;

    CursorImpl() = delete;

    CursorImpl(HCURSOR hc, CursorHandlesHolder *pH) : hCursor(hc), pHolder(pH) {}


    // Создаём стоковый курсор
    CursorImpl(EStockCursor cursorKind, CursorHandlesHolder *pH) : hCursor(0), pHolder(pH)
    {
        if (!pHolder)
        {
            throw std::runtime_error("Cursor::Cursor: invalid cursor fabrique taken");
        }

        hCursor = pH->createStockCursor(cursorKind);
    }

    virtual bool isValid() const override
    {
        return hCursor!=0; // && pHolder!=0; ???
    }

    virtual bool isUserCursor() const
    {
        if (!pHolder)
        {
            return false;
        }

        return pHolder->isKnownCursor(hCursor);
    }

    virtual bool isStockCursor() const override
    {
        if (!pHolder)
        {
            return false;
        }

        return pHolder->isStockCursor(hCursor);
    }

    virtual EStockCursor getCursorKind() const override
    {
        if (!pHolder)
        {
            return EStockCursor::invalid;
        }

        return pHolder->getCursorKind(hCursor);
    }


    virtual int compare(const IComparable *pComparable) const override
    {
        const CursorImpl* pOther = dynamic_cast<const CursorImpl*>(pComparable);
        if (!pOther)
        {
            throw std::runtime_error("ICursor::compare: pCursorOther is not compatible cursor object implementation");
        }

        auto k1 = getCursorKind();
        auto k2 = pOther->getCursorKind();

        if (k1!=k2)
        {
            return (std::uint32_t)k1<(std::uint32_t)k2 ? -1 : 1;
        }

        if (hCursor!=pOther->hCursor)
        {
            return hCursor<pOther->hCursor ? -1 : 1;
        }

        return 0;
    }


}; // struct WindowTimerImpl


#include "../../warnings/pop.h"




} // namespace mxPiglets


