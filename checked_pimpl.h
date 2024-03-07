#pragma once


#include <memory>
#include <string>
#include <exception>
#include <stdexcept>


namespace mxPiglets {

template<typename T>
class CheckedPimpl
{

public:

    bool isNull() const
    {
        auto pThisParent  = static_cast<const T*>(this);
        return !pThisParent->m_pImpl ? true : false;
    }

    bool isValid() const
    {
        auto pThisParent  = static_cast<const T*>(this);
        if (!pThisParent->m_pImpl)
            return false;

        return pThisParent->m_pImpl->isValid();
    }

    auto getCheckedRawPtr(const char* methodName) const
    {
        if (isNull())
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": pimpl pointer not initialized");
        }

        auto pThisParent  = static_cast<const T*>(this);

        return pThisParent->m_pImpl.get();
    }

    auto getCheckedRawPtr(const char* methodName)
    {
        if (isNull())
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": pimpl pointer not initialized");
        }

        auto pThisParent  = static_cast<T*>(this);

        return pThisParent->m_pImpl.get();
    }



};




} // namespace mxPiglets




