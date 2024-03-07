#pragma once

#include "i_cursor.h"
#include "comparable.h"
#include "checked_pimpl.h"

namespace mxPiglets {



struct Cursor : public Comparable<Cursor>
              , public CheckedPimpl<Cursor>
{

    friend class CheckedPimpl<Cursor>;

    explicit Cursor(std::shared_ptr<ICursor> pimpl) : m_pImpl(pimpl) {}

protected:

    std::shared_ptr<ICursor>  m_pImpl;

};


} // namespace mxPiglets


