#pragma once

#include "types.h"
//

namespace mxPiglets {


struct IControl;

struct IControlPainter
{
    // Отрисовка контрола. Отрисовка контрола pCanvas 
    virtual void paintControl(ICanvas *pCanvas, IControl *pControl) = 0;

}; // struct IControlPainter


} // namespace mxPiglets


