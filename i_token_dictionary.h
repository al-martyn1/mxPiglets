#pragma once

#include "non_copyable_object.h"
#include "i_comparable.h"
#include "types.h"
#include "enums.h"


namespace mxPiglets {

struct ITokenDictionary : public NonCopyableObject
                    //, public IComparable
{

    ITokenDictionary() = default;
    MX_PIGLETS_IMPLEMENT_CLASS_COPY_OPS_DELETE(ITokenDictionary);
    MX_PIGLETS_IMPLEMENT_CLASS_MOVE_OPS_DEFAULT(ITokenDictionary);

    //! Задаёт стратегию работы с регистров символов в имени (только ASCII). Если вызвать после добавления элементов, то можно нарваться на нежданчик
    virtual bool setCaseIgnore(bool сaseIgnore) = 0;

    //! Задаёт макс число допустимых токенов. Если вызвать после добавления элементов, то можно нарваться на нежданчик
    virtual ETokenType setNumFixedTokenValues(ETokenType numFixedTokenValues) = 0;

    //! Задаёт стиль строк идентификаторов. Если вызвать после добавления элементов, то можно нарваться на нежданчик
    virtual marty_cpp::NameStyle setNameStyle(marty_cpp::NameStyle nameStyle) = 0;

    //! Добавляет известный токен, все имена добавляются без обработки
    virtual bool addWellKnownToken(ETokenType tk, const String &mainName, const std::vector<String> &allNames) = 0;

    //! Добавляет известный токен, доп имена/алиасы генерятся по заданной стратегии
    virtual bool addWellKnownToken(ETokenType tk, const String &mainName) = 0;

    //! Возвращает токен по строке, при необходимости добавляя
    virtual ETokenType getTokenForString(String name) = 0;

    //! Возвращает строку по токену, или пустую строку, если токен не найден
    virtual String getStringForToken(ETokenType tk) const  = 0;


}; // struct ITokenDictionary


} // namespace mxPiglets




