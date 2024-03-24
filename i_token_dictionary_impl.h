#pragma once

#include "i_token_dictionary.h"
#include "token_dictionary_impl.h"
#include "enums.h"


namespace mxPiglets {

struct ITokenDictionaryImpl : public ITokenDictionary
{
    TokenDictionaryImpl<String, ETokenType>   m_dict;


    ITokenDictionaryImpl() : m_dict() {} // = default;
    MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DELETE(ITokenDictionaryImpl);
    MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DEFAULT(ITokenDictionaryImpl);

    virtual bool isValid() const override
    {
        return true;
    }

    //! Задаёт стратегию работы с регистров символов в имени (только ASCII). Если вызвать после добавления элементов, то можно нарваться на нежданчик
    virtual bool setCaseIgnore(bool сaseIgnore) override
    {
        return m_dict.setCaseIgnore(сaseIgnore);
    }

    //! Задаёт макс число допустимых токенов. Если вызвать после добавления элементов, то можно нарваться на нежданчик
    virtual ETokenType setNumFixedTokenValues(ETokenType numFixedTokenValues) override
    {
        return m_dict.setNumFixedTokenValues(numFixedTokenValues);
    }

    //! Задаёт стиль строк идентификаторов. Если вызвать после добавления элементов, то можно нарваться на нежданчик
    virtual marty_cpp::NameStyle setNameStyle(marty_cpp::NameStyle nameStyle) override
    {
        return m_dict.setNameStyle(nameStyle);
    }

    //! Добавляет известный токен, все имена добавляются без обработки
    virtual bool addWellKnownToken(ETokenType tk, const String &mainName, const std::vector<String> &allNames) override
    {
        return m_dict.addWellKnownToken(tk, mainName, allNames);
    }

    //! Добавляет известный токен, доп имена/алиасы генерятся по заданной стратегии
    virtual bool addWellKnownToken(ETokenType tk, const String &mainName) override
    {
        return m_dict.addWellKnownToken(tk, mainName);
    }

    //! Возвращает токен по строке, при необходимости добавляя
    virtual ETokenType getTokenForString(String name) override
    {
        return m_dict.getTokenForString(name);
    }

    //! Возвращает строку по токену, или пустую строку, если токен не найден
    virtual String getStringForToken(ETokenType tk) const override
    {
        return m_dict.getStringForToken(tk);
    }


}; // struct ITokenDictionary



inline
std::shared_ptr<ITokenDictionary> createSharedTokenDictionary()
{
    auto pDictImpl = std::make_shared<ITokenDictionaryImpl>();
    return std::static_pointer_cast<ITokenDictionaryImpl>(pDictImpl);
}

inline
std::shared_ptr<ITokenDictionary> createSharedTokenDictionaryWithKnownTokens()
{
    auto pDict = createSharedTokenDictionary();

    pDict->setCaseIgnore(true);
    pDict->setNameStyle(marty_cpp::NameStyle::all);
    pDict->setNumFixedTokenValues((ETokenType)1024);

    std::map< ETokenType, std::vector<String> > allTokenNames;

    const std::map< ETokenType , std::string >& enumMainNamesMap = enum_serialize_get_map_ETokenType();
    const std::map< std::string, ETokenType  >& enumNamesMap     = enum_deserialize_get_map_ETokenType();

    std::map< std::string, ETokenType >::const_iterator nit = enumNamesMap.begin();
    for(; nit!=enumNamesMap.end(); ++nit)
    {
        if (nit->second==(ETokenType)0)
            continue;

        allTokenNames[nit->second].emplace_back(make_string<String>(nit->first));
    }

    std::map< ETokenType, std::vector<String> >::const_iterator atit = allTokenNames.begin();
    for(; atit!=allTokenNames.end(); ++atit)
    {
        std::map< ETokenType, std::string >::const_iterator mnit = enumMainNamesMap.find(atit->first);
        if (mnit==enumMainNamesMap.end())
            continue;

        auto mainName = make_string<String>(mnit->second);
        pDict->addWellKnownToken(atit->first, mainName, atit->second);
    }

    return pDict;
}


} // namespace mxPiglets




