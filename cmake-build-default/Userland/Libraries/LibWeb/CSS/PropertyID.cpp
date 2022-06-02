
#include <AK/Assertions.h>
#include <LibWeb/CSS/Enums.h>
#include <LibWeb/CSS/Parser/Parser.h>
#include <LibWeb/CSS/PropertyID.h>
#include <LibWeb/CSS/StyleValue.h>

namespace Web::CSS {

PropertyID property_id_from_camel_case_string(StringView string)
{

    if (string.equals_ignoring_case("alignItems"sv))
        return PropertyID::AlignItems;

    if (string.equals_ignoring_case("background"sv))
        return PropertyID::Background;

    if (string.equals_ignoring_case("backgroundAttachment"sv))
        return PropertyID::BackgroundAttachment;

    if (string.equals_ignoring_case("backgroundClip"sv))
        return PropertyID::BackgroundClip;

    if (string.equals_ignoring_case("backgroundColor"sv))
        return PropertyID::BackgroundColor;

    if (string.equals_ignoring_case("backgroundImage"sv))
        return PropertyID::BackgroundImage;

    if (string.equals_ignoring_case("backgroundOrigin"sv))
        return PropertyID::BackgroundOrigin;

    if (string.equals_ignoring_case("backgroundPosition"sv))
        return PropertyID::BackgroundPosition;

    if (string.equals_ignoring_case("backgroundRepeat"sv))
        return PropertyID::BackgroundRepeat;

    if (string.equals_ignoring_case("backgroundSize"sv))
        return PropertyID::BackgroundSize;

    if (string.equals_ignoring_case("border"sv))
        return PropertyID::Border;

    if (string.equals_ignoring_case("borderTop"sv))
        return PropertyID::BorderTop;

    if (string.equals_ignoring_case("borderRight"sv))
        return PropertyID::BorderRight;

    if (string.equals_ignoring_case("borderBottom"sv))
        return PropertyID::BorderBottom;

    if (string.equals_ignoring_case("borderLeft"sv))
        return PropertyID::BorderLeft;

    if (string.equals_ignoring_case("borderBottomColor"sv))
        return PropertyID::BorderBottomColor;

    if (string.equals_ignoring_case("borderBottomLeftRadius"sv))
        return PropertyID::BorderBottomLeftRadius;

    if (string.equals_ignoring_case("borderBottomRightRadius"sv))
        return PropertyID::BorderBottomRightRadius;

    if (string.equals_ignoring_case("borderBottomStyle"sv))
        return PropertyID::BorderBottomStyle;

    if (string.equals_ignoring_case("borderBottomWidth"sv))
        return PropertyID::BorderBottomWidth;

    if (string.equals_ignoring_case("borderColor"sv))
        return PropertyID::BorderColor;

    if (string.equals_ignoring_case("borderCollapse"sv))
        return PropertyID::BorderCollapse;

    if (string.equals_ignoring_case("borderLeftColor"sv))
        return PropertyID::BorderLeftColor;

    if (string.equals_ignoring_case("borderLeftStyle"sv))
        return PropertyID::BorderLeftStyle;

    if (string.equals_ignoring_case("borderLeftWidth"sv))
        return PropertyID::BorderLeftWidth;

    if (string.equals_ignoring_case("borderRadius"sv))
        return PropertyID::BorderRadius;

    if (string.equals_ignoring_case("borderRightColor"sv))
        return PropertyID::BorderRightColor;

    if (string.equals_ignoring_case("borderRightStyle"sv))
        return PropertyID::BorderRightStyle;

    if (string.equals_ignoring_case("borderRightWidth"sv))
        return PropertyID::BorderRightWidth;

    if (string.equals_ignoring_case("borderSpacing"sv))
        return PropertyID::BorderSpacing;

    if (string.equals_ignoring_case("borderStyle"sv))
        return PropertyID::BorderStyle;

    if (string.equals_ignoring_case("borderTopColor"sv))
        return PropertyID::BorderTopColor;

    if (string.equals_ignoring_case("borderTopLeftRadius"sv))
        return PropertyID::BorderTopLeftRadius;

    if (string.equals_ignoring_case("borderTopRightRadius"sv))
        return PropertyID::BorderTopRightRadius;

    if (string.equals_ignoring_case("borderTopStyle"sv))
        return PropertyID::BorderTopStyle;

    if (string.equals_ignoring_case("borderTopWidth"sv))
        return PropertyID::BorderTopWidth;

    if (string.equals_ignoring_case("borderWidth"sv))
        return PropertyID::BorderWidth;

    if (string.equals_ignoring_case("bottom"sv))
        return PropertyID::Bottom;

    if (string.equals_ignoring_case("boxShadow"sv))
        return PropertyID::BoxShadow;

    if (string.equals_ignoring_case("boxSizing"sv))
        return PropertyID::BoxSizing;

    if (string.equals_ignoring_case("captionSide"sv))
        return PropertyID::CaptionSide;

    if (string.equals_ignoring_case("clear"sv))
        return PropertyID::Clear;

    if (string.equals_ignoring_case("clip"sv))
        return PropertyID::Clip;

    if (string.equals_ignoring_case("color"sv))
        return PropertyID::Color;

    if (string.equals_ignoring_case("content"sv))
        return PropertyID::Content;

    if (string.equals_ignoring_case("cursor"sv))
        return PropertyID::Cursor;

    if (string.equals_ignoring_case("direction"sv))
        return PropertyID::Direction;

    if (string.equals_ignoring_case("display"sv))
        return PropertyID::Display;

    if (string.equals_ignoring_case("fill"sv))
        return PropertyID::Fill;

    if (string.equals_ignoring_case("flex"sv))
        return PropertyID::Flex;

    if (string.equals_ignoring_case("flexBasis"sv))
        return PropertyID::FlexBasis;

    if (string.equals_ignoring_case("flexDirection"sv))
        return PropertyID::FlexDirection;

    if (string.equals_ignoring_case("flexFlow"sv))
        return PropertyID::FlexFlow;

    if (string.equals_ignoring_case("flexGrow"sv))
        return PropertyID::FlexGrow;

    if (string.equals_ignoring_case("flexShrink"sv))
        return PropertyID::FlexShrink;

    if (string.equals_ignoring_case("order"sv))
        return PropertyID::Order;

    if (string.equals_ignoring_case("flexWrap"sv))
        return PropertyID::FlexWrap;

    if (string.equals_ignoring_case("float"sv))
        return PropertyID::Float;

    if (string.equals_ignoring_case("font"sv))
        return PropertyID::Font;

    if (string.equals_ignoring_case("fontFamily"sv))
        return PropertyID::FontFamily;

    if (string.equals_ignoring_case("fontSize"sv))
        return PropertyID::FontSize;

    if (string.equals_ignoring_case("fontStyle"sv))
        return PropertyID::FontStyle;

    if (string.equals_ignoring_case("fontVariant"sv))
        return PropertyID::FontVariant;

    if (string.equals_ignoring_case("fontWeight"sv))
        return PropertyID::FontWeight;

    if (string.equals_ignoring_case("height"sv))
        return PropertyID::Height;

    if (string.equals_ignoring_case("imageRendering"sv))
        return PropertyID::ImageRendering;

    if (string.equals_ignoring_case("justifyContent"sv))
        return PropertyID::JustifyContent;

    if (string.equals_ignoring_case("left"sv))
        return PropertyID::Left;

    if (string.equals_ignoring_case("letterSpacing"sv))
        return PropertyID::LetterSpacing;

    if (string.equals_ignoring_case("lineHeight"sv))
        return PropertyID::LineHeight;

    if (string.equals_ignoring_case("listStyle"sv))
        return PropertyID::ListStyle;

    if (string.equals_ignoring_case("listStyleImage"sv))
        return PropertyID::ListStyleImage;

    if (string.equals_ignoring_case("listStylePosition"sv))
        return PropertyID::ListStylePosition;

    if (string.equals_ignoring_case("listStyleType"sv))
        return PropertyID::ListStyleType;

    if (string.equals_ignoring_case("margin"sv))
        return PropertyID::Margin;

    if (string.equals_ignoring_case("marginBottom"sv))
        return PropertyID::MarginBottom;

    if (string.equals_ignoring_case("marginLeft"sv))
        return PropertyID::MarginLeft;

    if (string.equals_ignoring_case("marginRight"sv))
        return PropertyID::MarginRight;

    if (string.equals_ignoring_case("marginTop"sv))
        return PropertyID::MarginTop;

    if (string.equals_ignoring_case("maxHeight"sv))
        return PropertyID::MaxHeight;

    if (string.equals_ignoring_case("maxWidth"sv))
        return PropertyID::MaxWidth;

    if (string.equals_ignoring_case("minHeight"sv))
        return PropertyID::MinHeight;

    if (string.equals_ignoring_case("minWidth"sv))
        return PropertyID::MinWidth;

    if (string.equals_ignoring_case("opacity"sv))
        return PropertyID::Opacity;

    if (string.equals_ignoring_case("outline"sv))
        return PropertyID::Outline;

    if (string.equals_ignoring_case("outlineColor"sv))
        return PropertyID::OutlineColor;

    if (string.equals_ignoring_case("outlineStyle"sv))
        return PropertyID::OutlineStyle;

    if (string.equals_ignoring_case("outlineWidth"sv))
        return PropertyID::OutlineWidth;

    if (string.equals_ignoring_case("overflow"sv))
        return PropertyID::Overflow;

    if (string.equals_ignoring_case("overflowX"sv))
        return PropertyID::OverflowX;

    if (string.equals_ignoring_case("overflowY"sv))
        return PropertyID::OverflowY;

    if (string.equals_ignoring_case("padding"sv))
        return PropertyID::Padding;

    if (string.equals_ignoring_case("paddingBottom"sv))
        return PropertyID::PaddingBottom;

    if (string.equals_ignoring_case("paddingLeft"sv))
        return PropertyID::PaddingLeft;

    if (string.equals_ignoring_case("paddingRight"sv))
        return PropertyID::PaddingRight;

    if (string.equals_ignoring_case("paddingTop"sv))
        return PropertyID::PaddingTop;

    if (string.equals_ignoring_case("pointerEvents"sv))
        return PropertyID::PointerEvents;

    if (string.equals_ignoring_case("position"sv))
        return PropertyID::Position;

    if (string.equals_ignoring_case("right"sv))
        return PropertyID::Right;

    if (string.equals_ignoring_case("stroke"sv))
        return PropertyID::Stroke;

    if (string.equals_ignoring_case("strokeWidth"sv))
        return PropertyID::StrokeWidth;

    if (string.equals_ignoring_case("textAlign"sv))
        return PropertyID::TextAlign;

    if (string.equals_ignoring_case("textDecoration"sv))
        return PropertyID::TextDecoration;

    if (string.equals_ignoring_case("textDecorationColor"sv))
        return PropertyID::TextDecorationColor;

    if (string.equals_ignoring_case("textDecorationLine"sv))
        return PropertyID::TextDecorationLine;

    if (string.equals_ignoring_case("textDecorationStyle"sv))
        return PropertyID::TextDecorationStyle;

    if (string.equals_ignoring_case("textDecorationThickness"sv))
        return PropertyID::TextDecorationThickness;

    if (string.equals_ignoring_case("textIndent"sv))
        return PropertyID::TextIndent;

    if (string.equals_ignoring_case("textJustify"sv))
        return PropertyID::TextJustify;

    if (string.equals_ignoring_case("textShadow"sv))
        return PropertyID::TextShadow;

    if (string.equals_ignoring_case("textTransform"sv))
        return PropertyID::TextTransform;

    if (string.equals_ignoring_case("top"sv))
        return PropertyID::Top;

    if (string.equals_ignoring_case("transform"sv))
        return PropertyID::Transform;

    if (string.equals_ignoring_case("transformOrigin"sv))
        return PropertyID::TransformOrigin;

    if (string.equals_ignoring_case("userSelect"sv))
        return PropertyID::UserSelect;

    if (string.equals_ignoring_case("verticalAlign"sv))
        return PropertyID::VerticalAlign;

    if (string.equals_ignoring_case("visibility"sv))
        return PropertyID::Visibility;

    if (string.equals_ignoring_case("width"sv))
        return PropertyID::Width;

    if (string.equals_ignoring_case("whiteSpace"sv))
        return PropertyID::WhiteSpace;

    if (string.equals_ignoring_case("wordSpacing"sv))
        return PropertyID::WordSpacing;

    if (string.equals_ignoring_case("wordWrap"sv))
        return PropertyID::WordWrap;

    if (string.equals_ignoring_case("zIndex"sv))
        return PropertyID::ZIndex;

    return PropertyID::Invalid;
}

PropertyID property_id_from_string(StringView string)
{

    if (string.equals_ignoring_case("align-items"))
        return PropertyID::AlignItems;

    if (string.equals_ignoring_case("background"))
        return PropertyID::Background;

    if (string.equals_ignoring_case("background-attachment"))
        return PropertyID::BackgroundAttachment;

    if (string.equals_ignoring_case("background-clip"))
        return PropertyID::BackgroundClip;

    if (string.equals_ignoring_case("background-color"))
        return PropertyID::BackgroundColor;

    if (string.equals_ignoring_case("background-image"))
        return PropertyID::BackgroundImage;

    if (string.equals_ignoring_case("background-origin"))
        return PropertyID::BackgroundOrigin;

    if (string.equals_ignoring_case("background-position"))
        return PropertyID::BackgroundPosition;

    if (string.equals_ignoring_case("background-repeat"))
        return PropertyID::BackgroundRepeat;

    if (string.equals_ignoring_case("background-size"))
        return PropertyID::BackgroundSize;

    if (string.equals_ignoring_case("border"))
        return PropertyID::Border;

    if (string.equals_ignoring_case("border-top"))
        return PropertyID::BorderTop;

    if (string.equals_ignoring_case("border-right"))
        return PropertyID::BorderRight;

    if (string.equals_ignoring_case("border-bottom"))
        return PropertyID::BorderBottom;

    if (string.equals_ignoring_case("border-left"))
        return PropertyID::BorderLeft;

    if (string.equals_ignoring_case("border-bottom-color"))
        return PropertyID::BorderBottomColor;

    if (string.equals_ignoring_case("border-bottom-left-radius"))
        return PropertyID::BorderBottomLeftRadius;

    if (string.equals_ignoring_case("border-bottom-right-radius"))
        return PropertyID::BorderBottomRightRadius;

    if (string.equals_ignoring_case("border-bottom-style"))
        return PropertyID::BorderBottomStyle;

    if (string.equals_ignoring_case("border-bottom-width"))
        return PropertyID::BorderBottomWidth;

    if (string.equals_ignoring_case("border-color"))
        return PropertyID::BorderColor;

    if (string.equals_ignoring_case("border-collapse"))
        return PropertyID::BorderCollapse;

    if (string.equals_ignoring_case("border-left-color"))
        return PropertyID::BorderLeftColor;

    if (string.equals_ignoring_case("border-left-style"))
        return PropertyID::BorderLeftStyle;

    if (string.equals_ignoring_case("border-left-width"))
        return PropertyID::BorderLeftWidth;

    if (string.equals_ignoring_case("border-radius"))
        return PropertyID::BorderRadius;

    if (string.equals_ignoring_case("border-right-color"))
        return PropertyID::BorderRightColor;

    if (string.equals_ignoring_case("border-right-style"))
        return PropertyID::BorderRightStyle;

    if (string.equals_ignoring_case("border-right-width"))
        return PropertyID::BorderRightWidth;

    if (string.equals_ignoring_case("border-spacing"))
        return PropertyID::BorderSpacing;

    if (string.equals_ignoring_case("border-style"))
        return PropertyID::BorderStyle;

    if (string.equals_ignoring_case("border-top-color"))
        return PropertyID::BorderTopColor;

    if (string.equals_ignoring_case("border-top-left-radius"))
        return PropertyID::BorderTopLeftRadius;

    if (string.equals_ignoring_case("border-top-right-radius"))
        return PropertyID::BorderTopRightRadius;

    if (string.equals_ignoring_case("border-top-style"))
        return PropertyID::BorderTopStyle;

    if (string.equals_ignoring_case("border-top-width"))
        return PropertyID::BorderTopWidth;

    if (string.equals_ignoring_case("border-width"))
        return PropertyID::BorderWidth;

    if (string.equals_ignoring_case("bottom"))
        return PropertyID::Bottom;

    if (string.equals_ignoring_case("box-shadow"))
        return PropertyID::BoxShadow;

    if (string.equals_ignoring_case("box-sizing"))
        return PropertyID::BoxSizing;

    if (string.equals_ignoring_case("caption-side"))
        return PropertyID::CaptionSide;

    if (string.equals_ignoring_case("clear"))
        return PropertyID::Clear;

    if (string.equals_ignoring_case("clip"))
        return PropertyID::Clip;

    if (string.equals_ignoring_case("color"))
        return PropertyID::Color;

    if (string.equals_ignoring_case("content"))
        return PropertyID::Content;

    if (string.equals_ignoring_case("cursor"))
        return PropertyID::Cursor;

    if (string.equals_ignoring_case("direction"))
        return PropertyID::Direction;

    if (string.equals_ignoring_case("display"))
        return PropertyID::Display;

    if (string.equals_ignoring_case("fill"))
        return PropertyID::Fill;

    if (string.equals_ignoring_case("flex"))
        return PropertyID::Flex;

    if (string.equals_ignoring_case("flex-basis"))
        return PropertyID::FlexBasis;

    if (string.equals_ignoring_case("flex-direction"))
        return PropertyID::FlexDirection;

    if (string.equals_ignoring_case("flex-flow"))
        return PropertyID::FlexFlow;

    if (string.equals_ignoring_case("flex-grow"))
        return PropertyID::FlexGrow;

    if (string.equals_ignoring_case("flex-shrink"))
        return PropertyID::FlexShrink;

    if (string.equals_ignoring_case("order"))
        return PropertyID::Order;

    if (string.equals_ignoring_case("flex-wrap"))
        return PropertyID::FlexWrap;

    if (string.equals_ignoring_case("float"))
        return PropertyID::Float;

    if (string.equals_ignoring_case("font"))
        return PropertyID::Font;

    if (string.equals_ignoring_case("font-family"))
        return PropertyID::FontFamily;

    if (string.equals_ignoring_case("font-size"))
        return PropertyID::FontSize;

    if (string.equals_ignoring_case("font-style"))
        return PropertyID::FontStyle;

    if (string.equals_ignoring_case("font-variant"))
        return PropertyID::FontVariant;

    if (string.equals_ignoring_case("font-weight"))
        return PropertyID::FontWeight;

    if (string.equals_ignoring_case("height"))
        return PropertyID::Height;

    if (string.equals_ignoring_case("image-rendering"))
        return PropertyID::ImageRendering;

    if (string.equals_ignoring_case("justify-content"))
        return PropertyID::JustifyContent;

    if (string.equals_ignoring_case("left"))
        return PropertyID::Left;

    if (string.equals_ignoring_case("letter-spacing"))
        return PropertyID::LetterSpacing;

    if (string.equals_ignoring_case("line-height"))
        return PropertyID::LineHeight;

    if (string.equals_ignoring_case("list-style"))
        return PropertyID::ListStyle;

    if (string.equals_ignoring_case("list-style-image"))
        return PropertyID::ListStyleImage;

    if (string.equals_ignoring_case("list-style-position"))
        return PropertyID::ListStylePosition;

    if (string.equals_ignoring_case("list-style-type"))
        return PropertyID::ListStyleType;

    if (string.equals_ignoring_case("margin"))
        return PropertyID::Margin;

    if (string.equals_ignoring_case("margin-bottom"))
        return PropertyID::MarginBottom;

    if (string.equals_ignoring_case("margin-left"))
        return PropertyID::MarginLeft;

    if (string.equals_ignoring_case("margin-right"))
        return PropertyID::MarginRight;

    if (string.equals_ignoring_case("margin-top"))
        return PropertyID::MarginTop;

    if (string.equals_ignoring_case("max-height"))
        return PropertyID::MaxHeight;

    if (string.equals_ignoring_case("max-width"))
        return PropertyID::MaxWidth;

    if (string.equals_ignoring_case("min-height"))
        return PropertyID::MinHeight;

    if (string.equals_ignoring_case("min-width"))
        return PropertyID::MinWidth;

    if (string.equals_ignoring_case("opacity"))
        return PropertyID::Opacity;

    if (string.equals_ignoring_case("outline"))
        return PropertyID::Outline;

    if (string.equals_ignoring_case("outline-color"))
        return PropertyID::OutlineColor;

    if (string.equals_ignoring_case("outline-style"))
        return PropertyID::OutlineStyle;

    if (string.equals_ignoring_case("outline-width"))
        return PropertyID::OutlineWidth;

    if (string.equals_ignoring_case("overflow"))
        return PropertyID::Overflow;

    if (string.equals_ignoring_case("overflow-x"))
        return PropertyID::OverflowX;

    if (string.equals_ignoring_case("overflow-y"))
        return PropertyID::OverflowY;

    if (string.equals_ignoring_case("padding"))
        return PropertyID::Padding;

    if (string.equals_ignoring_case("padding-bottom"))
        return PropertyID::PaddingBottom;

    if (string.equals_ignoring_case("padding-left"))
        return PropertyID::PaddingLeft;

    if (string.equals_ignoring_case("padding-right"))
        return PropertyID::PaddingRight;

    if (string.equals_ignoring_case("padding-top"))
        return PropertyID::PaddingTop;

    if (string.equals_ignoring_case("pointer-events"))
        return PropertyID::PointerEvents;

    if (string.equals_ignoring_case("position"))
        return PropertyID::Position;

    if (string.equals_ignoring_case("right"))
        return PropertyID::Right;

    if (string.equals_ignoring_case("stroke"))
        return PropertyID::Stroke;

    if (string.equals_ignoring_case("stroke-width"))
        return PropertyID::StrokeWidth;

    if (string.equals_ignoring_case("text-align"))
        return PropertyID::TextAlign;

    if (string.equals_ignoring_case("text-decoration"))
        return PropertyID::TextDecoration;

    if (string.equals_ignoring_case("text-decoration-color"))
        return PropertyID::TextDecorationColor;

    if (string.equals_ignoring_case("text-decoration-line"))
        return PropertyID::TextDecorationLine;

    if (string.equals_ignoring_case("text-decoration-style"))
        return PropertyID::TextDecorationStyle;

    if (string.equals_ignoring_case("text-decoration-thickness"))
        return PropertyID::TextDecorationThickness;

    if (string.equals_ignoring_case("text-indent"))
        return PropertyID::TextIndent;

    if (string.equals_ignoring_case("text-justify"))
        return PropertyID::TextJustify;

    if (string.equals_ignoring_case("text-shadow"))
        return PropertyID::TextShadow;

    if (string.equals_ignoring_case("text-transform"))
        return PropertyID::TextTransform;

    if (string.equals_ignoring_case("top"))
        return PropertyID::Top;

    if (string.equals_ignoring_case("transform"))
        return PropertyID::Transform;

    if (string.equals_ignoring_case("transform-origin"))
        return PropertyID::TransformOrigin;

    if (string.equals_ignoring_case("user-select"))
        return PropertyID::UserSelect;

    if (string.equals_ignoring_case("vertical-align"))
        return PropertyID::VerticalAlign;

    if (string.equals_ignoring_case("visibility"))
        return PropertyID::Visibility;

    if (string.equals_ignoring_case("width"))
        return PropertyID::Width;

    if (string.equals_ignoring_case("white-space"))
        return PropertyID::WhiteSpace;

    if (string.equals_ignoring_case("word-spacing"))
        return PropertyID::WordSpacing;

    if (string.equals_ignoring_case("word-wrap"))
        return PropertyID::WordWrap;

    if (string.equals_ignoring_case("z-index"))
        return PropertyID::ZIndex;

    return PropertyID::Invalid;
}

const char* string_from_property_id(PropertyID property_id) {
    switch (property_id) {

    case PropertyID::AlignItems:
        return "align-items";

    case PropertyID::Background:
        return "background";

    case PropertyID::BackgroundAttachment:
        return "background-attachment";

    case PropertyID::BackgroundClip:
        return "background-clip";

    case PropertyID::BackgroundColor:
        return "background-color";

    case PropertyID::BackgroundImage:
        return "background-image";

    case PropertyID::BackgroundOrigin:
        return "background-origin";

    case PropertyID::BackgroundPosition:
        return "background-position";

    case PropertyID::BackgroundRepeat:
        return "background-repeat";

    case PropertyID::BackgroundSize:
        return "background-size";

    case PropertyID::Border:
        return "border";

    case PropertyID::BorderTop:
        return "border-top";

    case PropertyID::BorderRight:
        return "border-right";

    case PropertyID::BorderBottom:
        return "border-bottom";

    case PropertyID::BorderLeft:
        return "border-left";

    case PropertyID::BorderBottomColor:
        return "border-bottom-color";

    case PropertyID::BorderBottomLeftRadius:
        return "border-bottom-left-radius";

    case PropertyID::BorderBottomRightRadius:
        return "border-bottom-right-radius";

    case PropertyID::BorderBottomStyle:
        return "border-bottom-style";

    case PropertyID::BorderBottomWidth:
        return "border-bottom-width";

    case PropertyID::BorderColor:
        return "border-color";

    case PropertyID::BorderCollapse:
        return "border-collapse";

    case PropertyID::BorderLeftColor:
        return "border-left-color";

    case PropertyID::BorderLeftStyle:
        return "border-left-style";

    case PropertyID::BorderLeftWidth:
        return "border-left-width";

    case PropertyID::BorderRadius:
        return "border-radius";

    case PropertyID::BorderRightColor:
        return "border-right-color";

    case PropertyID::BorderRightStyle:
        return "border-right-style";

    case PropertyID::BorderRightWidth:
        return "border-right-width";

    case PropertyID::BorderSpacing:
        return "border-spacing";

    case PropertyID::BorderStyle:
        return "border-style";

    case PropertyID::BorderTopColor:
        return "border-top-color";

    case PropertyID::BorderTopLeftRadius:
        return "border-top-left-radius";

    case PropertyID::BorderTopRightRadius:
        return "border-top-right-radius";

    case PropertyID::BorderTopStyle:
        return "border-top-style";

    case PropertyID::BorderTopWidth:
        return "border-top-width";

    case PropertyID::BorderWidth:
        return "border-width";

    case PropertyID::Bottom:
        return "bottom";

    case PropertyID::BoxShadow:
        return "box-shadow";

    case PropertyID::BoxSizing:
        return "box-sizing";

    case PropertyID::CaptionSide:
        return "caption-side";

    case PropertyID::Clear:
        return "clear";

    case PropertyID::Clip:
        return "clip";

    case PropertyID::Color:
        return "color";

    case PropertyID::Content:
        return "content";

    case PropertyID::Cursor:
        return "cursor";

    case PropertyID::Direction:
        return "direction";

    case PropertyID::Display:
        return "display";

    case PropertyID::Fill:
        return "fill";

    case PropertyID::Flex:
        return "flex";

    case PropertyID::FlexBasis:
        return "flex-basis";

    case PropertyID::FlexDirection:
        return "flex-direction";

    case PropertyID::FlexFlow:
        return "flex-flow";

    case PropertyID::FlexGrow:
        return "flex-grow";

    case PropertyID::FlexShrink:
        return "flex-shrink";

    case PropertyID::Order:
        return "order";

    case PropertyID::FlexWrap:
        return "flex-wrap";

    case PropertyID::Float:
        return "float";

    case PropertyID::Font:
        return "font";

    case PropertyID::FontFamily:
        return "font-family";

    case PropertyID::FontSize:
        return "font-size";

    case PropertyID::FontStyle:
        return "font-style";

    case PropertyID::FontVariant:
        return "font-variant";

    case PropertyID::FontWeight:
        return "font-weight";

    case PropertyID::Height:
        return "height";

    case PropertyID::ImageRendering:
        return "image-rendering";

    case PropertyID::JustifyContent:
        return "justify-content";

    case PropertyID::Left:
        return "left";

    case PropertyID::LetterSpacing:
        return "letter-spacing";

    case PropertyID::LineHeight:
        return "line-height";

    case PropertyID::ListStyle:
        return "list-style";

    case PropertyID::ListStyleImage:
        return "list-style-image";

    case PropertyID::ListStylePosition:
        return "list-style-position";

    case PropertyID::ListStyleType:
        return "list-style-type";

    case PropertyID::Margin:
        return "margin";

    case PropertyID::MarginBottom:
        return "margin-bottom";

    case PropertyID::MarginLeft:
        return "margin-left";

    case PropertyID::MarginRight:
        return "margin-right";

    case PropertyID::MarginTop:
        return "margin-top";

    case PropertyID::MaxHeight:
        return "max-height";

    case PropertyID::MaxWidth:
        return "max-width";

    case PropertyID::MinHeight:
        return "min-height";

    case PropertyID::MinWidth:
        return "min-width";

    case PropertyID::Opacity:
        return "opacity";

    case PropertyID::Outline:
        return "outline";

    case PropertyID::OutlineColor:
        return "outline-color";

    case PropertyID::OutlineStyle:
        return "outline-style";

    case PropertyID::OutlineWidth:
        return "outline-width";

    case PropertyID::Overflow:
        return "overflow";

    case PropertyID::OverflowX:
        return "overflow-x";

    case PropertyID::OverflowY:
        return "overflow-y";

    case PropertyID::Padding:
        return "padding";

    case PropertyID::PaddingBottom:
        return "padding-bottom";

    case PropertyID::PaddingLeft:
        return "padding-left";

    case PropertyID::PaddingRight:
        return "padding-right";

    case PropertyID::PaddingTop:
        return "padding-top";

    case PropertyID::PointerEvents:
        return "pointer-events";

    case PropertyID::Position:
        return "position";

    case PropertyID::Right:
        return "right";

    case PropertyID::Stroke:
        return "stroke";

    case PropertyID::StrokeWidth:
        return "stroke-width";

    case PropertyID::TextAlign:
        return "text-align";

    case PropertyID::TextDecoration:
        return "text-decoration";

    case PropertyID::TextDecorationColor:
        return "text-decoration-color";

    case PropertyID::TextDecorationLine:
        return "text-decoration-line";

    case PropertyID::TextDecorationStyle:
        return "text-decoration-style";

    case PropertyID::TextDecorationThickness:
        return "text-decoration-thickness";

    case PropertyID::TextIndent:
        return "text-indent";

    case PropertyID::TextJustify:
        return "text-justify";

    case PropertyID::TextShadow:
        return "text-shadow";

    case PropertyID::TextTransform:
        return "text-transform";

    case PropertyID::Top:
        return "top";

    case PropertyID::Transform:
        return "transform";

    case PropertyID::TransformOrigin:
        return "transform-origin";

    case PropertyID::UserSelect:
        return "user-select";

    case PropertyID::VerticalAlign:
        return "vertical-align";

    case PropertyID::Visibility:
        return "visibility";

    case PropertyID::Width:
        return "width";

    case PropertyID::WhiteSpace:
        return "white-space";

    case PropertyID::WordSpacing:
        return "word-spacing";

    case PropertyID::WordWrap:
        return "word-wrap";

    case PropertyID::ZIndex:
        return "z-index";

    default:
        return "(invalid CSS::PropertyID)";
    }
}

bool is_inherited_property(PropertyID property_id)
{
    switch (property_id) {

    case PropertyID::BorderCollapse:
        return true;

    case PropertyID::BorderSpacing:
        return true;

    case PropertyID::CaptionSide:
        return true;

    case PropertyID::Clip:
        return true;

    case PropertyID::Color:
        return true;

    case PropertyID::Cursor:
        return true;

    case PropertyID::Direction:
        return true;

    case PropertyID::Fill:
        return true;

    case PropertyID::Font:
        return true;

    case PropertyID::FontFamily:
        return true;

    case PropertyID::FontSize:
        return true;

    case PropertyID::FontStyle:
        return true;

    case PropertyID::FontVariant:
        return true;

    case PropertyID::FontWeight:
        return true;

    case PropertyID::ImageRendering:
        return true;

    case PropertyID::LetterSpacing:
        return true;

    case PropertyID::LineHeight:
        return true;

    case PropertyID::ListStyle:
        return true;

    case PropertyID::ListStyleImage:
        return true;

    case PropertyID::ListStylePosition:
        return true;

    case PropertyID::ListStyleType:
        return true;

    case PropertyID::PointerEvents:
        return true;

    case PropertyID::Stroke:
        return true;

    case PropertyID::StrokeWidth:
        return true;

    case PropertyID::TextAlign:
        return true;

    case PropertyID::TextDecorationLine:
        return true;

    case PropertyID::TextIndent:
        return true;

    case PropertyID::TextJustify:
        return true;

    case PropertyID::TextShadow:
        return true;

    case PropertyID::TextTransform:
        return true;

    case PropertyID::Visibility:
        return true;

    case PropertyID::WhiteSpace:
        return true;

    case PropertyID::WordSpacing:
        return true;

    case PropertyID::WordWrap:
        return true;

    default:
        return false;
    }
}

bool property_affects_layout(PropertyID property_id)
{
    switch (property_id) {

    case PropertyID::AlignItems:

    case PropertyID::Border:

    case PropertyID::BorderTop:

    case PropertyID::BorderRight:

    case PropertyID::BorderBottom:

    case PropertyID::BorderLeft:

    case PropertyID::BorderBottomWidth:

    case PropertyID::BorderCollapse:

    case PropertyID::BorderLeftWidth:

    case PropertyID::BorderRightWidth:

    case PropertyID::BorderSpacing:

    case PropertyID::BorderTopWidth:

    case PropertyID::BorderWidth:

    case PropertyID::Bottom:

    case PropertyID::BoxSizing:

    case PropertyID::CaptionSide:

    case PropertyID::Clear:

    case PropertyID::Clip:

    case PropertyID::Content:

    case PropertyID::Direction:

    case PropertyID::Display:

    case PropertyID::Flex:

    case PropertyID::FlexBasis:

    case PropertyID::FlexDirection:

    case PropertyID::FlexFlow:

    case PropertyID::FlexGrow:

    case PropertyID::FlexShrink:

    case PropertyID::Order:

    case PropertyID::FlexWrap:

    case PropertyID::Float:

    case PropertyID::Font:

    case PropertyID::FontFamily:

    case PropertyID::FontSize:

    case PropertyID::FontStyle:

    case PropertyID::FontVariant:

    case PropertyID::FontWeight:

    case PropertyID::Height:

    case PropertyID::JustifyContent:

    case PropertyID::Left:

    case PropertyID::LetterSpacing:

    case PropertyID::LineHeight:

    case PropertyID::ListStyle:

    case PropertyID::ListStyleImage:

    case PropertyID::ListStylePosition:

    case PropertyID::ListStyleType:

    case PropertyID::Margin:

    case PropertyID::MarginBottom:

    case PropertyID::MarginLeft:

    case PropertyID::MarginRight:

    case PropertyID::MarginTop:

    case PropertyID::MaxHeight:

    case PropertyID::MaxWidth:

    case PropertyID::MinHeight:

    case PropertyID::MinWidth:

    case PropertyID::Overflow:

    case PropertyID::OverflowX:

    case PropertyID::OverflowY:

    case PropertyID::Padding:

    case PropertyID::PaddingBottom:

    case PropertyID::PaddingLeft:

    case PropertyID::PaddingRight:

    case PropertyID::PaddingTop:

    case PropertyID::Position:

    case PropertyID::Right:

    case PropertyID::TextAlign:

    case PropertyID::TextIndent:

    case PropertyID::TextJustify:

    case PropertyID::TextTransform:

    case PropertyID::Top:

    case PropertyID::Transform:

    case PropertyID::VerticalAlign:

    case PropertyID::Visibility:

    case PropertyID::Width:

    case PropertyID::WhiteSpace:

    case PropertyID::WordSpacing:

    case PropertyID::WordWrap:

        return true;
    default:
        return false;
    }
}

bool property_affects_stacking_context(PropertyID property_id)
{
    switch (property_id) {

    case PropertyID::Opacity:

    case PropertyID::ZIndex:

        return true;
    default:
        return false;
    }
}

NonnullRefPtr<StyleValue> property_initial_value(PropertyID property_id)
{
    static Array<RefPtr<StyleValue>, to_underlying(last_property_id) + 1> initial_values;
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        Parser::ParsingContext parsing_context;

        {
            auto parsed_value = parse_css_value(parsing_context, "stretch", PropertyID::AlignItems);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::AlignItems)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "scroll", PropertyID::BackgroundAttachment);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundAttachment)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "border-box", PropertyID::BackgroundClip);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundClip)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "transparent", PropertyID::BackgroundColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BackgroundImage);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundImage)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "padding-box", PropertyID::BackgroundOrigin);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundOrigin)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0% 0%", PropertyID::BackgroundPosition);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundPosition)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "repeat", PropertyID::BackgroundRepeat);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundRepeat)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::BackgroundSize);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BackgroundSize)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "currentcolor", PropertyID::BorderBottomColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderBottomColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::BorderBottomLeftRadius);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderBottomLeftRadius)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::BorderBottomRightRadius);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderBottomRightRadius)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BorderBottomStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderBottomStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::BorderBottomWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderBottomWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "separate", PropertyID::BorderCollapse);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderCollapse)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "currentcolor", PropertyID::BorderLeftColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderLeftColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BorderLeftStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderLeftStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::BorderLeftWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderLeftWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "currentcolor", PropertyID::BorderRightColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderRightColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BorderRightStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderRightStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::BorderRightWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderRightWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::BorderSpacing);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderSpacing)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "currentcolor", PropertyID::BorderTopColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderTopColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::BorderTopLeftRadius);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderTopLeftRadius)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::BorderTopRightRadius);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderTopRightRadius)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BorderTopStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderTopStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::BorderTopWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderTopWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Bottom);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Bottom)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BoxShadow);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BoxShadow)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "content-box", PropertyID::BoxSizing);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BoxSizing)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "top", PropertyID::CaptionSide);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::CaptionSide)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::Clear);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Clear)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Clip);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Clip)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "-libweb-palette-base-text", PropertyID::Color);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Color)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::Content);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Content)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Cursor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Cursor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "ltr", PropertyID::Direction);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Direction)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "inline", PropertyID::Display);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Display)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "black", PropertyID::Fill);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Fill)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::FlexBasis);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FlexBasis)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "row", PropertyID::FlexDirection);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FlexDirection)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::FlexGrow);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FlexGrow)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "1", PropertyID::FlexShrink);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FlexShrink)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::Order);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Order)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "nowrap", PropertyID::FlexWrap);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FlexWrap)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::Float);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Float)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "sans-serif", PropertyID::FontFamily);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FontFamily)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::FontSize);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FontSize)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::FontStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FontStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::FontVariant);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FontVariant)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::FontWeight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FontWeight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Height);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Height)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::ImageRendering);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::ImageRendering)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "flex-start", PropertyID::JustifyContent);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::JustifyContent)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Left);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Left)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::LetterSpacing);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::LetterSpacing)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::LineHeight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::LineHeight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::ListStyleImage);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::ListStyleImage)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "outside", PropertyID::ListStylePosition);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::ListStylePosition)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "disc", PropertyID::ListStyleType);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::ListStyleType)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::MarginBottom);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MarginBottom)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::MarginLeft);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MarginLeft)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::MarginRight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MarginRight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::MarginTop);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MarginTop)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::MaxHeight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MaxHeight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::MaxWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MaxWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::MinHeight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MinHeight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::MinWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::MinWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "1", PropertyID::Opacity);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Opacity)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "invert", PropertyID::OutlineColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::OutlineColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::OutlineStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::OutlineStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::OutlineWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::OutlineWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "visible", PropertyID::OverflowX);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::OverflowX)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "visible", PropertyID::OverflowY);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::OverflowY)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::PaddingBottom);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::PaddingBottom)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::PaddingLeft);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::PaddingLeft)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::PaddingRight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::PaddingRight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::PaddingTop);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::PaddingTop)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::PointerEvents);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::PointerEvents)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "static", PropertyID::Position);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Position)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Right);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Right)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::Stroke);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Stroke)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "1px", PropertyID::StrokeWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::StrokeWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "left", PropertyID::TextAlign);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextAlign)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "currentcolor", PropertyID::TextDecorationColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextDecorationColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::TextDecorationLine);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextDecorationLine)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "solid", PropertyID::TextDecorationStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextDecorationStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::TextDecorationThickness);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextDecorationThickness)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::TextIndent);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextIndent)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::TextJustify);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextJustify)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::TextShadow);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextShadow)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::TextTransform);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextTransform)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Top);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Top)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::Transform);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Transform)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "50% 50%", PropertyID::TransformOrigin);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TransformOrigin)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::UserSelect);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::UserSelect)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "baseline", PropertyID::VerticalAlign);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::VerticalAlign)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "visible", PropertyID::Visibility);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Visibility)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::Width);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Width)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::WhiteSpace);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::WhiteSpace)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::WordSpacing);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::WordSpacing)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal", PropertyID::WordWrap);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::WordWrap)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "auto", PropertyID::ZIndex);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::ZIndex)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "transparent", PropertyID::Background);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Background)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium currentcolor none", PropertyID::Border);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Border)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium currentcolor none", PropertyID::BorderTop);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderTop)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium currentcolor none", PropertyID::BorderRight);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderRight)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium currentcolor none", PropertyID::BorderBottom);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderBottom)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium currentcolor none", PropertyID::BorderLeft);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderLeft)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "currentcolor", PropertyID::BorderColor);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderColor)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::BorderRadius);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderRadius)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::BorderStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "medium", PropertyID::BorderWidth);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::BorderWidth)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0 1 auto", PropertyID::Flex);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Flex)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "row nowrap", PropertyID::FlexFlow);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::FlexFlow)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "normal medium sans-serif", PropertyID::Font);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Font)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "outside disc", PropertyID::ListStyle);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::ListStyle)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::Margin);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Margin)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::Outline);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Outline)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "visible", PropertyID::Overflow);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Overflow)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "0", PropertyID::Padding);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::Padding)] = parsed_value.release_nonnull();
        }

        {
            auto parsed_value = parse_css_value(parsing_context, "none", PropertyID::TextDecoration);
            VERIFY(!parsed_value.is_null());
            initial_values[to_underlying(PropertyID::TextDecoration)] = parsed_value.release_nonnull();
        }

    }

    return *initial_values[to_underlying(property_id)];
}

bool property_has_quirk(PropertyID property_id, Quirk quirk)
{
    switch (property_id) {

    case PropertyID::BackgroundColor: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BackgroundPosition: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderBottomColor: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderBottomWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderColor: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderLeftColor: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderLeftWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderRightColor: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderRightWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderSpacing: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderTopColor: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderTopWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::BorderWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Bottom: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Clip: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Color: {
        switch (quirk) {

        case Quirk::HashlessHexColor:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::FontSize: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Height: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Left: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::LetterSpacing: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Margin: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MarginBottom: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MarginLeft: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MarginRight: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MarginTop: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MaxHeight: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MaxWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MinHeight: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::MinWidth: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Padding: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::PaddingBottom: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::PaddingLeft: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::PaddingRight: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::PaddingTop: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Right: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::TextIndent: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Top: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::VerticalAlign: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::Width: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    case PropertyID::WordSpacing: {
        switch (quirk) {

        case Quirk::UnitlessLength:
            return true;

        default:
            return false;
        }
    }

    default:
        return false;
    }
}

bool property_accepts_value(PropertyID property_id, StyleValue& style_value)
{
    if (style_value.is_builtin())
        return true;

    switch (property_id) {

    case PropertyID::AlignItems: {

        if (auto converted_identifier = value_id_to_align_items(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BackgroundAttachment: {

        if (auto converted_identifier = value_id_to_background_attachment(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BackgroundClip: {

        if (auto converted_identifier = value_id_to_background_box(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BackgroundColor: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::BackgroundImage: {

        if (style_value.is_image())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BackgroundOrigin: {

        if (auto converted_identifier = value_id_to_background_box(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BackgroundPosition: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Bottom:

        case ValueID::Center:

        case ValueID::Left:

        case ValueID::Right:

        case ValueID::Top:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BackgroundRepeat: {

        if (auto converted_identifier = value_id_to_repeat(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::RepeatX:

        case ValueID::RepeatY:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BackgroundSize: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

        case ValueID::Cover:

        case ValueID::Contain:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BorderBottomColor: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::BorderBottomLeftRadius: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::BorderBottomRightRadius: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::BorderBottomStyle: {

        if (auto converted_identifier = value_id_to_line_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BorderBottomWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Medium:

        case ValueID::Thick:

        case ValueID::Thin:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BorderColor: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::BorderCollapse: {

        switch (style_value.to_identifier()) {

        case ValueID::Collapse:

        case ValueID::Separate:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BorderLeftColor: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::BorderLeftStyle: {

        if (auto converted_identifier = value_id_to_line_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BorderLeftWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Medium:

        case ValueID::Thick:

        case ValueID::Thin:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BorderRightColor: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::BorderRightStyle: {

        if (auto converted_identifier = value_id_to_line_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BorderRightWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Medium:

        case ValueID::Thick:

        case ValueID::Thin:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BorderStyle: {

        if (auto converted_identifier = value_id_to_line_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BorderTopLeftRadius: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::BorderTopRightRadius: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::BorderTopStyle: {

        if (auto converted_identifier = value_id_to_line_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::BorderTopWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Medium:

        case ValueID::Thick:

        case ValueID::Thin:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BorderWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Medium:

        case ValueID::Thick:

        case ValueID::Thin:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Bottom: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BoxShadow: {

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::BoxSizing: {

        if (auto converted_identifier = value_id_to_box_sizing(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::CaptionSide: {

        switch (style_value.to_identifier()) {

        case ValueID::Bottom:

        case ValueID::Top:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Clear: {

        if (auto converted_identifier = value_id_to_clear(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Clip: {

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Color: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::Content: {

        if (style_value.is_string())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::Normal:

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Cursor: {

        if (auto converted_identifier = value_id_to_cursor(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Direction: {

        switch (style_value.to_identifier()) {

        case ValueID::Ltr:

        case ValueID::Rtl:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Display: {

        switch (style_value.to_identifier()) {

        case ValueID::Block:

        case ValueID::Flex:

        case ValueID::Inline:

        case ValueID::InlineBlock:

        case ValueID::InlineFlex:

        case ValueID::InlineTable:

        case ValueID::ListItem:

        case ValueID::None:

        case ValueID::Table:

        case ValueID::TableCaption:

        case ValueID::TableCell:

        case ValueID::TableColumn:

        case ValueID::TableColumnGroup:

        case ValueID::TableFooterGroup:

        case ValueID::TableHeaderGroup:

        case ValueID::TableRow:

        case ValueID::TableRowGroup:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Fill: {

        if (style_value.has_color())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::FlexBasis: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

        case ValueID::Content:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::FlexDirection: {

        if (auto converted_identifier = value_id_to_flex_direction(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::FlexGrow: {

        if ((style_value.has_number())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer || style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Number))) {
            return true;
        }

        return false;
    }

    case PropertyID::FlexShrink: {

        if ((style_value.has_number())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer || style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Number))) {
            return true;
        }

        return false;
    }

    case PropertyID::Order: {

        if ((style_value.has_integer())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer))) {
            return true;
        }

        return false;
    }

    case PropertyID::FlexWrap: {

        if (auto converted_identifier = value_id_to_flex_wrap(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Float: {

        if (auto converted_identifier = value_id_to_float(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::FontSize: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Large:

        case ValueID::Larger:

        case ValueID::Medium:

        case ValueID::Small:

        case ValueID::Smaller:

        case ValueID::XLarge:

        case ValueID::XSmall:

        case ValueID::XxLarge:

        case ValueID::XxSmall:

        case ValueID::XxxLarge:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::FontStyle: {

        switch (style_value.to_identifier()) {

        case ValueID::Italic:

        case ValueID::Normal:

        case ValueID::Oblique:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::FontVariant: {

        if (auto converted_identifier = value_id_to_font_variant(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::FontWeight: {

        if ((style_value.has_number() && (style_value.to_number() >= 1) && (style_value.to_number() <= 1000))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer || style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Number))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Bold:

        case ValueID::Bolder:

        case ValueID::Lighter:

        case ValueID::Normal:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Height: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::ImageRendering: {

        if (auto converted_identifier = value_id_to_image_rendering(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::JustifyContent: {

        if (auto converted_identifier = value_id_to_justify_content(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Left: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::LetterSpacing: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Normal:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::LineHeight: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.has_number() && (style_value.to_number() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer || style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Number))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Normal:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::ListStyleImage: {

        if (style_value.is_image())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::ListStylePosition: {

        switch (style_value.to_identifier()) {

        case ValueID::Inside:

        case ValueID::Outside:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::ListStyleType: {

        if (style_value.is_string())
            return true;

        if (auto converted_identifier = value_id_to_list_style_type(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Margin: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MarginBottom: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MarginLeft: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MarginRight: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MarginTop: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MaxHeight: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MaxWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MinHeight: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::MinWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Opacity: {

        if ((style_value.has_number())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer || style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Number))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::OutlineColor: {

        if (style_value.has_color())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::Invert:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::OutlineStyle: {

        if (auto converted_identifier = value_id_to_line_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::OutlineWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Medium:

        case ValueID::Thick:

        case ValueID::Thin:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Overflow: {

        if (auto converted_identifier = value_id_to_overflow(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::OverflowX: {

        if (auto converted_identifier = value_id_to_overflow(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::OverflowY: {

        if (auto converted_identifier = value_id_to_overflow(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Padding: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::PaddingBottom: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::PaddingLeft: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::PaddingRight: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::PaddingTop: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::PointerEvents: {

        if (auto converted_identifier = value_id_to_pointer_events(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Position: {

        if (auto converted_identifier = value_id_to_position(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Right: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::Stroke: {

        if (style_value.has_color())
            return true;

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::StrokeWidth: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.has_number() && (style_value.to_number() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer || style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Number))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::TextAlign: {

        if (auto converted_identifier = value_id_to_text_align(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::TextDecorationColor: {

        if (style_value.has_color())
            return true;

        return false;
    }

    case PropertyID::TextDecorationLine: {

        if (auto converted_identifier = value_id_to_text_decoration_line(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::TextDecorationStyle: {

        if (auto converted_identifier = value_id_to_text_decoration_style(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::TextDecorationThickness: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

        case ValueID::FromFont:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::TextIndent: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        return false;
    }

    case PropertyID::TextJustify: {

        if (auto converted_identifier = value_id_to_text_justify(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::TextShadow: {

        switch (style_value.to_identifier()) {

        case ValueID::None:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::TextTransform: {

        if (auto converted_identifier = value_id_to_text_transform(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Top: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::TransformOrigin: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Bottom:

        case ValueID::Center:

        case ValueID::Left:

        case ValueID::Right:

        case ValueID::Top:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::UserSelect: {

        switch (style_value.to_identifier()) {

        case ValueID::All:

        case ValueID::Auto:

        case ValueID::Contain:

        case ValueID::None:

        case ValueID::Text:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::VerticalAlign: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        if (auto converted_identifier = value_id_to_vertical_align(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Visibility: {

        if (auto converted_identifier = value_id_to_visibility(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::Width: {

        if ((style_value.has_length() && (style_value.to_length().raw_value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage() && (style_value.as_percentage().percentage().value() >= 0))
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::WhiteSpace: {

        if (auto converted_identifier = value_id_to_white_space(style_value.to_identifier()); converted_identifier.has_value())
            return true;

        return false;
    }

    case PropertyID::WordSpacing: {

        if ((style_value.has_length())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Length))) {
            return true;
        }

        if ((style_value.is_percentage())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Percentage))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Normal:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::WordWrap: {

        switch (style_value.to_identifier()) {

        case ValueID::Anywhere:

        case ValueID::BreakWord:

        case ValueID::Normal:

            return true;
        default:
            break;
        }

        return false;
    }

    case PropertyID::ZIndex: {

        if ((style_value.has_integer())
        || (style_value.is_calculated() && (style_value.as_calculated().resolved_type() == CalculatedStyleValue::ResolvedType::Integer))) {
            return true;
        }

        switch (style_value.to_identifier()) {

        case ValueID::Auto:

            return true;
        default:
            break;
        }

        return false;
    }

    default:
        return true;
    }
}

size_t property_maximum_value_count(PropertyID property_id)
{
    switch (property_id) {

    case PropertyID::BackgroundPosition:
        return 4;

    case PropertyID::BackgroundRepeat:
        return 2;

    case PropertyID::BackgroundSize:
        return 2;

    case PropertyID::BorderBottomLeftRadius:
        return 2;

    case PropertyID::BorderBottomRightRadius:
        return 2;

    case PropertyID::BorderColor:
        return 4;

    case PropertyID::BorderStyle:
        return 4;

    case PropertyID::BorderTopLeftRadius:
        return 2;

    case PropertyID::BorderTopRightRadius:
        return 2;

    case PropertyID::BorderWidth:
        return 4;

    case PropertyID::Margin:
        return 4;

    case PropertyID::Overflow:
        return 2;

    case PropertyID::Padding:
        return 4;

    case PropertyID::TransformOrigin:
        return 3;

    default:
        return 1;
    }
}

} // namespace Web::CSS

