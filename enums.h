#pragma once

#include "marty_cpp/marty_enum.h"

#include <exception>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>



namespace mxPiglets{

enum class EStockCursor : std::uint32_t
{
    invalid          = (std::uint32_t)(-1),
    unknown          = (std::uint32_t)(-1),
    normal           = 0x00,
    arrow            = 0x00,
    beam             = 0x01,
    textSelect       = 0x01,
    wait             = 0x02,
    busy             = 0x02,
    cross            = 0x03,
    upArrow          = 0x04,
    handwriting      = 0x05,
    resizeWse        = 0x06,
    resizeEsw        = 0x07,
    resizeWe         = 0x08,
    resizeNs         = 0x09,
    resizeAll        = 0x0A,
    cursorNo         = 0x0B,
    no               = 0x0B,
    hand             = 0x0C,
    appStarting      = 0x0D,
    semiWait         = 0x0D,
    help             = 0x0E,
    pin              = 0x0F,
    locationSelect   = 0x0F,
    person           = 0x10,
    personSelect     = 0x10

}; // enum class EStockCursor : std::uint32_t

MARTY_CPP_MAKE_ENUM_IS_FLAGS_FOR_NON_FLAGS_ENUM(EStockCursor)

MARTY_CPP_ENUM_CLASS_SERIALIZE_BEGIN( EStockCursor, std::map, 1 )
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::handwriting  , "Handwriting" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::person       , "Person"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::hand         , "Hand"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::wait         , "Wait"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::invalid      , "Invalid"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeWse    , "ResizeWse"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::beam         , "Beam"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::normal       , "Normal"      );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::cross        , "Cross"       );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::upArrow      , "UpArrow"     );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeEsw    , "ResizeEsw"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeWe     , "ResizeWe"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeNs     , "ResizeNs"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::resizeAll    , "ResizeAll"   );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::cursorNo     , "CursorNo"    );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::appStarting  , "AppStarting" );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::help         , "Help"        );
    MARTY_CPP_ENUM_CLASS_SERIALIZE_ITEM( EStockCursor::pin          , "Pin"         );
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
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWse    , "resize-wse"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWse    , "resize_wse"      );
    MARTY_CPP_ENUM_CLASS_DESERIALIZE_ITEM( EStockCursor::resizeWse    , "resizewse"       );
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
MARTY_CPP_ENUM_CLASS_DESERIALIZE_END( EStockCursor, std::map, 1 )

} // namespace mxPiglets

