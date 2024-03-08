#pragma once

namespace mxPiglets {

// Имеет метод Compare
// T должен иметь m_pImpl
template<typename T>
class Comparable //: public IComparable
{

public:

    // bool isNull() const
    // {
    //     auto pThisParent  = static_cast<const T*>(this);
    //     return !pThisParent->m_pImpl ? true : false;
    // }

    int compare(const Comparable &other) const
    {
        auto pThisT  = static_cast<const T*>(this);
        auto pOtherT = static_cast<const T*>(&other);

        if (!pThisT->m_pImpl && !pOtherT->m_pImpl)
            return 0; // Оба нулевые объекты - равны

        if (!pThisT->m_pImpl)
            return -1; // Текущий объект - нулевой - он меньше

        if (!pOtherT->m_pImpl)
            return 1; // Второй нулевой - текущий - больше

        return pThisT->m_pImpl->compare(pOtherT->m_pImpl.get());

    }

    bool operator==(const Comparable &other) const
    {
        return compare(other)==0;
    }

    bool operator!=(const Comparable &other) const
    {
        return compare(other)!=0;
    }

    // Остальные операторы отношений добъю потом

}; // class Comparable




} // namespace mxPiglets




