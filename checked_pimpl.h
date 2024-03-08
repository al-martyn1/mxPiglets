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
        auto pT  = static_cast<const T*>(this);
        return !pT->m_pImpl ? true : false;
    }

    bool isValid() const
    {
        auto pT  = static_cast<const T*>(this);
        if (!pT->m_pImpl)
            return false;

        return pT->m_pImpl->isValid();
    }

    auto getCheckedRawPtr(const char* methodName) const
    {
        if (isNull())
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": pimpl pointer not initialized");
        }

        auto pT  = static_cast<const T*>(this);

        return pT->m_pImpl.get();
    }

    auto getCheckedRawPtr(const char* methodName)
    {
        if (isNull())
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": pimpl pointer not initialized");
        }

        auto pT  = static_cast<T*>(this);

        return pT->m_pImpl.get();
    }

    template<typename TImpl>
    auto getCheckedCastedRawPtr(const char* methodName) const
    {
        auto pInterfaceRawPtr = getCheckedRawPtr(methodName);

        auto pImplRawPtr = dynamic_cast<TImpl*>(pInterfaceRawPtr);
        if (!pImplRawPtr)
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": is not compatible object implementation");
        }

        retun pImplRawPtr;
    }

    template<typename TImpl>
    auto getCheckedCastedRawPtr(const char* methodName)
    {
        auto pInterfaceRawPtr = getCheckedRawPtr(methodName);

        auto pImplRawPtr = dynamic_cast<TImpl*>(pInterfaceRawPtr);
        if (!pImplRawPtr)
        {
            throw std::runtime_error(std::string(methodName ? methodName : "Unknown method") + ": is not compatible object implementation");
        }

        return pImplRawPtr;
    }


};




} // namespace mxPiglets




