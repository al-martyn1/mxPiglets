#pragma once

#include "types.h"
//
#include "i_control_painter.h"

namespace mxPiglets {


struct IControl;

struct IControlPainterFactory
{
    // Отрисовка контрола. Отрисовка контрола pCanvas 
    virtual std::shared_ptr<IControlPainter> getControlPainter(IControl *pControl) = 0;

}; // struct IControlPainterFactory


} // namespace mxPiglets


