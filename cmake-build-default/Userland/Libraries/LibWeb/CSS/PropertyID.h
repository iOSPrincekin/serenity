
#pragma once

#include <AK/NonnullRefPtr.h>
#include <AK/StringView.h>
#include <AK/Traits.h>
#include <LibWeb/Forward.h>

namespace Web::CSS {

enum class PropertyID {
    Invalid,
    Custom,

    Background,

    Border,

    BorderTop,

    BorderRight,

    BorderBottom,

    BorderLeft,

    BorderColor,

    BorderRadius,

    BorderStyle,

    BorderWidth,

    Flex,

    FlexFlow,

    Font,

    ListStyle,

    Margin,

    Outline,

    Overflow,

    Padding,

    TextDecoration,

    AlignItems,

    BackgroundAttachment,

    BackgroundClip,

    BackgroundColor,

    BackgroundImage,

    BackgroundOrigin,

    BackgroundPosition,

    BackgroundRepeat,

    BackgroundSize,

    BorderBottomColor,

    BorderBottomLeftRadius,

    BorderBottomRightRadius,

    BorderBottomStyle,

    BorderBottomWidth,

    BorderCollapse,

    BorderLeftColor,

    BorderLeftStyle,

    BorderLeftWidth,

    BorderRightColor,

    BorderRightStyle,

    BorderRightWidth,

    BorderSpacing,

    BorderTopColor,

    BorderTopLeftRadius,

    BorderTopRightRadius,

    BorderTopStyle,

    BorderTopWidth,

    Bottom,

    BoxShadow,

    BoxSizing,

    CaptionSide,

    Clear,

    Clip,

    Color,

    Content,

    Cursor,

    Direction,

    Display,

    Fill,

    FlexBasis,

    FlexDirection,

    FlexGrow,

    FlexShrink,

    Order,

    FlexWrap,

    Float,

    FontFamily,

    FontSize,

    FontStyle,

    FontVariant,

    FontWeight,

    Height,

    ImageRendering,

    JustifyContent,

    Left,

    LetterSpacing,

    LineHeight,

    ListStyleImage,

    ListStylePosition,

    ListStyleType,

    MarginBottom,

    MarginLeft,

    MarginRight,

    MarginTop,

    MaxHeight,

    MaxWidth,

    MinHeight,

    MinWidth,

    Opacity,

    OutlineColor,

    OutlineStyle,

    OutlineWidth,

    OverflowX,

    OverflowY,

    PaddingBottom,

    PaddingLeft,

    PaddingRight,

    PaddingTop,

    PointerEvents,

    Position,

    Right,

    Stroke,

    StrokeWidth,

    TextAlign,

    TextDecorationColor,

    TextDecorationLine,

    TextDecorationStyle,

    TextDecorationThickness,

    TextIndent,

    TextJustify,

    TextShadow,

    TextTransform,

    Top,

    Transform,

    TransformOrigin,

    UserSelect,

    VerticalAlign,

    Visibility,

    Width,

    WhiteSpace,

    WordSpacing,

    WordWrap,

    ZIndex,

};

PropertyID property_id_from_camel_case_string(StringView);
PropertyID property_id_from_string(StringView);
const char* string_from_property_id(PropertyID);
bool is_inherited_property(PropertyID);
NonnullRefPtr<StyleValue> property_initial_value(PropertyID);

bool property_accepts_value(PropertyID, StyleValue&);
size_t property_maximum_value_count(PropertyID);

bool property_affects_layout(PropertyID);
bool property_affects_stacking_context(PropertyID);

constexpr PropertyID first_property_id = PropertyID::Background;
constexpr PropertyID last_property_id = PropertyID::ZIndex;
constexpr PropertyID first_shorthand_property_id = PropertyID::Background;
constexpr PropertyID last_shorthand_property_id = PropertyID::TextDecoration;
constexpr PropertyID first_longhand_property_id = PropertyID::AlignItems;
constexpr PropertyID last_longhand_property_id = PropertyID::ZIndex;

enum class Quirk {
    // https://quirks.spec.whatwg.org/#the-hashless-hex-color-quirk
    HashlessHexColor,
    // https://quirks.spec.whatwg.org/#the-unitless-length-quirk
    UnitlessLength,
};
bool property_has_quirk(PropertyID, Quirk);

} // namespace Web::CSS

namespace AK {
template<>
struct Traits<Web::CSS::PropertyID> : public GenericTraits<Web::CSS::PropertyID> {
    static unsigned hash(Web::CSS::PropertyID property_id) { return int_hash((unsigned)property_id); }
};
} // namespace AK
