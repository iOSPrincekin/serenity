
#include <AK/Assertions.h>
#include <LibWeb/CSS/ValueID.h>

namespace Web::CSS {

ValueID value_id_from_string(StringView string)
{

    if (string.equals_ignoring_case("-libweb-center"))
        return ValueID::LibwebCenter;

    if (string.equals_ignoring_case("-libweb-link"))
        return ValueID::LibwebLink;

    if (string.equals_ignoring_case("-libweb-palette-active-link"))
        return ValueID::LibwebPaletteActiveLink;

    if (string.equals_ignoring_case("-libweb-palette-active-window-border1"))
        return ValueID::LibwebPaletteActiveWindowBorder1;

    if (string.equals_ignoring_case("-libweb-palette-active-window-border2"))
        return ValueID::LibwebPaletteActiveWindowBorder2;

    if (string.equals_ignoring_case("-libweb-palette-active-window-title"))
        return ValueID::LibwebPaletteActiveWindowTitle;

    if (string.equals_ignoring_case("-libweb-palette-base"))
        return ValueID::LibwebPaletteBase;

    if (string.equals_ignoring_case("-libweb-palette-base-text"))
        return ValueID::LibwebPaletteBaseText;

    if (string.equals_ignoring_case("-libweb-palette-button"))
        return ValueID::LibwebPaletteButton;

    if (string.equals_ignoring_case("-libweb-palette-button-text"))
        return ValueID::LibwebPaletteButtonText;

    if (string.equals_ignoring_case("-libweb-palette-desktop-background"))
        return ValueID::LibwebPaletteDesktopBackground;

    if (string.equals_ignoring_case("-libweb-palette-focus-outline"))
        return ValueID::LibwebPaletteFocusOutline;

    if (string.equals_ignoring_case("-libweb-palette-highlight-window-border1"))
        return ValueID::LibwebPaletteHighlightWindowBorder1;

    if (string.equals_ignoring_case("-libweb-palette-highlight-window-border2"))
        return ValueID::LibwebPaletteHighlightWindowBorder2;

    if (string.equals_ignoring_case("-libweb-palette-highlight-window-title"))
        return ValueID::LibwebPaletteHighlightWindowTitle;

    if (string.equals_ignoring_case("-libweb-palette-hover-highlight"))
        return ValueID::LibwebPaletteHoverHighlight;

    if (string.equals_ignoring_case("-libweb-palette-inactive-selection"))
        return ValueID::LibwebPaletteInactiveSelection;

    if (string.equals_ignoring_case("-libweb-palette-inactive-selection-text"))
        return ValueID::LibwebPaletteInactiveSelectionText;

    if (string.equals_ignoring_case("-libweb-palette-inactive-window-border1"))
        return ValueID::LibwebPaletteInactiveWindowBorder1;

    if (string.equals_ignoring_case("-libweb-palette-inactive-window-border2"))
        return ValueID::LibwebPaletteInactiveWindowBorder2;

    if (string.equals_ignoring_case("-libweb-palette-inactive-window-title"))
        return ValueID::LibwebPaletteInactiveWindowTitle;

    if (string.equals_ignoring_case("-libweb-palette-link"))
        return ValueID::LibwebPaletteLink;

    if (string.equals_ignoring_case("-libweb-palette-menu-base"))
        return ValueID::LibwebPaletteMenuBase;

    if (string.equals_ignoring_case("-libweb-palette-menu-base-text"))
        return ValueID::LibwebPaletteMenuBaseText;

    if (string.equals_ignoring_case("-libweb-palette-menu-selection"))
        return ValueID::LibwebPaletteMenuSelection;

    if (string.equals_ignoring_case("-libweb-palette-menu-selection-text"))
        return ValueID::LibwebPaletteMenuSelectionText;

    if (string.equals_ignoring_case("-libweb-palette-menu-stripe"))
        return ValueID::LibwebPaletteMenuStripe;

    if (string.equals_ignoring_case("-libweb-palette-moving-window-border1"))
        return ValueID::LibwebPaletteMovingWindowBorder1;

    if (string.equals_ignoring_case("-libweb-palette-moving-window-border2"))
        return ValueID::LibwebPaletteMovingWindowBorder2;

    if (string.equals_ignoring_case("-libweb-palette-moving-window-title"))
        return ValueID::LibwebPaletteMovingWindowTitle;

    if (string.equals_ignoring_case("-libweb-palette-rubber-band-border"))
        return ValueID::LibwebPaletteRubberBandBorder;

    if (string.equals_ignoring_case("-libweb-palette-rubber-band-fill"))
        return ValueID::LibwebPaletteRubberBandFill;

    if (string.equals_ignoring_case("-libweb-palette-ruler"))
        return ValueID::LibwebPaletteRuler;

    if (string.equals_ignoring_case("-libweb-palette-ruler-active-text"))
        return ValueID::LibwebPaletteRulerActiveText;

    if (string.equals_ignoring_case("-libweb-palette-ruler-border"))
        return ValueID::LibwebPaletteRulerBorder;

    if (string.equals_ignoring_case("-libweb-palette-ruler-inactive-text"))
        return ValueID::LibwebPaletteRulerInactiveText;

    if (string.equals_ignoring_case("-libweb-palette-selection"))
        return ValueID::LibwebPaletteSelection;

    if (string.equals_ignoring_case("-libweb-palette-selection-text"))
        return ValueID::LibwebPaletteSelectionText;

    if (string.equals_ignoring_case("-libweb-palette-syntax-comment"))
        return ValueID::LibwebPaletteSyntaxComment;

    if (string.equals_ignoring_case("-libweb-palette-syntax-control-keyword"))
        return ValueID::LibwebPaletteSyntaxControlKeyword;

    if (string.equals_ignoring_case("-libweb-palette-syntax-identifier"))
        return ValueID::LibwebPaletteSyntaxIdentifier;

    if (string.equals_ignoring_case("-libweb-palette-syntax-keyword"))
        return ValueID::LibwebPaletteSyntaxKeyword;

    if (string.equals_ignoring_case("-libweb-palette-syntax-number"))
        return ValueID::LibwebPaletteSyntaxNumber;

    if (string.equals_ignoring_case("-libweb-palette-syntax-operator"))
        return ValueID::LibwebPaletteSyntaxOperator;

    if (string.equals_ignoring_case("-libweb-palette-syntax-preprocessor-statement"))
        return ValueID::LibwebPaletteSyntaxPreprocessorStatement;

    if (string.equals_ignoring_case("-libweb-palette-syntax-preprocessor-value"))
        return ValueID::LibwebPaletteSyntaxPreprocessorValue;

    if (string.equals_ignoring_case("-libweb-palette-syntax-punctuation"))
        return ValueID::LibwebPaletteSyntaxPunctuation;

    if (string.equals_ignoring_case("-libweb-palette-syntax-string"))
        return ValueID::LibwebPaletteSyntaxString;

    if (string.equals_ignoring_case("-libweb-palette-syntax-type"))
        return ValueID::LibwebPaletteSyntaxType;

    if (string.equals_ignoring_case("-libweb-palette-text-cursor"))
        return ValueID::LibwebPaletteTextCursor;

    if (string.equals_ignoring_case("-libweb-palette-threed-highlight"))
        return ValueID::LibwebPaletteThreedHighlight;

    if (string.equals_ignoring_case("-libweb-palette-threed-shadow1"))
        return ValueID::LibwebPaletteThreedShadow1;

    if (string.equals_ignoring_case("-libweb-palette-threed-shadow2"))
        return ValueID::LibwebPaletteThreedShadow2;

    if (string.equals_ignoring_case("-libweb-palette-visited-link"))
        return ValueID::LibwebPaletteVisitedLink;

    if (string.equals_ignoring_case("-libweb-palette-window"))
        return ValueID::LibwebPaletteWindow;

    if (string.equals_ignoring_case("-libweb-palette-window-text"))
        return ValueID::LibwebPaletteWindowText;

    if (string.equals_ignoring_case("absolute"))
        return ValueID::Absolute;

    if (string.equals_ignoring_case("active"))
        return ValueID::Active;

    if (string.equals_ignoring_case("additive"))
        return ValueID::Additive;

    if (string.equals_ignoring_case("alias"))
        return ValueID::Alias;

    if (string.equals_ignoring_case("all"))
        return ValueID::All;

    if (string.equals_ignoring_case("all-scroll"))
        return ValueID::AllScroll;

    if (string.equals_ignoring_case("anywhere"))
        return ValueID::Anywhere;

    if (string.equals_ignoring_case("auto"))
        return ValueID::Auto;

    if (string.equals_ignoring_case("back"))
        return ValueID::Back;

    if (string.equals_ignoring_case("baseline"))
        return ValueID::Baseline;

    if (string.equals_ignoring_case("blink"))
        return ValueID::Blink;

    if (string.equals_ignoring_case("block"))
        return ValueID::Block;

    if (string.equals_ignoring_case("bold"))
        return ValueID::Bold;

    if (string.equals_ignoring_case("bolder"))
        return ValueID::Bolder;

    if (string.equals_ignoring_case("border-box"))
        return ValueID::BorderBox;

    if (string.equals_ignoring_case("both"))
        return ValueID::Both;

    if (string.equals_ignoring_case("bottom"))
        return ValueID::Bottom;

    if (string.equals_ignoring_case("break-word"))
        return ValueID::BreakWord;

    if (string.equals_ignoring_case("browser"))
        return ValueID::Browser;

    if (string.equals_ignoring_case("capitalize"))
        return ValueID::Capitalize;

    if (string.equals_ignoring_case("cell"))
        return ValueID::Cell;

    if (string.equals_ignoring_case("center"))
        return ValueID::Center;

    if (string.equals_ignoring_case("circle"))
        return ValueID::Circle;

    if (string.equals_ignoring_case("clip"))
        return ValueID::Clip;

    if (string.equals_ignoring_case("coarse"))
        return ValueID::Coarse;

    if (string.equals_ignoring_case("col-resize"))
        return ValueID::ColResize;

    if (string.equals_ignoring_case("collapse"))
        return ValueID::Collapse;

    if (string.equals_ignoring_case("column"))
        return ValueID::Column;

    if (string.equals_ignoring_case("column-reverse"))
        return ValueID::ColumnReverse;

    if (string.equals_ignoring_case("contain"))
        return ValueID::Contain;

    if (string.equals_ignoring_case("content"))
        return ValueID::Content;

    if (string.equals_ignoring_case("content-box"))
        return ValueID::ContentBox;

    if (string.equals_ignoring_case("contents"))
        return ValueID::Contents;

    if (string.equals_ignoring_case("context-menu"))
        return ValueID::ContextMenu;

    if (string.equals_ignoring_case("copy"))
        return ValueID::Copy;

    if (string.equals_ignoring_case("cover"))
        return ValueID::Cover;

    if (string.equals_ignoring_case("crisp-edges"))
        return ValueID::CrispEdges;

    if (string.equals_ignoring_case("crosshair"))
        return ValueID::Crosshair;

    if (string.equals_ignoring_case("currentcolor"))
        return ValueID::Currentcolor;

    if (string.equals_ignoring_case("cursive"))
        return ValueID::Cursive;

    if (string.equals_ignoring_case("custom"))
        return ValueID::Custom;

    if (string.equals_ignoring_case("dark"))
        return ValueID::Dark;

    if (string.equals_ignoring_case("dashed"))
        return ValueID::Dashed;

    if (string.equals_ignoring_case("decimal"))
        return ValueID::Decimal;

    if (string.equals_ignoring_case("decimal-leading-zero"))
        return ValueID::DecimalLeadingZero;

    if (string.equals_ignoring_case("default"))
        return ValueID::Default;

    if (string.equals_ignoring_case("disc"))
        return ValueID::Disc;

    if (string.equals_ignoring_case("distribute"))
        return ValueID::Distribute;

    if (string.equals_ignoring_case("dotted"))
        return ValueID::Dotted;

    if (string.equals_ignoring_case("double"))
        return ValueID::Double;

    if (string.equals_ignoring_case("e-resize"))
        return ValueID::EResize;

    if (string.equals_ignoring_case("enabled"))
        return ValueID::Enabled;

    if (string.equals_ignoring_case("ew-resize"))
        return ValueID::EwResize;

    if (string.equals_ignoring_case("fantasy"))
        return ValueID::Fantasy;

    if (string.equals_ignoring_case("fast"))
        return ValueID::Fast;

    if (string.equals_ignoring_case("fine"))
        return ValueID::Fine;

    if (string.equals_ignoring_case("fixed"))
        return ValueID::Fixed;

    if (string.equals_ignoring_case("flex"))
        return ValueID::Flex;

    if (string.equals_ignoring_case("flex-end"))
        return ValueID::FlexEnd;

    if (string.equals_ignoring_case("flex-start"))
        return ValueID::FlexStart;

    if (string.equals_ignoring_case("flow"))
        return ValueID::Flow;

    if (string.equals_ignoring_case("flow-root"))
        return ValueID::FlowRoot;

    if (string.equals_ignoring_case("from-font"))
        return ValueID::FromFont;

    if (string.equals_ignoring_case("full-size-kana"))
        return ValueID::FullSizeKana;

    if (string.equals_ignoring_case("full-width"))
        return ValueID::FullWidth;

    if (string.equals_ignoring_case("fullscreen"))
        return ValueID::Fullscreen;

    if (string.equals_ignoring_case("grab"))
        return ValueID::Grab;

    if (string.equals_ignoring_case("grabbing"))
        return ValueID::Grabbing;

    if (string.equals_ignoring_case("grid"))
        return ValueID::Grid;

    if (string.equals_ignoring_case("groove"))
        return ValueID::Groove;

    if (string.equals_ignoring_case("help"))
        return ValueID::Help;

    if (string.equals_ignoring_case("hidden"))
        return ValueID::Hidden;

    if (string.equals_ignoring_case("high"))
        return ValueID::High;

    if (string.equals_ignoring_case("high-quality"))
        return ValueID::HighQuality;

    if (string.equals_ignoring_case("hover"))
        return ValueID::Hover;

    if (string.equals_ignoring_case("infinite"))
        return ValueID::Infinite;

    if (string.equals_ignoring_case("initial-only"))
        return ValueID::InitialOnly;

    if (string.equals_ignoring_case("inline"))
        return ValueID::Inline;

    if (string.equals_ignoring_case("inline-block"))
        return ValueID::InlineBlock;

    if (string.equals_ignoring_case("inline-flex"))
        return ValueID::InlineFlex;

    if (string.equals_ignoring_case("inline-table"))
        return ValueID::InlineTable;

    if (string.equals_ignoring_case("inset"))
        return ValueID::Inset;

    if (string.equals_ignoring_case("inside"))
        return ValueID::Inside;

    if (string.equals_ignoring_case("inter-character"))
        return ValueID::InterCharacter;

    if (string.equals_ignoring_case("inter-word"))
        return ValueID::InterWord;

    if (string.equals_ignoring_case("interlace"))
        return ValueID::Interlace;

    if (string.equals_ignoring_case("invert"))
        return ValueID::Invert;

    if (string.equals_ignoring_case("inverted"))
        return ValueID::Inverted;

    if (string.equals_ignoring_case("italic"))
        return ValueID::Italic;

    if (string.equals_ignoring_case("justify"))
        return ValueID::Justify;

    if (string.equals_ignoring_case("landscape"))
        return ValueID::Landscape;

    if (string.equals_ignoring_case("large"))
        return ValueID::Large;

    if (string.equals_ignoring_case("larger"))
        return ValueID::Larger;

    if (string.equals_ignoring_case("left"))
        return ValueID::Left;

    if (string.equals_ignoring_case("less"))
        return ValueID::Less;

    if (string.equals_ignoring_case("light"))
        return ValueID::Light;

    if (string.equals_ignoring_case("lighter"))
        return ValueID::Lighter;

    if (string.equals_ignoring_case("line-through"))
        return ValueID::LineThrough;

    if (string.equals_ignoring_case("list-item"))
        return ValueID::ListItem;

    if (string.equals_ignoring_case("local"))
        return ValueID::Local;

    if (string.equals_ignoring_case("lower-alpha"))
        return ValueID::LowerAlpha;

    if (string.equals_ignoring_case("lower-latin"))
        return ValueID::LowerLatin;

    if (string.equals_ignoring_case("lower-roman"))
        return ValueID::LowerRoman;

    if (string.equals_ignoring_case("lowercase"))
        return ValueID::Lowercase;

    if (string.equals_ignoring_case("ltr"))
        return ValueID::Ltr;

    if (string.equals_ignoring_case("medium"))
        return ValueID::Medium;

    if (string.equals_ignoring_case("middle"))
        return ValueID::Middle;

    if (string.equals_ignoring_case("minimal-ui"))
        return ValueID::MinimalUi;

    if (string.equals_ignoring_case("monospace"))
        return ValueID::Monospace;

    if (string.equals_ignoring_case("more"))
        return ValueID::More;

    if (string.equals_ignoring_case("move"))
        return ValueID::Move;

    if (string.equals_ignoring_case("n-resize"))
        return ValueID::NResize;

    if (string.equals_ignoring_case("ne-resize"))
        return ValueID::NeResize;

    if (string.equals_ignoring_case("nesw-resize"))
        return ValueID::NeswResize;

    if (string.equals_ignoring_case("no-drop"))
        return ValueID::NoDrop;

    if (string.equals_ignoring_case("no-preference"))
        return ValueID::NoPreference;

    if (string.equals_ignoring_case("no-repeat"))
        return ValueID::NoRepeat;

    if (string.equals_ignoring_case("none"))
        return ValueID::None;

    if (string.equals_ignoring_case("normal"))
        return ValueID::Normal;

    if (string.equals_ignoring_case("not-allowed"))
        return ValueID::NotAllowed;

    if (string.equals_ignoring_case("nowrap"))
        return ValueID::Nowrap;

    if (string.equals_ignoring_case("ns-resize"))
        return ValueID::NsResize;

    if (string.equals_ignoring_case("nw-resize"))
        return ValueID::NwResize;

    if (string.equals_ignoring_case("nwse-resize"))
        return ValueID::NwseResize;

    if (string.equals_ignoring_case("oblique"))
        return ValueID::Oblique;

    if (string.equals_ignoring_case("opaque"))
        return ValueID::Opaque;

    if (string.equals_ignoring_case("outset"))
        return ValueID::Outset;

    if (string.equals_ignoring_case("outside"))
        return ValueID::Outside;

    if (string.equals_ignoring_case("overline"))
        return ValueID::Overline;

    if (string.equals_ignoring_case("p3"))
        return ValueID::P3;

    if (string.equals_ignoring_case("padding-box"))
        return ValueID::PaddingBox;

    if (string.equals_ignoring_case("paged"))
        return ValueID::Paged;

    if (string.equals_ignoring_case("pixelated"))
        return ValueID::Pixelated;

    if (string.equals_ignoring_case("pointer"))
        return ValueID::Pointer;

    if (string.equals_ignoring_case("portrait"))
        return ValueID::Portrait;

    if (string.equals_ignoring_case("pre"))
        return ValueID::Pre;

    if (string.equals_ignoring_case("pre-line"))
        return ValueID::PreLine;

    if (string.equals_ignoring_case("pre-wrap"))
        return ValueID::PreWrap;

    if (string.equals_ignoring_case("progress"))
        return ValueID::Progress;

    if (string.equals_ignoring_case("progressive"))
        return ValueID::Progressive;

    if (string.equals_ignoring_case("rec2020"))
        return ValueID::Rec2020;

    if (string.equals_ignoring_case("reduce"))
        return ValueID::Reduce;

    if (string.equals_ignoring_case("relative"))
        return ValueID::Relative;

    if (string.equals_ignoring_case("repeat"))
        return ValueID::Repeat;

    if (string.equals_ignoring_case("repeat-x"))
        return ValueID::RepeatX;

    if (string.equals_ignoring_case("repeat-y"))
        return ValueID::RepeatY;

    if (string.equals_ignoring_case("ridge"))
        return ValueID::Ridge;

    if (string.equals_ignoring_case("right"))
        return ValueID::Right;

    if (string.equals_ignoring_case("round"))
        return ValueID::Round;

    if (string.equals_ignoring_case("row"))
        return ValueID::Row;

    if (string.equals_ignoring_case("row-resize"))
        return ValueID::RowResize;

    if (string.equals_ignoring_case("row-reverse"))
        return ValueID::RowReverse;

    if (string.equals_ignoring_case("rtl"))
        return ValueID::Rtl;

    if (string.equals_ignoring_case("ruby"))
        return ValueID::Ruby;

    if (string.equals_ignoring_case("ruby-base"))
        return ValueID::RubyBase;

    if (string.equals_ignoring_case("ruby-base-container"))
        return ValueID::RubyBaseContainer;

    if (string.equals_ignoring_case("ruby-text"))
        return ValueID::RubyText;

    if (string.equals_ignoring_case("ruby-text-container"))
        return ValueID::RubyTextContainer;

    if (string.equals_ignoring_case("run-in"))
        return ValueID::RunIn;

    if (string.equals_ignoring_case("s-resize"))
        return ValueID::SResize;

    if (string.equals_ignoring_case("sans-serif"))
        return ValueID::SansSerif;

    if (string.equals_ignoring_case("scroll"))
        return ValueID::Scroll;

    if (string.equals_ignoring_case("se-resize"))
        return ValueID::SeResize;

    if (string.equals_ignoring_case("separate"))
        return ValueID::Separate;

    if (string.equals_ignoring_case("serif"))
        return ValueID::Serif;

    if (string.equals_ignoring_case("slow"))
        return ValueID::Slow;

    if (string.equals_ignoring_case("small"))
        return ValueID::Small;

    if (string.equals_ignoring_case("small-caps"))
        return ValueID::SmallCaps;

    if (string.equals_ignoring_case("smaller"))
        return ValueID::Smaller;

    if (string.equals_ignoring_case("smooth"))
        return ValueID::Smooth;

    if (string.equals_ignoring_case("solid"))
        return ValueID::Solid;

    if (string.equals_ignoring_case("space"))
        return ValueID::Space;

    if (string.equals_ignoring_case("space-around"))
        return ValueID::SpaceAround;

    if (string.equals_ignoring_case("space-between"))
        return ValueID::SpaceBetween;

    if (string.equals_ignoring_case("square"))
        return ValueID::Square;

    if (string.equals_ignoring_case("srgb"))
        return ValueID::Srgb;

    if (string.equals_ignoring_case("standalone"))
        return ValueID::Standalone;

    if (string.equals_ignoring_case("standard"))
        return ValueID::Standard;

    if (string.equals_ignoring_case("static"))
        return ValueID::Static;

    if (string.equals_ignoring_case("sticky"))
        return ValueID::Sticky;

    if (string.equals_ignoring_case("stretch"))
        return ValueID::Stretch;

    if (string.equals_ignoring_case("sub"))
        return ValueID::Sub;

    if (string.equals_ignoring_case("subtractive"))
        return ValueID::Subtractive;

    if (string.equals_ignoring_case("super"))
        return ValueID::Super;

    if (string.equals_ignoring_case("sw-resize"))
        return ValueID::SwResize;

    if (string.equals_ignoring_case("table"))
        return ValueID::Table;

    if (string.equals_ignoring_case("table-caption"))
        return ValueID::TableCaption;

    if (string.equals_ignoring_case("table-cell"))
        return ValueID::TableCell;

    if (string.equals_ignoring_case("table-column"))
        return ValueID::TableColumn;

    if (string.equals_ignoring_case("table-column-group"))
        return ValueID::TableColumnGroup;

    if (string.equals_ignoring_case("table-footer-group"))
        return ValueID::TableFooterGroup;

    if (string.equals_ignoring_case("table-header-group"))
        return ValueID::TableHeaderGroup;

    if (string.equals_ignoring_case("table-row"))
        return ValueID::TableRow;

    if (string.equals_ignoring_case("table-row-group"))
        return ValueID::TableRowGroup;

    if (string.equals_ignoring_case("text"))
        return ValueID::Text;

    if (string.equals_ignoring_case("text-bottom"))
        return ValueID::TextBottom;

    if (string.equals_ignoring_case("text-top"))
        return ValueID::TextTop;

    if (string.equals_ignoring_case("thick"))
        return ValueID::Thick;

    if (string.equals_ignoring_case("thin"))
        return ValueID::Thin;

    if (string.equals_ignoring_case("top"))
        return ValueID::Top;

    if (string.equals_ignoring_case("ui-monospace"))
        return ValueID::UiMonospace;

    if (string.equals_ignoring_case("ui-rounded"))
        return ValueID::UiRounded;

    if (string.equals_ignoring_case("ui-sans-serif"))
        return ValueID::UiSansSerif;

    if (string.equals_ignoring_case("ui-serif"))
        return ValueID::UiSerif;

    if (string.equals_ignoring_case("underline"))
        return ValueID::Underline;

    if (string.equals_ignoring_case("upper-alpha"))
        return ValueID::UpperAlpha;

    if (string.equals_ignoring_case("upper-latin"))
        return ValueID::UpperLatin;

    if (string.equals_ignoring_case("upper-roman"))
        return ValueID::UpperRoman;

    if (string.equals_ignoring_case("uppercase"))
        return ValueID::Uppercase;

    if (string.equals_ignoring_case("vertical-text"))
        return ValueID::VerticalText;

    if (string.equals_ignoring_case("visible"))
        return ValueID::Visible;

    if (string.equals_ignoring_case("w-resize"))
        return ValueID::WResize;

    if (string.equals_ignoring_case("wait"))
        return ValueID::Wait;

    if (string.equals_ignoring_case("wavy"))
        return ValueID::Wavy;

    if (string.equals_ignoring_case("wrap"))
        return ValueID::Wrap;

    if (string.equals_ignoring_case("wrap-reverse"))
        return ValueID::WrapReverse;

    if (string.equals_ignoring_case("x-large"))
        return ValueID::XLarge;

    if (string.equals_ignoring_case("x-small"))
        return ValueID::XSmall;

    if (string.equals_ignoring_case("xx-large"))
        return ValueID::XxLarge;

    if (string.equals_ignoring_case("xx-small"))
        return ValueID::XxSmall;

    if (string.equals_ignoring_case("xxx-large"))
        return ValueID::XxxLarge;

    if (string.equals_ignoring_case("zoom-in"))
        return ValueID::ZoomIn;

    if (string.equals_ignoring_case("zoom-out"))
        return ValueID::ZoomOut;

    return ValueID::Invalid;
}

const char* string_from_value_id(ValueID value_id) {
    switch (value_id) {

    case ValueID::LibwebCenter:
        return "-libweb-center";
        
    case ValueID::LibwebLink:
        return "-libweb-link";
        
    case ValueID::LibwebPaletteActiveLink:
        return "-libweb-palette-active-link";
        
    case ValueID::LibwebPaletteActiveWindowBorder1:
        return "-libweb-palette-active-window-border1";
        
    case ValueID::LibwebPaletteActiveWindowBorder2:
        return "-libweb-palette-active-window-border2";
        
    case ValueID::LibwebPaletteActiveWindowTitle:
        return "-libweb-palette-active-window-title";
        
    case ValueID::LibwebPaletteBase:
        return "-libweb-palette-base";
        
    case ValueID::LibwebPaletteBaseText:
        return "-libweb-palette-base-text";
        
    case ValueID::LibwebPaletteButton:
        return "-libweb-palette-button";
        
    case ValueID::LibwebPaletteButtonText:
        return "-libweb-palette-button-text";
        
    case ValueID::LibwebPaletteDesktopBackground:
        return "-libweb-palette-desktop-background";
        
    case ValueID::LibwebPaletteFocusOutline:
        return "-libweb-palette-focus-outline";
        
    case ValueID::LibwebPaletteHighlightWindowBorder1:
        return "-libweb-palette-highlight-window-border1";
        
    case ValueID::LibwebPaletteHighlightWindowBorder2:
        return "-libweb-palette-highlight-window-border2";
        
    case ValueID::LibwebPaletteHighlightWindowTitle:
        return "-libweb-palette-highlight-window-title";
        
    case ValueID::LibwebPaletteHoverHighlight:
        return "-libweb-palette-hover-highlight";
        
    case ValueID::LibwebPaletteInactiveSelection:
        return "-libweb-palette-inactive-selection";
        
    case ValueID::LibwebPaletteInactiveSelectionText:
        return "-libweb-palette-inactive-selection-text";
        
    case ValueID::LibwebPaletteInactiveWindowBorder1:
        return "-libweb-palette-inactive-window-border1";
        
    case ValueID::LibwebPaletteInactiveWindowBorder2:
        return "-libweb-palette-inactive-window-border2";
        
    case ValueID::LibwebPaletteInactiveWindowTitle:
        return "-libweb-palette-inactive-window-title";
        
    case ValueID::LibwebPaletteLink:
        return "-libweb-palette-link";
        
    case ValueID::LibwebPaletteMenuBase:
        return "-libweb-palette-menu-base";
        
    case ValueID::LibwebPaletteMenuBaseText:
        return "-libweb-palette-menu-base-text";
        
    case ValueID::LibwebPaletteMenuSelection:
        return "-libweb-palette-menu-selection";
        
    case ValueID::LibwebPaletteMenuSelectionText:
        return "-libweb-palette-menu-selection-text";
        
    case ValueID::LibwebPaletteMenuStripe:
        return "-libweb-palette-menu-stripe";
        
    case ValueID::LibwebPaletteMovingWindowBorder1:
        return "-libweb-palette-moving-window-border1";
        
    case ValueID::LibwebPaletteMovingWindowBorder2:
        return "-libweb-palette-moving-window-border2";
        
    case ValueID::LibwebPaletteMovingWindowTitle:
        return "-libweb-palette-moving-window-title";
        
    case ValueID::LibwebPaletteRubberBandBorder:
        return "-libweb-palette-rubber-band-border";
        
    case ValueID::LibwebPaletteRubberBandFill:
        return "-libweb-palette-rubber-band-fill";
        
    case ValueID::LibwebPaletteRuler:
        return "-libweb-palette-ruler";
        
    case ValueID::LibwebPaletteRulerActiveText:
        return "-libweb-palette-ruler-active-text";
        
    case ValueID::LibwebPaletteRulerBorder:
        return "-libweb-palette-ruler-border";
        
    case ValueID::LibwebPaletteRulerInactiveText:
        return "-libweb-palette-ruler-inactive-text";
        
    case ValueID::LibwebPaletteSelection:
        return "-libweb-palette-selection";
        
    case ValueID::LibwebPaletteSelectionText:
        return "-libweb-palette-selection-text";
        
    case ValueID::LibwebPaletteSyntaxComment:
        return "-libweb-palette-syntax-comment";
        
    case ValueID::LibwebPaletteSyntaxControlKeyword:
        return "-libweb-palette-syntax-control-keyword";
        
    case ValueID::LibwebPaletteSyntaxIdentifier:
        return "-libweb-palette-syntax-identifier";
        
    case ValueID::LibwebPaletteSyntaxKeyword:
        return "-libweb-palette-syntax-keyword";
        
    case ValueID::LibwebPaletteSyntaxNumber:
        return "-libweb-palette-syntax-number";
        
    case ValueID::LibwebPaletteSyntaxOperator:
        return "-libweb-palette-syntax-operator";
        
    case ValueID::LibwebPaletteSyntaxPreprocessorStatement:
        return "-libweb-palette-syntax-preprocessor-statement";
        
    case ValueID::LibwebPaletteSyntaxPreprocessorValue:
        return "-libweb-palette-syntax-preprocessor-value";
        
    case ValueID::LibwebPaletteSyntaxPunctuation:
        return "-libweb-palette-syntax-punctuation";
        
    case ValueID::LibwebPaletteSyntaxString:
        return "-libweb-palette-syntax-string";
        
    case ValueID::LibwebPaletteSyntaxType:
        return "-libweb-palette-syntax-type";
        
    case ValueID::LibwebPaletteTextCursor:
        return "-libweb-palette-text-cursor";
        
    case ValueID::LibwebPaletteThreedHighlight:
        return "-libweb-palette-threed-highlight";
        
    case ValueID::LibwebPaletteThreedShadow1:
        return "-libweb-palette-threed-shadow1";
        
    case ValueID::LibwebPaletteThreedShadow2:
        return "-libweb-palette-threed-shadow2";
        
    case ValueID::LibwebPaletteVisitedLink:
        return "-libweb-palette-visited-link";
        
    case ValueID::LibwebPaletteWindow:
        return "-libweb-palette-window";
        
    case ValueID::LibwebPaletteWindowText:
        return "-libweb-palette-window-text";
        
    case ValueID::Absolute:
        return "absolute";
        
    case ValueID::Active:
        return "active";
        
    case ValueID::Additive:
        return "additive";
        
    case ValueID::Alias:
        return "alias";
        
    case ValueID::All:
        return "all";
        
    case ValueID::AllScroll:
        return "all-scroll";
        
    case ValueID::Anywhere:
        return "anywhere";
        
    case ValueID::Auto:
        return "auto";
        
    case ValueID::Back:
        return "back";
        
    case ValueID::Baseline:
        return "baseline";
        
    case ValueID::Blink:
        return "blink";
        
    case ValueID::Block:
        return "block";
        
    case ValueID::Bold:
        return "bold";
        
    case ValueID::Bolder:
        return "bolder";
        
    case ValueID::BorderBox:
        return "border-box";
        
    case ValueID::Both:
        return "both";
        
    case ValueID::Bottom:
        return "bottom";
        
    case ValueID::BreakWord:
        return "break-word";
        
    case ValueID::Browser:
        return "browser";
        
    case ValueID::Capitalize:
        return "capitalize";
        
    case ValueID::Cell:
        return "cell";
        
    case ValueID::Center:
        return "center";
        
    case ValueID::Circle:
        return "circle";
        
    case ValueID::Clip:
        return "clip";
        
    case ValueID::Coarse:
        return "coarse";
        
    case ValueID::ColResize:
        return "col-resize";
        
    case ValueID::Collapse:
        return "collapse";
        
    case ValueID::Column:
        return "column";
        
    case ValueID::ColumnReverse:
        return "column-reverse";
        
    case ValueID::Contain:
        return "contain";
        
    case ValueID::Content:
        return "content";
        
    case ValueID::ContentBox:
        return "content-box";
        
    case ValueID::Contents:
        return "contents";
        
    case ValueID::ContextMenu:
        return "context-menu";
        
    case ValueID::Copy:
        return "copy";
        
    case ValueID::Cover:
        return "cover";
        
    case ValueID::CrispEdges:
        return "crisp-edges";
        
    case ValueID::Crosshair:
        return "crosshair";
        
    case ValueID::Currentcolor:
        return "currentcolor";
        
    case ValueID::Cursive:
        return "cursive";
        
    case ValueID::Custom:
        return "custom";
        
    case ValueID::Dark:
        return "dark";
        
    case ValueID::Dashed:
        return "dashed";
        
    case ValueID::Decimal:
        return "decimal";
        
    case ValueID::DecimalLeadingZero:
        return "decimal-leading-zero";
        
    case ValueID::Default:
        return "default";
        
    case ValueID::Disc:
        return "disc";
        
    case ValueID::Distribute:
        return "distribute";
        
    case ValueID::Dotted:
        return "dotted";
        
    case ValueID::Double:
        return "double";
        
    case ValueID::EResize:
        return "e-resize";
        
    case ValueID::Enabled:
        return "enabled";
        
    case ValueID::EwResize:
        return "ew-resize";
        
    case ValueID::Fantasy:
        return "fantasy";
        
    case ValueID::Fast:
        return "fast";
        
    case ValueID::Fine:
        return "fine";
        
    case ValueID::Fixed:
        return "fixed";
        
    case ValueID::Flex:
        return "flex";
        
    case ValueID::FlexEnd:
        return "flex-end";
        
    case ValueID::FlexStart:
        return "flex-start";
        
    case ValueID::Flow:
        return "flow";
        
    case ValueID::FlowRoot:
        return "flow-root";
        
    case ValueID::FromFont:
        return "from-font";
        
    case ValueID::FullSizeKana:
        return "full-size-kana";
        
    case ValueID::FullWidth:
        return "full-width";
        
    case ValueID::Fullscreen:
        return "fullscreen";
        
    case ValueID::Grab:
        return "grab";
        
    case ValueID::Grabbing:
        return "grabbing";
        
    case ValueID::Grid:
        return "grid";
        
    case ValueID::Groove:
        return "groove";
        
    case ValueID::Help:
        return "help";
        
    case ValueID::Hidden:
        return "hidden";
        
    case ValueID::High:
        return "high";
        
    case ValueID::HighQuality:
        return "high-quality";
        
    case ValueID::Hover:
        return "hover";
        
    case ValueID::Infinite:
        return "infinite";
        
    case ValueID::InitialOnly:
        return "initial-only";
        
    case ValueID::Inline:
        return "inline";
        
    case ValueID::InlineBlock:
        return "inline-block";
        
    case ValueID::InlineFlex:
        return "inline-flex";
        
    case ValueID::InlineTable:
        return "inline-table";
        
    case ValueID::Inset:
        return "inset";
        
    case ValueID::Inside:
        return "inside";
        
    case ValueID::InterCharacter:
        return "inter-character";
        
    case ValueID::InterWord:
        return "inter-word";
        
    case ValueID::Interlace:
        return "interlace";
        
    case ValueID::Invert:
        return "invert";
        
    case ValueID::Inverted:
        return "inverted";
        
    case ValueID::Italic:
        return "italic";
        
    case ValueID::Justify:
        return "justify";
        
    case ValueID::Landscape:
        return "landscape";
        
    case ValueID::Large:
        return "large";
        
    case ValueID::Larger:
        return "larger";
        
    case ValueID::Left:
        return "left";
        
    case ValueID::Less:
        return "less";
        
    case ValueID::Light:
        return "light";
        
    case ValueID::Lighter:
        return "lighter";
        
    case ValueID::LineThrough:
        return "line-through";
        
    case ValueID::ListItem:
        return "list-item";
        
    case ValueID::Local:
        return "local";
        
    case ValueID::LowerAlpha:
        return "lower-alpha";
        
    case ValueID::LowerLatin:
        return "lower-latin";
        
    case ValueID::LowerRoman:
        return "lower-roman";
        
    case ValueID::Lowercase:
        return "lowercase";
        
    case ValueID::Ltr:
        return "ltr";
        
    case ValueID::Medium:
        return "medium";
        
    case ValueID::Middle:
        return "middle";
        
    case ValueID::MinimalUi:
        return "minimal-ui";
        
    case ValueID::Monospace:
        return "monospace";
        
    case ValueID::More:
        return "more";
        
    case ValueID::Move:
        return "move";
        
    case ValueID::NResize:
        return "n-resize";
        
    case ValueID::NeResize:
        return "ne-resize";
        
    case ValueID::NeswResize:
        return "nesw-resize";
        
    case ValueID::NoDrop:
        return "no-drop";
        
    case ValueID::NoPreference:
        return "no-preference";
        
    case ValueID::NoRepeat:
        return "no-repeat";
        
    case ValueID::None:
        return "none";
        
    case ValueID::Normal:
        return "normal";
        
    case ValueID::NotAllowed:
        return "not-allowed";
        
    case ValueID::Nowrap:
        return "nowrap";
        
    case ValueID::NsResize:
        return "ns-resize";
        
    case ValueID::NwResize:
        return "nw-resize";
        
    case ValueID::NwseResize:
        return "nwse-resize";
        
    case ValueID::Oblique:
        return "oblique";
        
    case ValueID::Opaque:
        return "opaque";
        
    case ValueID::Outset:
        return "outset";
        
    case ValueID::Outside:
        return "outside";
        
    case ValueID::Overline:
        return "overline";
        
    case ValueID::P3:
        return "p3";
        
    case ValueID::PaddingBox:
        return "padding-box";
        
    case ValueID::Paged:
        return "paged";
        
    case ValueID::Pixelated:
        return "pixelated";
        
    case ValueID::Pointer:
        return "pointer";
        
    case ValueID::Portrait:
        return "portrait";
        
    case ValueID::Pre:
        return "pre";
        
    case ValueID::PreLine:
        return "pre-line";
        
    case ValueID::PreWrap:
        return "pre-wrap";
        
    case ValueID::Progress:
        return "progress";
        
    case ValueID::Progressive:
        return "progressive";
        
    case ValueID::Rec2020:
        return "rec2020";
        
    case ValueID::Reduce:
        return "reduce";
        
    case ValueID::Relative:
        return "relative";
        
    case ValueID::Repeat:
        return "repeat";
        
    case ValueID::RepeatX:
        return "repeat-x";
        
    case ValueID::RepeatY:
        return "repeat-y";
        
    case ValueID::Ridge:
        return "ridge";
        
    case ValueID::Right:
        return "right";
        
    case ValueID::Round:
        return "round";
        
    case ValueID::Row:
        return "row";
        
    case ValueID::RowResize:
        return "row-resize";
        
    case ValueID::RowReverse:
        return "row-reverse";
        
    case ValueID::Rtl:
        return "rtl";
        
    case ValueID::Ruby:
        return "ruby";
        
    case ValueID::RubyBase:
        return "ruby-base";
        
    case ValueID::RubyBaseContainer:
        return "ruby-base-container";
        
    case ValueID::RubyText:
        return "ruby-text";
        
    case ValueID::RubyTextContainer:
        return "ruby-text-container";
        
    case ValueID::RunIn:
        return "run-in";
        
    case ValueID::SResize:
        return "s-resize";
        
    case ValueID::SansSerif:
        return "sans-serif";
        
    case ValueID::Scroll:
        return "scroll";
        
    case ValueID::SeResize:
        return "se-resize";
        
    case ValueID::Separate:
        return "separate";
        
    case ValueID::Serif:
        return "serif";
        
    case ValueID::Slow:
        return "slow";
        
    case ValueID::Small:
        return "small";
        
    case ValueID::SmallCaps:
        return "small-caps";
        
    case ValueID::Smaller:
        return "smaller";
        
    case ValueID::Smooth:
        return "smooth";
        
    case ValueID::Solid:
        return "solid";
        
    case ValueID::Space:
        return "space";
        
    case ValueID::SpaceAround:
        return "space-around";
        
    case ValueID::SpaceBetween:
        return "space-between";
        
    case ValueID::Square:
        return "square";
        
    case ValueID::Srgb:
        return "srgb";
        
    case ValueID::Standalone:
        return "standalone";
        
    case ValueID::Standard:
        return "standard";
        
    case ValueID::Static:
        return "static";
        
    case ValueID::Sticky:
        return "sticky";
        
    case ValueID::Stretch:
        return "stretch";
        
    case ValueID::Sub:
        return "sub";
        
    case ValueID::Subtractive:
        return "subtractive";
        
    case ValueID::Super:
        return "super";
        
    case ValueID::SwResize:
        return "sw-resize";
        
    case ValueID::Table:
        return "table";
        
    case ValueID::TableCaption:
        return "table-caption";
        
    case ValueID::TableCell:
        return "table-cell";
        
    case ValueID::TableColumn:
        return "table-column";
        
    case ValueID::TableColumnGroup:
        return "table-column-group";
        
    case ValueID::TableFooterGroup:
        return "table-footer-group";
        
    case ValueID::TableHeaderGroup:
        return "table-header-group";
        
    case ValueID::TableRow:
        return "table-row";
        
    case ValueID::TableRowGroup:
        return "table-row-group";
        
    case ValueID::Text:
        return "text";
        
    case ValueID::TextBottom:
        return "text-bottom";
        
    case ValueID::TextTop:
        return "text-top";
        
    case ValueID::Thick:
        return "thick";
        
    case ValueID::Thin:
        return "thin";
        
    case ValueID::Top:
        return "top";
        
    case ValueID::UiMonospace:
        return "ui-monospace";
        
    case ValueID::UiRounded:
        return "ui-rounded";
        
    case ValueID::UiSansSerif:
        return "ui-sans-serif";
        
    case ValueID::UiSerif:
        return "ui-serif";
        
    case ValueID::Underline:
        return "underline";
        
    case ValueID::UpperAlpha:
        return "upper-alpha";
        
    case ValueID::UpperLatin:
        return "upper-latin";
        
    case ValueID::UpperRoman:
        return "upper-roman";
        
    case ValueID::Uppercase:
        return "uppercase";
        
    case ValueID::VerticalText:
        return "vertical-text";
        
    case ValueID::Visible:
        return "visible";
        
    case ValueID::WResize:
        return "w-resize";
        
    case ValueID::Wait:
        return "wait";
        
    case ValueID::Wavy:
        return "wavy";
        
    case ValueID::Wrap:
        return "wrap";
        
    case ValueID::WrapReverse:
        return "wrap-reverse";
        
    case ValueID::XLarge:
        return "x-large";
        
    case ValueID::XSmall:
        return "x-small";
        
    case ValueID::XxLarge:
        return "xx-large";
        
    case ValueID::XxSmall:
        return "xx-small";
        
    case ValueID::XxxLarge:
        return "xxx-large";
        
    case ValueID::ZoomIn:
        return "zoom-in";
        
    case ValueID::ZoomOut:
        return "zoom-out";
        
    default:
        return "(invalid CSS::ValueID)";
    }
}

} // namespace Web::CSS
