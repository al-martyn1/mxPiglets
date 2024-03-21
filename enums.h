#pragma once

#include "marty_cpp/marty_enum.h"
#include "marty_cpp/marty_flag_ops.h"
#include "marty_cpp/marty_flags.h"

#include <exception>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>



namespace mxPiglets{

enum class EStockCursor : std::uint32_t
{
    invalid          = (std::uint32_t)(-1),
    unknown          = (std::uint32_t)(-1),
    custom           = 0x00,
    normal           = 0x01,
    arrow            = 0x01,
    beam             = 0x02,
    textSelect       = 0x02,
    wait             = 0x03,
    busy             = 0x03,
    cross            = 0x04,
    upArrow          = 0x05,
    handwriting      = 0x06,
    resizeWse        = 0x07,
    resizeEsw        = 0x08,
    resizeWe         = 0x09,
    resizeNs         = 0x0A,
    resizeAll        = 0x0B,
    cursorNo         = 0x0C,
    no               = 0x0C,
    hand             = 0x0D,
    appStarting      = 0x0E,
    semiWait         = 0x0E,
    help             = 0x0F,
    pin              = 0x10,
    locationSelect   = 0x10,
    person           = 0x11,
    personSelect     = 0x11,
    end              = 0x12

}; // enum class EStockCursor : std::uint32_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(EStockCursor)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( EStockCursor, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::handwriting  , "Handwriting" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::person       , "Person"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::hand         , "Hand"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::wait         , "Wait"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::invalid      , "Invalid"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::custom       , "Custom"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::beam         , "Beam"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::normal       , "Normal"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::cross        , "Cross"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::upArrow      , "UpArrow"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeWse    , "ResizeWse"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeEsw    , "ResizeEsw"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeWe     , "ResizeWe"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeNs     , "ResizeNs"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeAll    , "ResizeAll"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::cursorNo     , "CursorNo"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::appStarting  , "AppStarting" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::help         , "Help"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::pin          , "Pin"         );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::end          , "End"         );
MARTY_CPP_ENUM_CLASS_SERIALIZE_END( EStockCursor, std::map, 1 )

MARTY_CPP_ENUM_CLASS_DESERIALIZE_BEGIN( EStockCursor, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::handwriting  , "handwriting"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::person       , "personselect"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::person       , "person"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::person       , "person-select"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::person       , "person_select"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::hand         , "hand"            );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::wait         , "busy"            );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::wait         , "wait"            );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::invalid      , "invalid"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::invalid      , "unknown"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::custom       , "custom"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::beam         , "beam"            );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::beam         , "text-select"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::beam         , "text_select"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::beam         , "textselect"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::normal       , "normal"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::normal       , "arrow"           );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::cross        , "cross"           );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::upArrow      , "up-arrow"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::upArrow      , "up_arrow"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::upArrow      , "uparrow"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWse    , "resize-wse"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWse    , "resize_wse"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWse    , "resizewse"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeEsw    , "resize-esw"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeEsw    , "resize_esw"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeEsw    , "resizeesw"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWe     , "resize-we"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWe     , "resize_we"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWe     , "resizewe"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeNs     , "resize-ns"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeNs     , "resize_ns"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeNs     , "resizens"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeAll    , "resize-all"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeAll    , "resize_all"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeAll    , "resizeall"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::cursorNo     , "cursor-no"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::cursorNo     , "cursor_no"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::cursorNo     , "cursorno"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::cursorNo     , "no"              );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::appStarting  , "semi-wait"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::appStarting  , "app-starting"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::appStarting  , "semi_wait"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::appStarting  , "app_starting"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::appStarting  , "appstarting"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::appStarting  , "semiwait"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::help         , "help"            );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::pin          , "pin"             );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::pin          , "location-select" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::pin          , "location_select" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::pin          , "locationselect"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::end          , "end"             );
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( EStockCursor, std::map, 1 )


enum class EMouseButtonEvent : std::uint32_t
{
    invalid       = (std::uint32_t)(-1),
    unknown       = (std::uint32_t)(-1),
    released      = 0,
    pressed       = 1,
    doubleClick   = 2

}; // enum class EMouseButtonEvent : std::uint32_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(EMouseButtonEvent)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( EMouseButtonEvent, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButtonEvent::doubleClick  , "DoubleClick" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButtonEvent::invalid      , "Invalid"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButtonEvent::released     , "Released"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButtonEvent::pressed      , "Pressed"     );
MARTY_CPP_ENUM_CLASS_SERIALIZE_END( EMouseButtonEvent, std::map, 1 )

MARTY_CPP_ENUM_CLASS_DESERIALIZE_BEGIN( EMouseButtonEvent, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::doubleClick  , "double-click" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::doubleClick  , "double_click" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::doubleClick  , "doubleclick"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::invalid      , "invalid"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::invalid      , "unknown"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::released     , "released"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::pressed      , "pressed"      );
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( EMouseButtonEvent, std::map, 1 )


enum class EMouseButton : std::uint32_t
{
    invalid        = (std::uint32_t)(-1),
    unknown        = (std::uint32_t)(-1),
    none           = 0,
    leftButton     = 1,
    rightButton    = 2,
    middleButton   = 3,
    midButton      = 3,
    xButton1       = 4,
    xButton2       = 5

}; // enum class EMouseButton : std::uint32_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(EMouseButton)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( EMouseButton, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::invalid       , "Invalid"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::none          , "None"         );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::middleButton  , "MiddleButton" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::leftButton    , "LeftButton"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::rightButton   , "RightButton"  );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::xButton1      , "XButton1"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseButton::xButton2      , "XButton2"     );
MARTY_CPP_ENUM_CLASS_SERIALIZE_END( EMouseButton, std::map, 1 )

MARTY_CPP_ENUM_CLASS_DESERIALIZE_BEGIN( EMouseButton, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::invalid       , "invalid"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::invalid       , "unknown"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::none          , "none"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "middle-button" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "midbutton"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "middle_button" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "mid-button"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "middlebutton"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "mid_button"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::leftButton    , "left-button"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::leftButton    , "left_button"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::leftButton    , "leftbutton"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::rightButton   , "right-button"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::rightButton   , "right_button"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::rightButton   , "rightbutton"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton1      , "x-button1"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton1      , "x_button1"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton1      , "xbutton1"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton2      , "x-button2"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton2      , "x_button2"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton2      , "xbutton2"      );
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( EMouseButton, std::map, 1 )


enum class MouseButtonStateFlags : std::uint32_t
{
    invalid               = (std::uint32_t)(-1),
    unknown               = (std::uint32_t)(-1),
    none                  = 0x00,
    leftButtonPressed     = 0x01,
    rightButtonPressed    = 0x02,
    shiftPressed          = 0x04,
    controlPressed        = 0x08,
    middleButtonPressed   = 0x10,
    midButtonPressed      = 0x10,
    xButton1Pressed       = 0x20,
    xButton2Pressed       = 0x40

}; // enum class MouseButtonStateFlags : std::uint32_t

MARTY_CPP_MAKE_ENUM_FLAGS(MouseButtonStateFlags)

MARTY_CPP_ENUM_FLAGS_SERIALIZE_BEGIN( MouseButtonStateFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::xButton1Pressed       , "XButton1Pressed"     );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::invalid               , "Invalid"             );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::none                  , "None"                );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "MiddleButtonPressed" );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::leftButtonPressed     , "LeftButtonPressed"   );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::rightButtonPressed    , "RightButtonPressed"  );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::shiftPressed          , "ShiftPressed"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::controlPressed        , "ControlPressed"      );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( MouseButtonStateFlags::xButton2Pressed       , "XButton2Pressed"     );
MARTY_CPP_ENUM_FLAGS_SERIALIZE_END( MouseButtonStateFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_BEGIN( MouseButtonStateFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton1Pressed       , "x-button1-pressed"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton1Pressed       , "x_button1_pressed"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton1Pressed       , "xbutton1pressed"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::invalid               , "invalid"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::invalid               , "unknown"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::none                  , "none"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "middle-button-pressed" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "middle_button_pressed" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "middlebuttonpressed"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "mid-button-pressed"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "mid_button_pressed"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "midbuttonpressed"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::leftButtonPressed     , "left-button-pressed"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::leftButtonPressed     , "left_button_pressed"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::leftButtonPressed     , "leftbuttonpressed"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::rightButtonPressed    , "right-button-pressed"  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::rightButtonPressed    , "right_button_pressed"  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::rightButtonPressed    , "rightbuttonpressed"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::shiftPressed          , "shift-pressed"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::shiftPressed          , "shift_pressed"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::shiftPressed          , "shiftpressed"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::controlPressed        , "control-pressed"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::controlPressed        , "control_pressed"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::controlPressed        , "controlpressed"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton2Pressed       , "x-button2-pressed"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton2Pressed       , "x_button2_pressed"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton2Pressed       , "xbutton2pressed"       );
MARTY_CPP_ENUM_FLAGS_DESERIALIZE_END( MouseButtonStateFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_SERIALIZE_SET(MouseButtonStateFlags, std::set)

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_SET(MouseButtonStateFlags, std::set)


enum class EMouseMoveEventType : std::uint32_t
{
    invalid   = (std::uint32_t)(-1),
    unknown   = (std::uint32_t)(-1),
    move      = 0,
    hover     = 1,
    leave     = 2

}; // enum class EMouseMoveEventType : std::uint32_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(EMouseMoveEventType)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( EMouseMoveEventType, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseMoveEventType::leave    , "Leave"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseMoveEventType::invalid  , "Invalid" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseMoveEventType::move     , "Move"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EMouseMoveEventType::hover    , "Hover"   );
MARTY_CPP_ENUM_CLASS_SERIALIZE_END( EMouseMoveEventType, std::map, 1 )

MARTY_CPP_ENUM_CLASS_DESERIALIZE_BEGIN( EMouseMoveEventType, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseMoveEventType::leave    , "leave"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseMoveEventType::invalid  , "invalid" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseMoveEventType::invalid  , "unknown" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseMoveEventType::move     , "move"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseMoveEventType::hover    , "hover"   );
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( EMouseMoveEventType, std::map, 1 )


enum class ControlStyleFlags : std::uint32_t
{
    invalid              = (std::uint32_t)(-1),
    unknown              = (std::uint32_t)(-1),
    none                 = 0x00,
    noFlags              = 0x00,
    paintTransparent     = 0x01 /*!< When drawing, it does not draw its background, only child controls are drawn */,
    hitTransparent       = 0x02 /*!< When checking coordinate hits (hit test), if a point does not hits on any of the child controls, then it is not considered a hit on the control */,
    transparentControl   = 0x03 /*!< PaintTransparent|HitTransparent */,
    group                = 0x04 /*!< Starts the control group */,
    groupStart           = 0x04 /*!< Starts the control group */,
    tabStop              = 0x08 /*!< Allow the control to be in tab navigation list */,
    focusLess            = 0x10 /*!< Control can't own the input focus */,
    cantOwnFocus         = 0x10 /*!< Control can't own the input focus */,
    controlParent        = 0x20 /*!< Acts as control container, not a single (possible compaund) control */,
    controlContainer     = 0x20 /*!< Acts as control container, not a single (possible compaund) control */,
    container            = 0x20 /*!< Acts as control container, not a single (possible compaund) control */,
    wantArrows           = 0x1000 /*!< Want arrow (direction) keys press/unpress events */,
    wantChars            = 0x2000 /*!< Want char input messages */,
    wantTab              = 0x3000 /*!< Want Tab key messages */,
    wantReturn           = 0x4000 /*!< Want Enter key messages */,
    wantAllKeys          = 0x5000 /*!< Want all keyboard input */,
    wantFlagsMask        = 0xF000 /*!< Mask for "want" sub-enum */,
    userFirst            = 0x10000 /*!< First user flag value */

}; // enum class ControlStyleFlags : std::uint32_t

MARTY_CPP_MAKE_ENUM_FLAGS(ControlStyleFlags)

MARTY_CPP_ENUM_FLAGS_SERIALIZE_BEGIN( ControlStyleFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::invalid              , "Invalid"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::none                 , "None"               );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "PaintTransparent"   );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::tabStop              , "TabStop"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantChars            , "WantChars"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::group                , "Group"              );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "HitTransparent"     );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "TransparentControl" );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "WantAllKeys"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::focusLess            , "FocusLess"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::controlParent        , "ControlParent"      );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "WantReturn"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "WantArrows"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantTab              , "WantTab"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantFlagsMask        , "WantFlagsMask"      );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::userFirst            , "UserFirst"          );
MARTY_CPP_ENUM_FLAGS_SERIALIZE_END( ControlStyleFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_BEGIN( ControlStyleFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::invalid              , "invalid"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::invalid              , "unknown"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "none"                );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "no-flags"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "no_flags"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "noflags"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "paint-transparent"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "paint_transparent"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "painttransparent"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::tabStop              , "tab-stop"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::tabStop              , "tab_stop"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::tabStop              , "tabstop"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantChars            , "want-chars"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantChars            , "want_chars"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantChars            , "wantchars"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "group"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "group-start"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "group_start"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "groupstart"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "hit-transparent"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "hit_transparent"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "hittransparent"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "transparent-control" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "transparent_control" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "transparentcontrol"  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "want-all-keys"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "want_all_keys"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "wantallkeys"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "cant-own-focus"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "cantownfocus"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "focus-less"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "focus_less"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "focusless"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "cant_own_focus"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control-parent"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control_parent"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control_container"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "controlparent"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control-container"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "controlcontainer"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "container"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want-return"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want_return"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "wantreturn"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "want-arrows"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "want_arrows"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "wantarrows"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantTab              , "want-tab"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantTab              , "want_tab"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantTab              , "wanttab"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantFlagsMask        , "want-flags-mask"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantFlagsMask        , "want_flags_mask"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantFlagsMask        , "wantflagsmask"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::userFirst            , "user-first"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::userFirst            , "user_first"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::userFirst            , "userfirst"           );
MARTY_CPP_ENUM_FLAGS_DESERIALIZE_END( ControlStyleFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_SERIALIZE_SET(ControlStyleFlags, std::set)

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_SET(ControlStyleFlags, std::set)


enum class ControlStateFlags : std::uint32_t
{
    invalid           = (std::uint32_t)(-1),
    unknown           = (std::uint32_t)(-1),
    none              = 0x00,
    noFlags           = 0x00,
    disabled          = 0x01 /*!< Disabled, can't process any input (keyboard/mouse) */,
    grayed            = 0x02 /*!< Looks grayed, but can process user input (keyboard/mouse) */,
    disabledControl   = 0x03 /*!< Disabled|Grayed */,
    needRepaint       = 0x04 /*!< Marked as need repaint after event processing was done */,
    needRedraw        = 0x04 /*!< Marked as need repaint after event processing was done */,
    hasFocus          = 0x08 /*!< Control currently owns input focus */,
    inFocus           = 0x08 /*!< Control currently owns input focus */,
    groupFocus        = 0x10 /*!< Control that receives input focus when it goes to this controls group (last focused control in group) */,
    userFirst         = 0x10000 /*!< First user flag value */

}; // enum class ControlStateFlags : std::uint32_t

MARTY_CPP_MAKE_ENUM_FLAGS(ControlStateFlags)

MARTY_CPP_ENUM_FLAGS_SERIALIZE_BEGIN( ControlStateFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::invalid           , "Invalid"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::grayed            , "Grayed"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::none              , "None"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::disabled          , "Disabled"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::hasFocus          , "HasFocus"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::disabledControl   , "DisabledControl" );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::needRepaint       , "NeedRepaint"     );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::groupFocus        , "GroupFocus"      );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::userFirst         , "UserFirst"       );
MARTY_CPP_ENUM_FLAGS_SERIALIZE_END( ControlStateFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_BEGIN( ControlStateFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::invalid           , "invalid"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::invalid           , "unknown"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::grayed            , "grayed"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::none              , "none"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::none              , "no-flags"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::none              , "no_flags"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::none              , "noflags"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::disabled          , "disabled"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hasFocus          , "has-focus"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hasFocus          , "has_focus"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hasFocus          , "in_focus"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hasFocus          , "hasfocus"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hasFocus          , "in-focus"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hasFocus          , "infocus"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::disabledControl   , "disabled-control" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::disabledControl   , "disabled_control" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::disabledControl   , "disabledcontrol"  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need-redraw"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need-repaint"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need_redraw"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need_repaint"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "needrepaint"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "needredraw"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::groupFocus        , "group-focus"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::groupFocus        , "group_focus"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::groupFocus        , "groupfocus"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::userFirst         , "user-first"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::userFirst         , "user_first"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::userFirst         , "userfirst"        );
MARTY_CPP_ENUM_FLAGS_DESERIALIZE_END( ControlStateFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_SERIALIZE_SET(ControlStateFlags, std::set)

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_SET(ControlStateFlags, std::set)



/*!  Modal dialogs predefined result codes - see https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox */
enum class EDialogResult : std::uint32_t
{
    invalid     = (std::uint32_t)(-1),
    unknown     = (std::uint32_t)(-1),
    none        = 0,
    ok          = 1 /*!< The OK button was selected. */,
    cancel      = 2 /*!< The Cancel button was selected. */,
    abort       = 3 /*!< The Abort button was selected. */,
    retry       = 4 /*!< The Retry button was selected. */,
    ignore      = 5 /*!< The Ignore button was selected. */,
    yes         = 6 /*!< The Yes button was selected. */,
    no          = 7 /*!< The No button was selected. */,
    tryAgain    = 10 /*!< The Try Again button was selected. */,
    _continue   = 11 /*!< The Continue button was selected. */

}; // enum class EDialogResult : std::uint32_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(EDialogResult)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( EDialogResult, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::invalid    , "Invalid"  );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::yes        , "Yes"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::ignore     , "Ignore"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::none       , "None"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::cancel     , "Cancel"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::ok         , "Ok"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::retry      , "Retry"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::abort      , "Abort"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::no         , "No"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::tryAgain   , "TryAgain" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EDialogResult::_continue  , "Continue" );
MARTY_CPP_ENUM_CLASS_SERIALIZE_END( EDialogResult, std::map, 1 )

MARTY_CPP_ENUM_CLASS_DESERIALIZE_BEGIN( EDialogResult, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::invalid    , "invalid"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::invalid    , "unknown"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::yes        , "yes"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::ignore     , "ignore"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::none       , "none"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::cancel     , "cancel"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::ok         , "ok"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::retry      , "retry"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::abort      , "abort"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::no         , "no"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::tryAgain   , "try-again" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::tryAgain   , "try_again" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::tryAgain   , "tryagain"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EDialogResult::_continue  , "continue"  );
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( EDialogResult, std::map, 1 )

} // namespace mxPiglets

