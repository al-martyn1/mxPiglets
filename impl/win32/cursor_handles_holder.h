#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//

#include "../../enums.h"

//
#include <memory>
#include <string>
#include <exception>
#include <stdexcept>
#include <utility>
#include <unordered_map>


namespace mxPiglets {



class CursorHandlesHolder
{
    // https://learn.microsoft.com/en-us/windows/win32/menurc/cursors

    std::unordered_map<HCURSOR, EStockCursor>   cursorKinds  ; // По хэндлу храним тип курсора
    std::unordered_map<EStockCursor, HCURSOR>   cursorsByKind; // по типу курсора ищем, есть ли уже готовый

    // See also - https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createcursor
    // See also - https://learn.microsoft.com/en-us/windows/win32/menurc/using-cursors

    static
    HCURSOR createCursorHandle(EStockCursor cursorKind)
    {
        auto id = IDC_ARROW; // MAKEINTRESOURCE();
        switch(cursorKind)
        {
            // https://learn.microsoft.com/en-us/windows/win32/menurc/about-cursors
            case EStockCursor::normal        : id = IDC_ARROW; break; // arrow
            case EStockCursor::beam          : id = IDC_IBEAM; break; // textSelect
            case EStockCursor::wait          : id = IDC_WAIT ; break; // busy
            case EStockCursor::cross         : id = IDC_CROSS; break;
            case EStockCursor::upArrow       : id = IDC_UPARROW; break;
            case EStockCursor::handwriting   : id = MAKEINTRESOURCE(32631); break;
            case EStockCursor::resizeWse     : id = IDC_SIZENWSE; break;
            case EStockCursor::resizeEsw     : id = IDC_SIZENESW; break;
            case EStockCursor::resizeWe      : id = IDC_SIZEWE ; break;
            case EStockCursor::resizeNs      : id = IDC_SIZENS ; break;
            case EStockCursor::resizeAll     : id = IDC_SIZEALL; break;
            case EStockCursor::cursorNo      : id = IDC_NO; break; // no
            case EStockCursor::hand          : id = IDC_HAND; break;
            case EStockCursor::appStarting   : id = IDC_APPSTARTING; break; // semiWait
            case EStockCursor::help          : id = IDC_HELP; break;
            case EStockCursor::locationSelect: id = MAKEINTRESOURCE(32671); // IDC_PIN; break; // pin - incompatible with WinXP ???
            case EStockCursor::personSelect  : id = MAKEINTRESOURCE(32672); // IDC_PERSON; break; // person - incompatible with WinXP ???

            //case EStockCursor::windowOriginal: [[fallthrough]];
            case EStockCursor::invalid       : [[fallthrough]];
            case EStockCursor::custom        : [[fallthrough]];
            case EStockCursor::end           : [[fallthrough]];
            
            default:
            {
                // throw std::runtime_error("CursorHandlesHolder::createCursorHandle: invalid cursor kind");
                return (HCURSOR)0; // нахер не нужны исключения
            }
        }

        HCURSOR hCursor = ::LoadCursor(NULL, id);

        if (hCursor==0)
        {
            //throw std::runtime_error("CursorHandlesHolder::createCursorHandle: failed to load stock cursor");
            return (HCURSOR)0; // нахер не нужны исключения
        }

        return hCursor;
    }

public:

    static
    bool isValidStockCursorKind(EStockCursor cursorKind)
    {
        if ( (std::uint32_t)cursorKind >= (std::uint32_t)EStockCursor::normal
          && (std::uint32_t)cursorKind <  (std::uint32_t)EStockCursor::end
           )
        {
            return true;
        }

        return false;
    }

    // Создаёт новый или возвращает существующий
    HCURSOR createStockCursor(EStockCursor cursorKind)
    {

        //TODO: !!! Хорошо бы тут блокирнуть

        if (!isValidStockCursorKind(cursorKind))
        {
            return (HCURSOR)0;
        }

        std::unordered_map<EStockCursor, HCURSOR>::const_iterator it = cursorsByKind.find(cursorKind);
        if (it!=cursorsByKind.end())
        {
            return it->second; // Вернули существующий
        }

        HCURSOR hCursor = createCursorHandle(cursorKind);

        cursorKinds[hCursor]      = cursorKind;
        cursorsByKind[cursorKind] = hCursor;

        return hCursor;
    }

    bool isKnownCursor(HCURSOR hCursor) const
    {
        //TODO: !!! Хорошо бы тут блокирнуть
        std::unordered_map<HCURSOR, EStockCursor>::const_iterator it = cursorKinds.find(hCursor);
        if (it==cursorKinds.end())
        {
            return false;
        }

        return true;
    }

    bool isStockCursor(HCURSOR hCursor) const
    {
        //TODO: !!! Хорошо бы тут блокирнуть
        std::unordered_map<HCURSOR, EStockCursor>::const_iterator it = cursorKinds.find(hCursor);
        if (it==cursorKinds.end())
        {
            return false;
        }

        if (isValidStockCursorKind(it->second))
        {
            return true;
        }

        return false;
    }

    EStockCursor getCursorKind(HCURSOR hCursor) const
    {
        //TODO: !!! Хорошо бы тут блокирнуть
        std::unordered_map<HCURSOR, EStockCursor>::const_iterator it = cursorKinds.find(hCursor);
        if (it==cursorKinds.end())
        {
            return EStockCursor::unknown;
        }
    
        return it->second;
    }

    ~CursorHandlesHolder()
    {
        std::unordered_map<HCURSOR, EStockCursor>::iterator it = cursorKinds.begin();
        for(; it!=cursorKinds.end(); ++it)
        {
            ::DestroyCursor(it->first); // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-destroycursor
        }
    }



}; // class CursorHandlesHolder



inline
CursorHandlesHolder& getCursorHandlesHolder()
{
    static CursorHandlesHolder holder;
    return holder;
}




} // namespace mxPiglets


