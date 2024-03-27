#pragma once

#include "marty_draw_context/draw_context_enums.h"
#include "marty_draw_context/draw_context_types.h"
#include "marty_draw_context/i_animation.h"
#include "marty_draw_context/i_draw_context.h"
#include "marty_draw_context/i_image_list.h"

//
#include "enums.h"

#include <type_traits>
#include <functional>
#include <memory>
#include <cctype>
#include <string>



namespace mxPiglets {

using ETokenUnderlyingType = std::underlying_type<ETokenType>::type;

} // namespace mxPiglets {



// template <class T> inline
// std::size_t hash_combine(std::size_t seed, const T &v)
// {
//     //std::hash<T> hasher;
//     return seed ^ ( std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2) );
// }



namespace std {

template <>
struct hash<mxPiglets::ETokenType>
{
    std::size_t operator()(const mxPiglets::ETokenType& c) const
    {
        // std::size_t seed = marty_draw_context::hash_combine(0,c.x);
        // return marty_draw_context::hash_combine(seed,c.y);

        // Для std::uint16_t похоже нет специализации, но мы знаем, какой тип используется, поэтому прямо задаём тип
        typedef mxPiglets::ETokenUnderlyingType UnderlyingType;
        //typedef  unsigned short  UnderlyingType;

        return std::hash<UnderlyingType>()((UnderlyingType)c);
    }
};


#if (__cplusplus) > 201703L
    //#define _HAS_CXX17 1
    //#define _HAS_CXX20 1
#elif (__cplusplus) > 201402L
    //#define _HAS_CXX17 1
    //#define _HAS_CXX20 0
#else // _STL_LANG <= 201402L
    //#define _HAS_CXX17 0
    //#define _HAS_CXX20 0
#endif


#if defined(_MSC_VER)
// #elif defined(__CC_ARM)
// #elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
// #elif defined(__ICCARM__) || defined(__IAR_SYSTEMS_ICC__)
#elif defined(__GNUC__)
// #elif defined(__clang__)
// #elif defined(__BORLANDC__)
// #elif defined(__CODEGEARC__)
#else
    // #error "std::char_traits<mxPiglets::ETokenType>: Unknown (unsupported) compiler"
#endif



} // namespace std {


//----------------------------------------------------------------------------
namespace mxPiglets {



//----------------------------------------------------------------------------

#if defined(_MSC_VER)

    struct ETokenTypeCharTraits : std::_Char_traits<ETokenType, ETokenUnderlyingType> {};

#else

    // Надо вручную колбасить ETokenTypeCharTraits, чтобы оно было совместимо со стандартным

    struct ETokenTypeCharTraits
    {
        typedef ETokenType              char_type ;
        typedef ETokenUnderlyingType    int_type  ;
        typedef std::streamoff          off_type  ;
        typedef std::streampos          pos_type  ;
        typedef std::mbstate_t          state_type;
        
        static constexpr void assign(char_type& c1, const char_type& c2) noexcept   { c1 = c2; }
        static constexpr bool eq(const char_type& c1, const char_type& c2) noexcept { return c1 == c2; }
        static constexpr bool lt(const char_type& c1, const char_type& c2) noexcept { return c1 < c2; }
        
        static constexpr int compare(const char_type* s1, const char_type* s2, std::size_t n)
        {
            for (std::size_t i = 0; i < n; ++i)
            {
                if (lt(s1[i], s2[i]))
                    return -1;
                else if (lt(s2[i], s1[i]))
                    return 1;
            }
        
            return 0;
        }
        
        static constexpr std::size_t length(const char_type* s)
        {
            std::size_t i = 0;
            while (!eq(s[i], (ETokenType)0))
                ++i;
            return i;
        }
        
        static constexpr const char_type* find(const char_type* s, std::size_t n, const char_type& a)
        {
            for (std::size_t i = 0; i < n; ++i)
            {
                if (eq(s[i], a))
                    return s + i;
            }
            return 0;
        }
        
        static char_type* move(char_type* s1, const char_type* s2, std::size_t n)
        {
            if (n==0)
                return s1;
            return (static_cast<char_type*>(__builtin_memmove(s1, s2, n * sizeof(char_type))));
        }
        
        static char_type* copy(char_type* s1, const char_type* s2, std::size_t n)
        {
            if (n == 0)
                return s1;
            return (static_cast<char_type*>(__builtin_memcpy(s1, s2, n * sizeof(char_type))));
        }
        
        static char_type* assign(char_type* s, std::size_t n, char_type a)
        {
            for (std::size_t i = 0; i < n; ++i)
                assign(s[i], a);
            return s;
        }
        
        static constexpr char_type to_char_type(const int_type& c) noexcept { return char_type(c); }
        static constexpr int_type to_int_type(const char_type& c) noexcept  { return int_type(c); }
        static constexpr bool eq_int_type(const int_type& c1, const int_type& c2) noexcept { return c1 == c2; }
        static constexpr int_type eof() noexcept { return static_cast<int_type>(-1); }
        static constexpr int_type not_eof(const int_type& c) noexcept { return eq_int_type(c, eof()) ? 0 : c; }
    
    }; // struct ETokenTypeCharTraits

#endif

//----------------------------------------------------------------------------


using TokenString = std::basic_string<ETokenType, ETokenTypeCharTraits>;

//----------------------------------------------------------------------------




//----------------------------------------------------------------------------
using ICanvas                  = marty_draw_context::IDrawContext;

using CanvasCoords             = marty_draw_context::DrawCoord;
using CanvasCoordValue         = marty_draw_context::DrawCoord::value_type;

using CanvasSize               = marty_draw_context::DrawCoord;
using CanvasPoint              = marty_draw_context::DrawCoord;

using CanvasImageSize          = marty_draw_context::ImageSize;
using CanvasImageListImageInfo = marty_draw_context::ImageListImageInfo;
using ICanvasImageList         = marty_draw_context::IImageList;

using CanvasColorRef = marty_draw_context::ColorRef;

using CanvasFontWeight         = marty_draw_context::FontWeight;
using CanvasFontStyleFlags     = marty_draw_context::FontStyleFlags;

template<typename StringType>
using CanvasFontSimpleParamsT  = marty_draw_context::FontSimpleParamsT<StringType>;

template<typename StringType>
using CanvasFontParamsT        = marty_draw_context::FontParamsT<StringType>;

using CanvasFontParamsA        = marty_draw_context::FontParamsA;
using CanvasFontParamsW        = marty_draw_context::FontParamsW;

using CanvasSimpleFontMetrics  = marty_draw_context::SimpleFontMetrics;

using CanvasPenParamsWithColor = marty_draw_context::PenParamsWithColor;
using CanvasPenParams          = marty_draw_context::PenParams;

using CanvasLineType           = marty_draw_context::LineType;
using CanvasLineDirection      = marty_draw_context::LineDirection;
using CanvasLineEndcapStyle    = marty_draw_context::LineEndcapStyle;
using CanvasLineJoinStyle      = marty_draw_context::LineJoinStyle;

using CanvasHorAlign           = marty_draw_context::HorAlign;
using CanvasVertAlign          = marty_draw_context::VertAlign;
using CanvasGradientRoundRectFillFlags = marty_draw_context::GradientRoundRectFillFlags;
using CanvasGradientType       = marty_draw_context::GradientType;
using CanvasBkMode             = marty_draw_context::BkMode;
using CanvasArcDirection       = marty_draw_context::ArcDirectionEnum;

using CanvasSmoothingMode      = marty_draw_context::SmoothingMode;
using CanvasDrawingPrecise     = marty_draw_context::DrawingPrecise;
using CanvasDrawTextFlags      = marty_draw_context::DrawTextFlags;


using ICanvasAnimation         = marty_draw_context::IAnimation;
using ICanvasSpriteAnimation   = marty_draw_context::ISpriteAnimation;

using ICanvasAnimationDrawingHandler = marty_draw_context::IAnimationDrawingHandler;
using ICanvasAnimationFrameChangeHandler = marty_draw_context::IAnimationFrameChangeHandler;

template<typename THandler>
using CanvasAnimationDrawer    = marty_draw_context::AnimationDrawer<THandler>;
using CanvasSpriteAnimationDrawer = marty_draw_context::SpriteAnimationDrawer;

template<typename THandler>
using CanvasAnimationFrameChangeHandler = marty_draw_context::AnimationFrameChangeHandler<THandler>;

//using Canvas = marty_draw_context::


inline
std::shared_ptr<ICanvasAnimationDrawingHandler> createSharedCanvasSpriteAnimationDrawer()
{
    return marty_draw_context::createSharedSpriteAnimationDrawer();
}

template<typename THandler>
inline
std::shared_ptr<ICanvasAnimationDrawingHandler> createSharedCanvasAnimationDrawer(THandler handler)
{
    return marty_draw_context::createSharedAnimationDrawer(handler);
}


template<typename THandler> inline
std::shared_ptr<ICanvasAnimationFrameChangeHandler> createSharedCanvasAnimationFrameChangeHandler(THandler h)
{
    return marty_draw_context::createSharedAnimationFrameChangeHandler(THandler h)
}



// using Canvas = marty_draw_context::
// using Canvas = marty_draw_context::


//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
inline
CanvasCoordValue distance(const CanvasCoords& c1, const CanvasCoords& c2)
{
    return marty_draw_context::distance(c1,c2);
}

//----------------------------------------------------------------------------





//----------------------------------------------------------------------------
using timeout_t  = std::uint32_t;


using taborder_t = std::uint32_t;

constexpr const taborder_t tabOrderAuto              = 0;
constexpr const taborder_t tabOrderInvalid           = (taborder_t)-1; // не участвует в смене фокуса по табу
constexpr const taborder_t tabOrderDefAutoIncrement  = 10;




//----------------------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32)

    using String = std::wstring;

#else // Linups and others

    using String = std::wstring;

#endif

using Char = String::value_type;

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
struct WindowPoint
{
    int x = 0;
    int y = 0;

}; // struct Point



struct WindowSize
{
    int width  = 0;
    int height = 0;

}; // struct WindowSize



struct WindowRect
{
    int x = 0;
    int y = 0;
    int width  = 0;
    int height = 0;

    WindowRect() = default;
    WindowRect(const WindowRect &) = default;
    WindowRect& operator=(const WindowRect &) = default;
    WindowRect(WindowRect &&) = default;
    WindowRect& operator=(WindowRect &&) = default;

    WindowRect(int x_, int y_, int width_, int height_)
    : x(x_)
    , y(y_)
    , width (width_ )
    , height(height_)
    {}

    WindowRect(WindowPoint pos, WindowSize size)
    : x(pos.x)
    , y(pos.y)
    , width (size.width )
    , height(size.height)
    {}

    WindowPoint getPos() const
    {
        return WindowPoint{x,y};
    }

    WindowSize getSize() const
    {
        return WindowSize{width,height};
    }

}; // struct WindowRect




// Координаты и размеры, которыми оперируют контролы

using CoordValue  = CanvasCoordValue;
using Point       = CanvasPoint     ;



struct Size
{
    CoordValue width  = 0;
    CoordValue height = 0;
};


struct Rect
{
    CoordValue    x = 0;
    CoordValue    y = 0;
    CoordValue    width  = 0;
    CoordValue    height = 0;

    Rect() = default;
    Rect(const Rect &) = default;
    Rect& operator=(const Rect &) = default;
    Rect(Rect &&) = default;
    Rect& operator=(Rect &&) = default;

    Rect(CoordValue x_, CoordValue y_, CoordValue width_, CoordValue height_)
    : x(x_)
    , y(y_)
    , width (width_ )
    , height(height_)
    {}

    Rect(Point pos, Size size)
    : x(pos.x)
    , y(pos.y)
    , width (size.width )
    , height(size.height)
    {}

    Point getPos() const
    {
        return Point{x,y};
    }

    Size getSize() const
    {
        return Size{width,height};
    }

}; // struct Rect





} // namespace mxPiglets



