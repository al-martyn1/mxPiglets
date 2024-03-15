#pragma once

#include "defs.h"
#include "enums.h"
#include "types.h"




//----------------------------------------------------------------------------
namespace mxPiglets {



//-----------------------------------------------------------------------------
//! Создаёт строку StringType из std::wstring (работает только для базового диапазона ASCII).
template<typename StringType> inline StringType make_string( const std::wstring &str )
{
    StringType res;
    for( std::wstring::const_iterator it = str.begin(); it != str.end(); ++it)
        res.append(1, (typename StringType::value_type)*it );
    return res;
}

//-----------------------------------------------------------------------------
//! Создаёт строку StringType из std::string (работает только для базового диапазона ASCII).
template<typename StringType> inline StringType make_string( const std::string &str )
{
    StringType res;
    for( std::string::const_iterator it = str.begin(); it != str.end(); ++it)
        res.append(1, (typename StringType::value_type)*it );
    return res;
}

//-----------------------------------------------------------------------------
//! Создаёт строку StringType из const wchar_t* (работает только для базового диапазона ASCII).
template<typename StringType> inline StringType make_string( const wchar_t *str )
{
    StringType res;
    for(; *str; str++)
        res.append(1, (typename StringType::value_type)*str );
    return res;
}

//-----------------------------------------------------------------------------
//! Создаёт строку StringType из const char* (работает только для базового диапазона ASCII).
template<typename StringType> inline StringType make_string( const char *str )
{
    StringType res;
    for(; *str; str++)
        res.append(1, (typename StringType::value_type)*str );
    return res;
}

//-----------------------------------------------------------------------------
//! Создаёт строку StringType из sz wchar_t'ов (работает только для базового диапазона ASCII).
template<typename StringType> inline StringType make_string( wchar_t ch, size_t sz = 1 )
{
    StringType res;
    res.append(sz, (typename StringType::value_type)ch );
    return res;
}

//-----------------------------------------------------------------------------
//! Создаёт строку StringType из sz char'ов (работает только для базового диапазона ASCII).
template<typename StringType> inline StringType make_string( char ch, size_t sz = 1 )
{
    StringType res;
    res.append(sz, (typename StringType::value_type)ch );
    return res;
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
#if 0
inline
CanvasPoint p2p(CanvasPoint p)
{
    return p;
}

//------------------------------
inline
CanvasPoint p2p(WindowPoint p)
{
    return CanvasPoint{p.x,p.y};
}

//------------------------------
inline
WindowPoint p2p(CanvasPoint p)
{
    return WindowPoint{p.x,p.y};
}

//------------------------------
#endif




// using CoordValue  = CanvasCoordValue;
// using Point       = CanvasPoint     ;
//  
//  
//  
// struct Size
// {
//     CoordValue width  = 0;
//     CoordValue height = 0;
// };
//  
//  
// struct Rect
// {
//     CoordValue    x = 0;
//     CoordValue    y = 0;
//     CoordValue    width  = 0;
//     CoordValue    height = 0;





} // namespace mxPiglets



