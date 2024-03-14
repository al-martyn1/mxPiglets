#pragma once

#include "marty_draw_context/draw_context_enums.h"
#include "marty_draw_context/draw_context_types.h"
#include "marty_draw_context/i_animation.h"
#include "marty_draw_context/i_draw_context.h"
#include "marty_draw_context/i_image_list.h"



//----------------------------------------------------------------------------
namespace mxPiglets {



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
typedef    std::uint32_t    timeout_t;

//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
struct Point
{
    int x = 0;
    int y = 0;

}; // struct Point



struct Size
{
    int width  = 0;
    int height = 0;

}; // struct Size



struct Rect
{
    int x = 0;
    int y = 0;
    int width  = 0;
    int height = 0;

    Rect() = default;
    Rect(const Rect &) = default;
    Rect& operator=(const Rect &) = default;
    Rect(Rect &&) = default;
    Rect& operator=(Rect &&) = default;

    Rect(int x_, int y_, int width_, int height_)
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



