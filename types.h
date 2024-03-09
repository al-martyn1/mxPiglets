#pragma once

namespace mxPiglets {


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



