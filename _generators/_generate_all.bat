@set UINT8=--underlaying-type=std::uint8_t
@set UINT16=--underlaying-type=std::uint16_t
@set UINT32=--underlaying-type=std::uint32_t
@set INT=--underlaying-type=int

@set HEX2=--hex-width=2
@set HEX4=--hex-width=4
@set HEX6=--hex-width=6
@set HEX8=--hex-width=8

@rem set EXTRA=--enum-flags=extra
@rem same but more detailed
@set FLAGENUM_EXTRA=--enum-flags=serialize-set,deserialize-set

@set FLAGS=--enum-flags=flags
@set DECL=--enum-flags=type-decl
@set CLS=--enum-flags=enum-class
@set DECLCLS=--enum-flags=type-decl,enum-class
@set FMTHEX=--enum-flags=fmt-hex
@set SERIALIZE=--enum-flags=serialize,deserialize,lowercase

@set VALUES_CAMEL=--enum-values-style=CamelStyle
@set VALUES_PASCAL=--enum-values-style=PascalStyle 
@set SERIALIZE_PASCAL=--serialize-style=PascalStyle 


@set TPL_OVERRIDE=--override-template-parameter=EnumNameFormat:$(ENAMNAME)
@set GEN_OPTS=--enum-values-style=CamelStyle


@rem Samples

@set VERTALIGN_GEN_FLAGS=--enum-flags=0 --enum-flags=type-decl,serialize,deserialize,lowercase,enum-class,fmt-hex %VALUES_CAMEL% %SERIALIZE_PASCAL%
@set VERTALIGN_DEF=invalid,alignInvalid=-1;top,alignTop=0;center,alignCenter;bottom,alignBottom

@set FONTSTYLEFLAGS_GEN_FLAGS=        --enum-flags=0 --enum-flags=type-decl,serialize,deserialize,lowercase,enum-class,flags,fmt-hex %VALUES_CAMEL% %SERIALIZE_PASCAL% %FLAGENUM_EXTRA%
@set FONTSTYLEFLAGS_DEF=invalid=-1;normal,none=0;italic,oblique=1;underlined=2;strikeout=4;


@rem Combat enums

@rem https://learn.microsoft.com/en-us/windows/win32/menurc/about-cursors
@rem Value Meaning
@rem IDC_ARROW         MAKEINTRESOURCE(32512)    Normal select
@rem IDC_IBEAM         MAKEINTRESOURCE(32513)    Text select
@rem IDC_WAIT          MAKEINTRESOURCE(32514)    Busy
@rem IDC_CROSS         MAKEINTRESOURCE(32515)    Precision select
@rem IDC_UPARROW       MAKEINTRESOURCE(32516)    Alternate select
@rem No ID             MAKEINTRESOURCE(32631)    Handwriting
@rem IDC_SIZENWSE      MAKEINTRESOURCE(32642)    Diagonal resize 1
@rem IDC_SIZENESW      MAKEINTRESOURCE(32643)    Diagonal resize 2
@rem IDC_SIZEWE        MAKEINTRESOURCE(32644)    Horizontal resize
@rem IDC_SIZENS        MAKEINTRESOURCE(32645)    Vertical resize
@rem IDC_SIZEALL       MAKEINTRESOURCE(32646)    Move
@rem IDC_NO            MAKEINTRESOURCE(32648)    Unavailable
@rem IDC_HAND          MAKEINTRESOURCE(32649)    Link select
@rem IDC_APPSTARTING   MAKEINTRESOURCE(32650)    Working in background
@rem IDC_HELP          MAKEINTRESOURCE(32651)    Help select
@rem IDC_PIN           MAKEINTRESOURCE(32671)    Location select
@rem IDC_PERSON        MAKEINTRESOURCE(32672)    Person select

@set STOCKCURSOR_GEN_FLAGS=--enum-flags=0 --enum-flags=type-decl,serialize,deserialize,lowercase,enum-class,fmt-hex %VALUES_CAMEL% 
@rem %SERIALIZE_PASCAL%
@set STOCKCURSOR_DEF=invalid,unknown=-1;normal,arrow=0;beam,textSelect=1;wait,busy;cross;upArrow;handwriting;resizeWse;resizeEsw;resizeWe;resizeNs;resizeAll;cursorNo,no;hand;appStarting,semiWait;help;pin,locationSelect;person,personSelect



@rem  %TPL_OVERRIDE%

umba-enum-gen %GEN_OPTS% %HEX2% ^
%STOCKCURSOR_GEN_FLAGS%                  %UINT32% -E=StockCursor                        -F=%STOCKCURSOR_DEF%               ^
..\enums.h

