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
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::doubleClick  , "doubleclick" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::invalid      , "invalid"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::invalid      , "unknown"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::released     , "released"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButtonEvent::pressed      , "pressed"     );
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
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::invalid       , "invalid"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::invalid       , "unknown"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::none          , "none"         );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "middlebutton" );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::middleButton  , "midbutton"    );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::leftButton    , "leftbutton"   );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::rightButton   , "rightbutton"  );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton1      , "xbutton1"     );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EMouseButton::xButton2      , "xbutton2"     );
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
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton1Pressed       , "xbutton1pressed"     );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::invalid               , "invalid"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::invalid               , "unknown"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::none                  , "none"                );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "middlebuttonpressed" );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::middleButtonPressed   , "midbuttonpressed"    );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::leftButtonPressed     , "leftbuttonpressed"   );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::rightButtonPressed    , "rightbuttonpressed"  );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::shiftPressed          , "shiftpressed"        );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::controlPressed        , "controlpressed"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( MouseButtonStateFlags::xButton2Pressed       , "xbutton2pressed"     );
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


enum class KeyEventFlags : std::uint32_t
{
    invalid            = (std::uint32_t)(-1),
    unknown            = (std::uint32_t)(-1),
    none               = 0x00,
    noFlags            = 0x00,
    extended           = 0x100,
    extendedKey        = 0x100,
    altDown            = 0x2000,
    repeat             = 0x4000,
    up                 = 0x8000,
    prevKeyStateDown   = 0x10000,
    keyDown            = 0x20000

}; // enum class KeyEventFlags : std::uint32_t

MARTY_CPP_MAKE_ENUM_FLAGS(KeyEventFlags)

MARTY_CPP_ENUM_FLAGS_SERIALIZE_BEGIN( KeyEventFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::keyDown            , "KeyDown"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::up                 , "Up"               );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::altDown            , "AltDown"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::extended           , "Extended"         );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::invalid            , "Invalid"          );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::none               , "None"             );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::repeat             , "Repeat"           );
    MARTY_CPP_ENUM_FLAGS_SERIALIZE_ITEM( KeyEventFlags::prevKeyStateDown   , "PrevKeyStateDown" );
MARTY_CPP_ENUM_FLAGS_SERIALIZE_END( KeyEventFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_BEGIN( KeyEventFlags, std::map, 1 )
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::keyDown            , "keydown"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::up                 , "up"               );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::altDown            , "altdown"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::extended           , "extended"         );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::extended           , "extendedkey"      );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::invalid            , "invalid"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::invalid            , "unknown"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::none               , "none"             );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::none               , "noflags"          );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::repeat             , "repeat"           );
    MARTY_CPP_ENUM_FLAGS_DESERIALIZE_ITEM( KeyEventFlags::prevKeyStateDown   , "prevkeystatedown" );
MARTY_CPP_ENUM_FLAGS_DESERIALIZE_END( KeyEventFlags, std::map, 1 )

MARTY_CPP_ENUM_FLAGS_SERIALIZE_SET(KeyEventFlags, std::set)

MARTY_CPP_ENUM_FLAGS_DESERIALIZE_SET(KeyEventFlags, std::set)

} // namespace mxPiglets

