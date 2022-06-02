
#pragma once

#include <AK/StringView.h>
#include <AK/Traits.h>

namespace Web::CSS {

enum class ValueID {
    Invalid,

    LibwebCenter,

    LibwebLink,

    LibwebPaletteActiveLink,

    LibwebPaletteActiveWindowBorder1,

    LibwebPaletteActiveWindowBorder2,

    LibwebPaletteActiveWindowTitle,

    LibwebPaletteBase,

    LibwebPaletteBaseText,

    LibwebPaletteButton,

    LibwebPaletteButtonText,

    LibwebPaletteDesktopBackground,

    LibwebPaletteFocusOutline,

    LibwebPaletteHighlightWindowBorder1,

    LibwebPaletteHighlightWindowBorder2,

    LibwebPaletteHighlightWindowTitle,

    LibwebPaletteHoverHighlight,

    LibwebPaletteInactiveSelection,

    LibwebPaletteInactiveSelectionText,

    LibwebPaletteInactiveWindowBorder1,

    LibwebPaletteInactiveWindowBorder2,

    LibwebPaletteInactiveWindowTitle,

    LibwebPaletteLink,

    LibwebPaletteMenuBase,

    LibwebPaletteMenuBaseText,

    LibwebPaletteMenuSelection,

    LibwebPaletteMenuSelectionText,

    LibwebPaletteMenuStripe,

    LibwebPaletteMovingWindowBorder1,

    LibwebPaletteMovingWindowBorder2,

    LibwebPaletteMovingWindowTitle,

    LibwebPaletteRubberBandBorder,

    LibwebPaletteRubberBandFill,

    LibwebPaletteRuler,

    LibwebPaletteRulerActiveText,

    LibwebPaletteRulerBorder,

    LibwebPaletteRulerInactiveText,

    LibwebPaletteSelection,

    LibwebPaletteSelectionText,

    LibwebPaletteSyntaxComment,

    LibwebPaletteSyntaxControlKeyword,

    LibwebPaletteSyntaxIdentifier,

    LibwebPaletteSyntaxKeyword,

    LibwebPaletteSyntaxNumber,

    LibwebPaletteSyntaxOperator,

    LibwebPaletteSyntaxPreprocessorStatement,

    LibwebPaletteSyntaxPreprocessorValue,

    LibwebPaletteSyntaxPunctuation,

    LibwebPaletteSyntaxString,

    LibwebPaletteSyntaxType,

    LibwebPaletteTextCursor,

    LibwebPaletteThreedHighlight,

    LibwebPaletteThreedShadow1,

    LibwebPaletteThreedShadow2,

    LibwebPaletteVisitedLink,

    LibwebPaletteWindow,

    LibwebPaletteWindowText,

    Absolute,

    Active,

    Additive,

    Alias,

    All,

    AllScroll,

    Anywhere,

    Auto,

    Back,

    Baseline,

    Blink,

    Block,

    Bold,

    Bolder,

    BorderBox,

    Both,

    Bottom,

    BreakWord,

    Browser,

    Capitalize,

    Cell,

    Center,

    Circle,

    Clip,

    Coarse,

    ColResize,

    Collapse,

    Column,

    ColumnReverse,

    Contain,

    Content,

    ContentBox,

    Contents,

    ContextMenu,

    Copy,

    Cover,

    CrispEdges,

    Crosshair,

    Currentcolor,

    Cursive,

    Custom,

    Dark,

    Dashed,

    Decimal,

    DecimalLeadingZero,

    Default,

    Disc,

    Distribute,

    Dotted,

    Double,

    EResize,

    Enabled,

    EwResize,

    Fantasy,

    Fast,

    Fine,

    Fixed,

    Flex,

    FlexEnd,

    FlexStart,

    Flow,

    FlowRoot,

    FromFont,

    FullSizeKana,

    FullWidth,

    Fullscreen,

    Grab,

    Grabbing,

    Grid,

    Groove,

    Help,

    Hidden,

    High,

    HighQuality,

    Hover,

    Infinite,

    InitialOnly,

    Inline,

    InlineBlock,

    InlineFlex,

    InlineTable,

    Inset,

    Inside,

    InterCharacter,

    InterWord,

    Interlace,

    Invert,

    Inverted,

    Italic,

    Justify,

    Landscape,

    Large,

    Larger,

    Left,

    Less,

    Light,

    Lighter,

    LineThrough,

    ListItem,

    Local,

    LowerAlpha,

    LowerLatin,

    LowerRoman,

    Lowercase,

    Ltr,

    Medium,

    Middle,

    MinimalUi,

    Monospace,

    More,

    Move,

    NResize,

    NeResize,

    NeswResize,

    NoDrop,

    NoPreference,

    NoRepeat,

    None,

    Normal,

    NotAllowed,

    Nowrap,

    NsResize,

    NwResize,

    NwseResize,

    Oblique,

    Opaque,

    Outset,

    Outside,

    Overline,

    P3,

    PaddingBox,

    Paged,

    Pixelated,

    Pointer,

    Portrait,

    Pre,

    PreLine,

    PreWrap,

    Progress,

    Progressive,

    Rec2020,

    Reduce,

    Relative,

    Repeat,

    RepeatX,

    RepeatY,

    Ridge,

    Right,

    Round,

    Row,

    RowResize,

    RowReverse,

    Rtl,

    Ruby,

    RubyBase,

    RubyBaseContainer,

    RubyText,

    RubyTextContainer,

    RunIn,

    SResize,

    SansSerif,

    Scroll,

    SeResize,

    Separate,

    Serif,

    Slow,

    Small,

    SmallCaps,

    Smaller,

    Smooth,

    Solid,

    Space,

    SpaceAround,

    SpaceBetween,

    Square,

    Srgb,

    Standalone,

    Standard,

    Static,

    Sticky,

    Stretch,

    Sub,

    Subtractive,

    Super,

    SwResize,

    Table,

    TableCaption,

    TableCell,

    TableColumn,

    TableColumnGroup,

    TableFooterGroup,

    TableHeaderGroup,

    TableRow,

    TableRowGroup,

    Text,

    TextBottom,

    TextTop,

    Thick,

    Thin,

    Top,

    UiMonospace,

    UiRounded,

    UiSansSerif,

    UiSerif,

    Underline,

    UpperAlpha,

    UpperLatin,

    UpperRoman,

    Uppercase,

    VerticalText,

    Visible,

    WResize,

    Wait,

    Wavy,

    Wrap,

    WrapReverse,

    XLarge,

    XSmall,

    XxLarge,

    XxSmall,

    XxxLarge,

    ZoomIn,

    ZoomOut,

};

ValueID value_id_from_string(StringView);
const char* string_from_value_id(ValueID);

}

