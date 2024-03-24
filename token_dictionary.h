#pragma once

#include "i_token_dictionary.h"
#include "checked_pimpl.h"


namespace mxPiglets {


struct TokenDictionary : public CheckedPimpl<TokenDictionary>
{

    friend class CheckedPimpl<TokenDictionary>;

    TokenDictionary() = default;

    explicit TokenDictionary(std::shared_ptr<ITokenDictionary> pimpl) : m_pImpl(pimpl) {}

    // MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DEFAULT(WindowTimer);
    // MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DEFAULT(WindowTimer);


    //! Возвращает токен по строке, при необходимости добавляя
    ETokenType getTokenForString(const String &name)
    {
        return getCheckedRawPtr("TokenDictionary::getTokenForString")->getTokenForString(name);
    }

    //! Возвращает строку по токену, или пустую строку, если токен не найден
    String getStringForToken(ETokenType tk) const
    {
        return getCheckedRawPtr("TokenDictionary::getStringForToken")->getStringForToken(tk);
    }


protected:

    std::shared_ptr<ITokenDictionary>  m_pImpl;

}; // struct WindowTimer




} // namespace mxPiglets


