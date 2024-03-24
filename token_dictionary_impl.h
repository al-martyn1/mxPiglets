#pragma once


#include "marty_cpp/marty_cpp.h"
//
#include <string>
#include <unordered_map>



namespace mxPiglets {


//! Словарь токенов
template<typename StringType, typename TokenType>
class TokenDictionaryImpl
{
    // Токен с кодом 0 всегда должен быть невалидным

    // Аспекты работы
    // Все аспекты работы можно настраивать в рантайме, но желательно де первого использования, иначе я ни за что не отвечаю

    using TokenUnderlyingType = typename std::underlying_type<TokenType>::type;


    TokenType              m_numFixedTokenValues = (TokenType)1;
    TokenType              m_lastDynamicTokenId  = (TokenType)1; // NumFixedTokenValues; //  + 1;
    bool                   m_caseIgnore          = false;
    marty_cpp::NameStyle   m_nameStyle           = marty_cpp::NameStyle::all;

    // Мапы из строк в токены и обратно
    std::unordered_map<TokenType, StringType>   m_tokenToString;
    std::unordered_map<StringType, TokenType>   m_stringToToken;

    static
    TokenType incrementToken(TokenType tk)
    {
        if constexpr (std::is_enum<TokenType>::value==true)
        {
            return (TokenType)((TokenUnderlyingType)tk + 1);
        }
        else
        {
            return tk+1;
        }
    }

    //! Получает дополнительно вектор алиасов, не! делает над ним никаких преобразований, тупо добавляет
    bool addWellKnownTokenImpl(TokenType tk, StringType mainName, std::vector<StringType> allNames)
    {
        if (tk==(TokenType)0)
        {
            return false; // 0 - зарезервированное значение для токена
        }

        if ((TokenUnderlyingType)tk<256u)
        {
            return false; // нельзя иметь токены с кодом ASCII-символа
        }

        if (m_caseIgnore)
        {
            mainName = marty_cpp::toLower(mainName);
            for(auto &n : allNames)
            {
                n = marty_cpp::toLower(n);
            }

            allNames.emplace_back(mainName);
        }

        // Проверяем наличие токена и имён до добавления, чтобы в случае ошибки не было ничего произведено
        std::unordered_map<TokenType, StringType>::const_iterator ttsIt = m_tokenToString.find(tk);
        if (ttsIt!=m_tokenToString.end() && ttsIt->second!=mainName)
        {
            return false; // такой токен уже есть, но имя не соответствует тому, что мы добавляем
        }

        for(const auto &n : allNames)
        {
            std::unordered_map<StringType, TokenType>::const_iterator sttIt = m_stringToToken.find(n);
            if (sttIt!=m_stringToToken.end() && sttIt->second!=tk)
            {
                return false; // такое имя есть, но токен отличается - ошибка
            }
        }

        // Какая-то часть имён уже может быть добавлена, но существующим именам соответствует текущий токен, так что всё нормально

        m_tokenToString[tk] = mainName;

        for(const auto &n : allNames)
        {
            m_stringToToken[n] = tk;
        }

        return true;
    }

    //! Генерирует набор имён по установленным правилам
    std::vector<StringType> generateNameStrings(const StringType &name) const
    {
        std::vector<StringType> generatedNames;

        if (m_nameStyle==marty_cpp::NameStyle::all) // генерим все имена
        {
            auto styles = std::vector<marty_cpp::NameStyle>{ marty_cpp::NameStyle::hyphenStyle           
                                                           , marty_cpp::NameStyle::cppStyle              
                                                           , marty_cpp::NameStyle::camelStyle            
                                                           , marty_cpp::NameStyle::pascalStyle           
                                                           , marty_cpp::NameStyle::hyphenCamelMixedStyle 
                                                           , marty_cpp::NameStyle::hyphenPascalMixedStyle
                                                           , marty_cpp::NameStyle::cppCamelMixedStyle    
                                                           , marty_cpp::NameStyle::cppPascalMixedStyle   
                                                           , marty_cpp::NameStyle::defineStyle           
                                                           , marty_cpp::NameStyle::sqlStyle              
                                                           };
            for(auto st : styles)
            {
                auto newName = marty_cpp::makeEnamValueString(name, StringType() /* prefix */ , st);
                if (m_caseIgnore)
                {
                    newName = marty_cpp::toLower(newName);
                }
                generatedNames.emplace_back(newName);
            }
        }
        else if (m_nameStyle==marty_cpp::NameStyle::defaultStyle) // используем только то, что есть
        {
            generatedNames.emplace_back(m_caseIgnore ? marty_cpp::toLower(name) : name);
        }
        else
        {
            auto newName = marty_cpp::makeEnamValueString(name, StringType() /* prefix */ , m_nameStyle);
            if (m_caseIgnore)
            {
                newName = marty_cpp::toLower(newName);
            }
            generatedNames.emplace_back(newName);
        }
    
        return generatedNames;
    }

    //! Возвращает токен по строке
    TokenType getTokenForStringImpl(const StringType &name)
    {
        // auto nameCopy = name;
        // if (caseIgnore)
        // {
        //     nameCopy = marty_cpp::toLower(nameCopy);
        // }

        // Пробуем найти токен по имени/строке
        std::unordered_map<StringType, TokenType>::const_iterator sttIt = m_stringToToken.find(((m_caseIgnore) ? marty_cpp::toLower(name) : name));
        if (sttIt!=m_stringToToken.end())
        {
            return sttIt->second;
        }

        // Не нашли, надо добавлять

        auto generatedNames = generateNameStrings(name);

        TokenType newTokenId = incrementToken(m_lastDynamicTokenId);
        if (!addWellKnownTokenImpl(newTokenId, name, generatedNames))
        {
            return (TokenType)0;
        }

        m_lastDynamicTokenId = newTokenId;

        return newTokenId;
    }


public:

    TokenDictionaryImpl() = default;
    TokenDictionaryImpl(const TokenDictionaryImpl &) = default;
    TokenDictionaryImpl& operator=(const TokenDictionaryImpl &) = default;
    TokenDictionaryImpl(TokenDictionaryImpl &&) = default;
    TokenDictionaryImpl& operator=(TokenDictionaryImpl &&) = default;

    TokenDictionaryImpl(TokenType numFixedTokenValues_, bool caseIgnore_, marty_cpp::NameStyle nameStyle_)
    : m_numFixedTokenValues(numFixedTokenValues_)
    , m_lastDynamicTokenId(numFixedTokenValues_)
    , m_сaseIgnore(сaseIgnore_)
    , m_nameStyle(nameStyle_)
    // Оставляем по дефолту
    // , m_tokenToString()
    // , m_stringToToken()
    {}

    //! Задаёт стратегию работы с регистров символов в имени (только ASCII). Если вызвать после добавления элементов, то можно нарваться на нежданчик
    bool setCaseIgnore(bool сaseIgnore_)
    {
        return std::exchange(m_caseIgnore, сaseIgnore_);
    }

    //! Задаёт макс число допустимых токенов. Если вызвать после добавления элементов, то можно нарваться на нежданчик
    TokenType setNumFixedTokenValues(TokenType numFixedTokenValues_)
    {
        auto res = m_numFixedTokenValues;
        m_numFixedTokenValues = numFixedTokenValues_;
        m_lastDynamicTokenId = numFixedTokenValues_;

        if ((TokenUnderlyingType)m_numFixedTokenValues<256u)
        {
            m_numFixedTokenValues = (TokenType)256u;
        }

        if ((TokenUnderlyingType)m_lastDynamicTokenId<256u)
        {
            m_lastDynamicTokenId = (TokenType)256u;
        }

        return res;
    }

    //! Задаёт стиль строк идентификаторов. Если вызвать после добавления элементов, то можно нарваться на нежданчик
    marty_cpp::NameStyle setNameStyle(marty_cpp::NameStyle nameStyle_)
    {
        return std::exchange(m_nameStyle, nameStyle_);
    }

    //! Добавляет известный токен, все имена добавляются без обработки
    bool addWellKnownToken(TokenType tk, const StringType &mainName, const std::vector<StringType> &allNames)
    {
        if (tk>=m_numFixedTokenValues)
        {
            return false;
        }

        return addWellKnownTokenImpl(tk, mainName, allNames);
    }

    //! Добавляет известный токен, доп имена/алиасы генерятся по заданной стратегии
    bool addWellKnownToken(TokenType tk, const StringType &mainName)
    {
        if (tk>=m_numFixedTokenValues)
        {
            return false;
        }

        return addWellKnownTokenImpl(tk, mainName, generateNameStrings(mainName));
    }

    //! Возвращает токен по строке, при необходимости добавляя
    TokenType getTokenForString(StringType name)
    {
        return getTokenForStringImpl(name);
    }

    //! Возвращает строку по токену, или пустую строку, если токен не найден
    StringType getStringForToken(TokenType tk) const
    {
        std::unordered_map<TokenType, StringType>::const_iterator it = m_tokenToString.find(tk);
        if (it==m_tokenToString.end())
        {
            return StringType();
        }

        return it->second;
    }



}; // class TokenDictionaryImpl




} // namespace mxPiglets



