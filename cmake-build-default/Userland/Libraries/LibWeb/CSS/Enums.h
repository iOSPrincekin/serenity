
#pragma once

#include <AK/Optional.h>

namespace Web::CSS {

enum class ValueID;

enum class AlignItems : u8 {
    FlexStart,
    FlexEnd,
    Center,
    Baseline,
    Stretch,
};
Optional<AlignItems> value_id_to_align_items(ValueID);
ValueID to_value_id(AlignItems);
StringView to_string(AlignItems);

enum class BackgroundAttachment : u8 {
    Fixed,
    Local,
    Scroll,
};
Optional<BackgroundAttachment> value_id_to_background_attachment(ValueID);
ValueID to_value_id(BackgroundAttachment);
StringView to_string(BackgroundAttachment);

enum class BackgroundBox : u8 {
    BorderBox,
    ContentBox,
    PaddingBox,
};
Optional<BackgroundBox> value_id_to_background_box(ValueID);
ValueID to_value_id(BackgroundBox);
StringView to_string(BackgroundBox);

enum class BoxSizing : u8 {
    BorderBox,
    ContentBox,
};
Optional<BoxSizing> value_id_to_box_sizing(ValueID);
ValueID to_value_id(BoxSizing);
StringView to_string(BoxSizing);

enum class Clear : u8 {
    None,
    Left,
    Right,
    Both,
};
Optional<Clear> value_id_to_clear(ValueID);
ValueID to_value_id(Clear);
StringView to_string(Clear);

enum class Cursor : u8 {
    Auto,
    Default,
    None,
    ContextMenu,
    Help,
    Pointer,
    Progress,
    Wait,
    Cell,
    Crosshair,
    Text,
    VerticalText,
    Alias,
    Copy,
    Move,
    NoDrop,
    NotAllowed,
    Grab,
    Grabbing,
    EResize,
    NResize,
    NeResize,
    NwResize,
    SResize,
    SeResize,
    SwResize,
    WResize,
    EwResize,
    NsResize,
    NeswResize,
    NwseResize,
    ColResize,
    RowResize,
    AllScroll,
    ZoomIn,
    ZoomOut,
};
Optional<Cursor> value_id_to_cursor(ValueID);
ValueID to_value_id(Cursor);
StringView to_string(Cursor);

enum class FlexDirection : u8 {
    Row,
    RowReverse,
    Column,
    ColumnReverse,
};
Optional<FlexDirection> value_id_to_flex_direction(ValueID);
ValueID to_value_id(FlexDirection);
StringView to_string(FlexDirection);

enum class FlexWrap : u8 {
    Nowrap,
    Wrap,
    WrapReverse,
};
Optional<FlexWrap> value_id_to_flex_wrap(ValueID);
ValueID to_value_id(FlexWrap);
StringView to_string(FlexWrap);

enum class Float : u8 {
    None,
    Left,
    Right,
};
Optional<Float> value_id_to_float(ValueID);
ValueID to_value_id(Float);
StringView to_string(Float);

enum class FontVariant : u8 {
    Normal,
    SmallCaps,
};
Optional<FontVariant> value_id_to_font_variant(ValueID);
ValueID to_value_id(FontVariant);
StringView to_string(FontVariant);

enum class ImageRendering : u8 {
    Auto,
    CrispEdges,
    HighQuality,
    Pixelated,
    Smooth,
};
Optional<ImageRendering> value_id_to_image_rendering(ValueID);
ValueID to_value_id(ImageRendering);
StringView to_string(ImageRendering);

enum class JustifyContent : u8 {
    FlexStart,
    FlexEnd,
    Center,
    SpaceBetween,
    SpaceAround,
};
Optional<JustifyContent> value_id_to_justify_content(ValueID);
ValueID to_value_id(JustifyContent);
StringView to_string(JustifyContent);

enum class LineStyle : u8 {
    None,
    Hidden,
    Dotted,
    Dashed,
    Solid,
    Double,
    Groove,
    Ridge,
    Inset,
    Outset,
};
Optional<LineStyle> value_id_to_line_style(ValueID);
ValueID to_value_id(LineStyle);
StringView to_string(LineStyle);

enum class ListStyleType : u8 {
    Circle,
    Decimal,
    DecimalLeadingZero,
    Disc,
    LowerAlpha,
    LowerLatin,
    LowerRoman,
    None,
    Square,
    UpperAlpha,
    UpperLatin,
    UpperRoman,
};
Optional<ListStyleType> value_id_to_list_style_type(ValueID);
ValueID to_value_id(ListStyleType);
StringView to_string(ListStyleType);

enum class Overflow : u8 {
    Auto,
    Clip,
    Hidden,
    Scroll,
    Visible,
};
Optional<Overflow> value_id_to_overflow(ValueID);
ValueID to_value_id(Overflow);
StringView to_string(Overflow);

enum class PointerEvents : u8 {
    Auto,
    All,
    None,
};
Optional<PointerEvents> value_id_to_pointer_events(ValueID);
ValueID to_value_id(PointerEvents);
StringView to_string(PointerEvents);

enum class Position : u8 {
    Absolute,
    Fixed,
    Relative,
    Static,
    Sticky,
};
Optional<Position> value_id_to_position(ValueID);
ValueID to_value_id(Position);
StringView to_string(Position);

enum class PositionEdge : u8 {
    Left,
    Right,
    Top,
    Bottom,
};
Optional<PositionEdge> value_id_to_position_edge(ValueID);
ValueID to_value_id(PositionEdge);
StringView to_string(PositionEdge);

enum class Repeat : u8 {
    NoRepeat,
    Repeat,
    Round,
    Space,
};
Optional<Repeat> value_id_to_repeat(ValueID);
ValueID to_value_id(Repeat);
StringView to_string(Repeat);

enum class TextAlign : u8 {
    Center,
    Justify,
    Left,
    Right,
    LibwebCenter,
};
Optional<TextAlign> value_id_to_text_align(ValueID);
ValueID to_value_id(TextAlign);
StringView to_string(TextAlign);

enum class TextDecorationLine : u8 {
    Blink,
    LineThrough,
    None,
    Overline,
    Underline,
};
Optional<TextDecorationLine> value_id_to_text_decoration_line(ValueID);
ValueID to_value_id(TextDecorationLine);
StringView to_string(TextDecorationLine);

enum class TextDecorationStyle : u8 {
    Dashed,
    Dotted,
    Double,
    Solid,
    Wavy,
};
Optional<TextDecorationStyle> value_id_to_text_decoration_style(ValueID);
ValueID to_value_id(TextDecorationStyle);
StringView to_string(TextDecorationStyle);

enum class TextJustify : u8 {
    Auto,
    None,
    InterWord,
    InterCharacter,
};
Optional<TextJustify> value_id_to_text_justify(ValueID);
ValueID to_value_id(TextJustify);
StringView to_string(TextJustify);

enum class TextTransform : u8 {
    Capitalize,
    FullSizeKana,
    FullWidth,
    Lowercase,
    None,
    Uppercase,
};
Optional<TextTransform> value_id_to_text_transform(ValueID);
ValueID to_value_id(TextTransform);
StringView to_string(TextTransform);

enum class VerticalAlign : u8 {
    Baseline,
    Bottom,
    Middle,
    Sub,
    Super,
    TextBottom,
    TextTop,
    Top,
};
Optional<VerticalAlign> value_id_to_vertical_align(ValueID);
ValueID to_value_id(VerticalAlign);
StringView to_string(VerticalAlign);

enum class Visibility : u8 {
    Collapse,
    Hidden,
    Visible,
};
Optional<Visibility> value_id_to_visibility(ValueID);
ValueID to_value_id(Visibility);
StringView to_string(Visibility);

enum class WhiteSpace : u8 {
    Normal,
    Nowrap,
    Pre,
    PreLine,
    PreWrap,
};
Optional<WhiteSpace> value_id_to_white_space(ValueID);
ValueID to_value_id(WhiteSpace);
StringView to_string(WhiteSpace);

}
