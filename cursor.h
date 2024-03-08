#pragma once

#include "i_cursor.h"
#include "comparable.h"
#include "checked_pimpl.h"
#include "defs.h"



namespace mxPiglets {



struct Cursor : public Comparable<Cursor>
              , public CheckedPimpl<Cursor>
{

    friend class Comparable<Cursor>;
    friend class CheckedPimpl<Cursor>;

    Cursor() = default;

    explicit Cursor(std::shared_ptr<ICursor> pimpl) : m_pImpl(pimpl) {}

    // MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DEFAULT(Cursor);
    // MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DEFAULT(Cursor);

    bool isUserCursor() const
    {
        return getCheckedRawPtr("Cursor::isUserCursor")->isUserCursor();
    }

    bool isStockCursor() const
    {
        return getCheckedRawPtr("Cursor::isStockCursor")->isStockCursor();
    }

    EStockCursor getCursorKind() const
    {
        return getCheckedRawPtr("Cursor::getCursorKind")->getCursorKind();
    }


protected:

    std::shared_ptr<ICursor>  m_pImpl;

};


} // namespace mxPiglets


