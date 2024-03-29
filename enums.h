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



/*! Common control style flags. dialog* and want* flags are not used directly, they are used trough virt fns getDialogResultFlags/getWantKeyFlags, which can be overriden in childs */
enum class ControlStyleFlags : std::uint32_t
{
    invalid                 = (std::uint32_t)(-1),
    unknown                 = (std::uint32_t)(-1),
    none                    = 0x0000,
    noFlags                 = 0x0000,
    paintTransparent        = 0x0001 /*!< When drawing, it does not draw its background, only child controls are drawn */,
    hitTransparent          = 0x0002 /*!< When checking coordinate hits (hit test), if a point does not hits on any of the child controls, then it is not considered a hit on the control */,
    transparentControl      = 0x0003 /*!< Combination of PaintTransparent|HitTransparent flags */,
    group                   = 0x0004 /*!< Starts the control group */,
    groupStart              = 0x0004 /*!< Starts the control group */,
    tabStop                 = 0x0008 /*!< Allow the control to be in tab navigation list */,
    focusLess               = 0x0010 /*!< Control can't own the input focus */,
    cantOwnFocus            = 0x0010 /*!< Control can't own the input focus */,
    controlParent           = 0x0020 /*!< Acts as control container, not a single (possible compaund) control */,
    controlContainer        = 0x0020 /*!< Acts as control container, not a single (possible compaund) control */,
    container               = 0x0020 /*!< Acts as control container, not a single (possible compaund) control */,
    dialogResultNone        = 0x0000 /*!< Clicking/pushing this control don't close the dialog */,
    dialogResultButton      = 0x0400 /*!< (:close) Clicking/pushing this control closes the dialog, and dlgResultCode (EDialogResult) control field used as result code. This control does not have to be an any kind of button. */,
    dlgResultButton         = 0x0400 /*!< (:close) Clicking/pushing this control closes the dialog, and dlgResultCode (EDialogResult) control field used as result code. This control does not have to be an any kind of button. */,
    dialogDefButton         = 0x0800 /*!< (:close, :default-ok) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Enter. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dlgDefButton            = 0x0800 /*!< (:close, :default-ok) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Enter. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dialogCancelButton      = 0x0C00 /*!< (:close, :default-cancel) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Escape. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dlgCancelButton         = 0x0C00 /*!< (:close, :default-cancel) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Escape. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dialogEscButton         = 0x0C00 /*!< (:close, :default-cancel) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Escape. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dlgEscButton            = 0x0C00 /*!< (:close, :default-cancel) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Escape. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dialogEscapeButton      = 0x0C00 /*!< (:close, :default-cancel) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Escape. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dlgEscapeButton         = 0x0C00 /*!< (:close, :default-cancel) If any of window controls have set this flags combination, it's dlgResultCode (EDialogResult) is used to close the dialog while user presses Escape. Only first found control's dlgResultCode with this flag is used. This control does not have to be an any kind of button. */,
    dialogResultFlagsMask   = 0x0C00 /*!< Mask for "dialog*" sub-enum */,
    wantArrows              = 0x1000 /*!< Want arrow (direction) keys press/unpress events */,
    wantChars               = 0x2000 /*!< Want char input messages */,
    wantTab                 = 0x3000 /*!< Want Tab key messages */,
    wantReturn              = 0x4000 /*!< Want Enter key messages */,
    wantCr                  = 0x4000 /*!< Want Enter key messages */,
    wantEscape              = 0x4000 /*!< Want Escape key messages */,
    wantEsc                 = 0x4000 /*!< Want Escape key messages */,
    wantAllKeys             = 0x5000 /*!< Want all keyboard input */,
    wantKeyFlagsMask        = 0xF000 /*!< Mask for "want*" sub-enum */,
    userFirst               = 0x10000 /*!< First user flag value */

}; // enum class ControlStyleFlags : std::uint32_t

MARTY_CPP_MAKE_ENUM_FLAGS(ControlStyleFlags)

MARTY_CPP_ENUM_FLAGS_SERIALIZE_BEGIN( ControlStyleFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::invalid              , "Invalid"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::none                 , "None"               );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "PaintTransparent"   );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::tabStop              , "TabStop"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantChars            , "WantChars"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "DialogResultButton" );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::group                , "Group"              );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "HitTransparent"     );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "TransparentControl" );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "WantAllKeys"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::focusLess            , "FocusLess"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::controlParent        , "ControlParent"      );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "DialogDefButton"    );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "DialogCancelButton" );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantKeyFlagsMask     , "WantKeyFlagsMask"   );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "WantReturn"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "WantArrows"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::wantTab              , "WantTab"            );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStyleFlags::userFirst            , "UserFirst"          );
MARTY_CPP_ENUM_FLAGS_SERIALIZE_END( ControlStyleFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_BEGIN( ControlStyleFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::invalid              , "invalid"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::invalid              , "unknown"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "none"                     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "no-flags"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "dialog_result_none"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "no_flags"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "noflags"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "dialog-result-none"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::none                 , "dialogresultnone"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "paint-transparent"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "paint_transparent"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::paintTransparent     , "painttransparent"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::tabStop              , "tab-stop"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::tabStop              , "tab_stop"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::tabStop              , "tabstop"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantChars            , "want-chars"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantChars            , "want_chars"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantChars            , "wantchars"                );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "dialog-result-button"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "dialogresultbutton"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "dialog_result_button"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "dlg-result-button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "dlg_result_button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogResultButton   , "dlgresultbutton"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "group"                    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "group-start"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "group_start"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::group                , "groupstart"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "hit-transparent"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "hit_transparent"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::hitTransparent       , "hittransparent"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "transparent-control"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "transparent_control"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::transparentControl   , "transparentcontrol"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "want-all-keys"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "want_all_keys"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantAllKeys          , "wantallkeys"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "cant-own-focus"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "cantownfocus"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "focus-less"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "focus_less"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "focusless"                );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::focusLess            , "cant_own_focus"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control-parent"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control_parent"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control_container"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "controlparent"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "control-container"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "controlcontainer"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::controlParent        , "container"                );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "dialog-def-button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "dialog_def_button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "dialogdefbutton"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "dlg-def-button"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "dlg_def_button"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogDefButton      , "dlgdefbutton"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog-cancel-button"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog_cancel_button"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialogcancelbutton"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlg-cancel-button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlg_cancel_button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog-esc-button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog_esc_button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlgcancelbutton"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialogescbutton"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlg_esc_button"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlg-esc-button"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialogresultflagsmask"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlgescbutton"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog_escape_button"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog-escape-button"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialogescapebutton"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlg-escape-button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlgescapebutton"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dlg_escape_button"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog-result-flags-mask" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::dialogCancelButton   , "dialog_result_flags_mask" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantKeyFlagsMask     , "want-key-flags-mask"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantKeyFlagsMask     , "want_key_flags_mask"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantKeyFlagsMask     , "wantkeyflagsmask"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "wantescape"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want-return"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want_return"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "wantreturn"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want-cr"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want-escape"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want_cr"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "wantcr"                   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want_escape"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want-esc"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "want_esc"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantReturn           , "wantesc"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "want-arrows"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "want_arrows"              );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantArrows           , "wantarrows"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantTab              , "want-tab"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantTab              , "want_tab"                 );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::wantTab              , "wanttab"                  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::userFirst            , "user-first"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::userFirst            , "user_first"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStyleFlags::userFirst            , "userfirst"                );
MARTY_CPP_ENUM_FLAGS_DESERIALIZE_END( ControlStyleFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_SERIALIZE_SET(ControlStyleFlags, std::set)

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_SET(ControlStyleFlags, std::set)


enum class ControlStateFlags : std::uint32_t
{
    invalid           = (std::uint32_t)(-1),
    unknown           = (std::uint32_t)(-1),
    none              = 0x0000,
    noFlags           = 0x0000,
    disabled          = 0x0001 /*!< Disabled, can't process any input (keyboard/mouse) (:disabled/:enabled) */,
    grayed            = 0x0002 /*!< Looks grayed, but can process user input (keyboard/mouse) (:grayed) */,
    greyed            = 0x0002 /*!< Looks grayed, but can process user input (keyboard/mouse) (:grayed) */,
    disabledControl   = 0x0003 /*!< Combination of Disabled|Grayed flags */,
    readOnly          = 0x0004 /*!< Not disabled and grayed, looks like regular control, but user can't change control state (:read-only) */,
    hasFocus          = 0x0008 /*!< Control currently owns input focus (=focus) */,
    inFocus           = 0x0008 /*!< Control currently owns input focus (=focus) */,
    groupFocus        = 0x0010 /*!< Control that receives input focus when it goes to this controls group (last focused control in group) (=group-focus) */,
    hover             = 0x0020 /*!< Matches when a user designates an item with a pointing device, such as holding the mouse pointer over the item (=hover) */,
    visited           = 0x0040 /*!< Matches controls that had user interaction (example= links that have been visited) (:visited) */,
    hadFocus          = 0x0080 /*!< Matches elements that had input focus at least one time (=hadfocus) */,
    needRepaint       = 0x0100 /*!< Marked as need repaint after event processing was done */,
    needRedraw        = 0x0100 /*!< Marked as need repaint after event processing was done */,
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
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::readOnly          , "ReadOnly"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::needRepaint       , "NeedRepaint"     );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::groupFocus        , "GroupFocus"      );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::visited           , "Visited"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::hover             , "Hover"           );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::hadFocus          , "HadFocus"        );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( ControlStateFlags::userFirst         , "UserFirst"       );
MARTY_CPP_ENUM_FLAGS_SERIALIZE_END( ControlStateFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_BEGIN( ControlStateFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::invalid           , "invalid"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::invalid           , "unknown"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::grayed            , "grayed"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::grayed            , "greyed"           );
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
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::readOnly          , "read-only"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::readOnly          , "read_only"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::readOnly          , "readonly"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need-redraw"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need-repaint"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need_redraw"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "need_repaint"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "needrepaint"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::needRepaint       , "needredraw"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::groupFocus        , "group-focus"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::groupFocus        , "group_focus"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::groupFocus        , "groupfocus"       );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::visited           , "visited"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hover             , "hover"            );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hadFocus          , "had-focus"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hadFocus          , "had_focus"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( ControlStateFlags::hadFocus          , "hadfocus"         );
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


enum class ETokenType : std::uint16_t
{
    tokenTypeNone   = 0,
    closeDialog     = 256 /*!< pseudo - Clicking/pushing this control closes the dialog, and dlgResultCode (EDialogResult) control field used as result code. This control does not have to be an any kind of button. */,
    defaultOk       = 257 /*!< pseudo - Close control with ok code (when RETURN is pressed) */,
    defaultCancel   = 258 /*!< pseudo - Close control with cancel code (when ESC is pressed) */,
    disabled        = 259 /*!< pseudo - Disabled, can't process any input (keyboard/mouse) */,
    enabled         = 260 /*!< pseudo - Enabled, can process user input (keyboard/mouse) */,
    grayed          = 261 /*!< pseudo - Looks grayed, but can process user input (keyboard/mouse) */,
    readOnly        = 262 /*!< pseudo - Not disabled and grayed, looks like regular control, but user can't change control state */,
    focus           = 263 /*!< pseudo - Control currently owns input focus */,
    groupFocus      = 264 /*!< pseudo - Control that receives input focus when it goes to this controls group (last focused control in group) */,
    hover           = 265 /*!< pseudo - Matches when a user designates an item with a pointing device, such as holding the mouse pointer over the item */,
    visited         = 266 /*!< pseudo - Matches controls that had user interaction (example - links that have been visited) */,
    hadFocus        = 267 /*!< pseudo - Matches elements that had input focus at least one time */,
    normal          = 268 /*!< state - default state of generic control */,
    pressed         = 269 /*!< state - */,
    unpressed       = 270 /*!< state - */,
    checked         = 271 /*!< state - */,
    unchecked       = 272 /*!< state - */,
    checked3        = 273 /*!< state - In third state for 3-state controls */,
    selected        = 274 /*!< state - */,
    unselected      = 275 /*!< state - */,
    selected3       = 276 /*!< state - In third state for 3-state controls */,
    control         = 277 /*!< ctrl - generic control - We use it for basic tests of controls. It can be created, but it makes no sense, it only draws itself and throws messages into the debug output */,
    button          = 278 /*!< ctrl - */,
    pushButton      = 279 /*!< ctrl - */,
    toggleButton    = 280 /*!< ctrl - */,
    checkBox        = 281 /*!< ctrl - */,
    checkBox3       = 282 /*!< ctrl - */,
    radioButton     = 283 /*!< ctrl - */,
    radioButton3    = 284 /*!< ctrl - */,
    label           = 285 /*!< ctrl - */,
    edit            = 286 /*!< ctrl - */,
    listBox         = 287 /*!< ctrl - */,
    dropDownList    = 288 /*!< ctrl - */,
    dropDownEdit    = 289 /*!< ctrl - */

}; // enum class ETokenType : std::uint16_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(ETokenType)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( ETokenType, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::checkBox       , "CheckBox"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::tokenTypeNone  , "TokenTypeNone" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::defaultOk      , "DefaultOk"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::readOnly       , "ReadOnly"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::closeDialog    , "CloseDialog"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::selected       , "Selected"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::defaultCancel  , "DefaultCancel" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::pressed        , "Pressed"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::disabled       , "Disabled"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::enabled        , "Enabled"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::grayed         , "Grayed"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::unselected     , "Unselected"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::focus          , "Focus"         );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::groupFocus     , "GroupFocus"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::visited        , "Visited"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::hover          , "Hover"         );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::hadFocus       , "HadFocus"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::normal         , "Normal"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::dropDownList   , "DropDownList"  );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::unpressed      , "Unpressed"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::checked        , "Checked"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::unchecked      , "Unchecked"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::checked3       , "Checked3"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::selected3      , "Selected3"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::control        , "Control"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::edit           , "Edit"          );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::checkBox3      , "CheckBox3"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::toggleButton   , "ToggleButton"  );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::button         , "Button"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::pushButton     , "PushButton"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::radioButton    , "RadioButton"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::radioButton3   , "RadioButton3"  );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::label          , "Label"         );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::listBox        , "ListBox"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( ETokenType::dropDownEdit   , "DropDownEdit"  );
MARTY_CPP_ENUM_CLASS_SERIALIZE_END( ETokenType, std::map, 1 )

MARTY_CPP_ENUM_CLASS_DESERIALIZE_BEGIN( ETokenType, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checkBox       , "check-box"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checkBox       , "check_box"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checkBox       , "checkbox"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::tokenTypeNone  , "token-type-none" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::tokenTypeNone  , "token_type_none" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::tokenTypeNone  , "tokentypenone"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::defaultOk      , "default-ok"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::defaultOk      , "default_ok"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::defaultOk      , "defaultok"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::readOnly       , "read-only"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::readOnly       , "read_only"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::readOnly       , "readonly"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::closeDialog    , "close-dialog"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::closeDialog    , "close_dialog"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::closeDialog    , "closedialog"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::selected       , "selected"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::defaultCancel  , "default-cancel"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::defaultCancel  , "default_cancel"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::defaultCancel  , "defaultcancel"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::pressed        , "pressed"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::disabled       , "disabled"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::enabled        , "enabled"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::grayed         , "grayed"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::unselected     , "unselected"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::focus          , "focus"           );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::groupFocus     , "group-focus"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::groupFocus     , "group_focus"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::groupFocus     , "groupfocus"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::visited        , "visited"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::hover          , "hover"           );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::hadFocus       , "had-focus"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::hadFocus       , "had_focus"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::hadFocus       , "hadfocus"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::normal         , "normal"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::dropDownList   , "drop-down-list"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::dropDownList   , "drop_down_list"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::dropDownList   , "dropdownlist"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::unpressed      , "unpressed"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checked        , "checked"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::unchecked      , "unchecked"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checked3       , "checked3"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::selected3      , "selected3"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::control        , "control"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::edit           , "edit"            );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checkBox3      , "check-box3"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checkBox3      , "check_box3"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::checkBox3      , "checkbox3"       );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::toggleButton   , "toggle-button"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::toggleButton   , "toggle_button"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::toggleButton   , "togglebutton"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::button         , "button"          );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::pushButton     , "push-button"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::pushButton     , "push_button"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::pushButton     , "pushbutton"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::radioButton    , "radio-button"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::radioButton    , "radio_button"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::radioButton    , "radiobutton"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::radioButton3   , "radio-button3"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::radioButton3   , "radio_button3"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::radioButton3   , "radiobutton3"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::label          , "label"           );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::listBox        , "list-box"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::listBox        , "list_box"        );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::listBox        , "listbox"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::dropDownEdit   , "drop-down-edit"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::dropDownEdit   , "drop_down_edit"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( ETokenType::dropDownEdit   , "dropdownedit"    );
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( ETokenType, std::map, 1 )

} // namespace mxPiglets

