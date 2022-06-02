
#include <LibWeb/CSS/Enums.h>
#include <LibWeb/CSS/ValueID.h>

namespace Web::CSS {

Optional<AlignItems> value_id_to_align_items(ValueID value_id)
{
    switch (value_id) {
    case ValueID::FlexStart:
        return AlignItems::FlexStart;
    case ValueID::FlexEnd:
        return AlignItems::FlexEnd;
    case ValueID::Center:
        return AlignItems::Center;
    case ValueID::Baseline:
        return AlignItems::Baseline;
    case ValueID::Stretch:
        return AlignItems::Stretch;
    default:
        return {};
    }
}

ValueID to_value_id(AlignItems align_items_value)
{
    switch (align_items_value) {
    case AlignItems::FlexStart:
        return ValueID::FlexStart;
    case AlignItems::FlexEnd:
        return ValueID::FlexEnd;
    case AlignItems::Center:
        return ValueID::Center;
    case AlignItems::Baseline:
        return ValueID::Baseline;
    case AlignItems::Stretch:
        return ValueID::Stretch;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(AlignItems value)
{
    switch (value) {
    case AlignItems::FlexStart:
        return "flex-start"sv;
    case AlignItems::FlexEnd:
        return "flex-end"sv;
    case AlignItems::Center:
        return "center"sv;
    case AlignItems::Baseline:
        return "baseline"sv;
    case AlignItems::Stretch:
        return "stretch"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<BackgroundAttachment> value_id_to_background_attachment(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Fixed:
        return BackgroundAttachment::Fixed;
    case ValueID::Local:
        return BackgroundAttachment::Local;
    case ValueID::Scroll:
        return BackgroundAttachment::Scroll;
    default:
        return {};
    }
}

ValueID to_value_id(BackgroundAttachment background_attachment_value)
{
    switch (background_attachment_value) {
    case BackgroundAttachment::Fixed:
        return ValueID::Fixed;
    case BackgroundAttachment::Local:
        return ValueID::Local;
    case BackgroundAttachment::Scroll:
        return ValueID::Scroll;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(BackgroundAttachment value)
{
    switch (value) {
    case BackgroundAttachment::Fixed:
        return "fixed"sv;
    case BackgroundAttachment::Local:
        return "local"sv;
    case BackgroundAttachment::Scroll:
        return "scroll"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<BackgroundBox> value_id_to_background_box(ValueID value_id)
{
    switch (value_id) {
    case ValueID::BorderBox:
        return BackgroundBox::BorderBox;
    case ValueID::ContentBox:
        return BackgroundBox::ContentBox;
    case ValueID::PaddingBox:
        return BackgroundBox::PaddingBox;
    default:
        return {};
    }
}

ValueID to_value_id(BackgroundBox background_box_value)
{
    switch (background_box_value) {
    case BackgroundBox::BorderBox:
        return ValueID::BorderBox;
    case BackgroundBox::ContentBox:
        return ValueID::ContentBox;
    case BackgroundBox::PaddingBox:
        return ValueID::PaddingBox;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(BackgroundBox value)
{
    switch (value) {
    case BackgroundBox::BorderBox:
        return "border-box"sv;
    case BackgroundBox::ContentBox:
        return "content-box"sv;
    case BackgroundBox::PaddingBox:
        return "padding-box"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<BoxSizing> value_id_to_box_sizing(ValueID value_id)
{
    switch (value_id) {
    case ValueID::BorderBox:
        return BoxSizing::BorderBox;
    case ValueID::ContentBox:
        return BoxSizing::ContentBox;
    default:
        return {};
    }
}

ValueID to_value_id(BoxSizing box_sizing_value)
{
    switch (box_sizing_value) {
    case BoxSizing::BorderBox:
        return ValueID::BorderBox;
    case BoxSizing::ContentBox:
        return ValueID::ContentBox;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(BoxSizing value)
{
    switch (value) {
    case BoxSizing::BorderBox:
        return "border-box"sv;
    case BoxSizing::ContentBox:
        return "content-box"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Clear> value_id_to_clear(ValueID value_id)
{
    switch (value_id) {
    case ValueID::None:
        return Clear::None;
    case ValueID::Left:
        return Clear::Left;
    case ValueID::Right:
        return Clear::Right;
    case ValueID::Both:
        return Clear::Both;
    default:
        return {};
    }
}

ValueID to_value_id(Clear clear_value)
{
    switch (clear_value) {
    case Clear::None:
        return ValueID::None;
    case Clear::Left:
        return ValueID::Left;
    case Clear::Right:
        return ValueID::Right;
    case Clear::Both:
        return ValueID::Both;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Clear value)
{
    switch (value) {
    case Clear::None:
        return "none"sv;
    case Clear::Left:
        return "left"sv;
    case Clear::Right:
        return "right"sv;
    case Clear::Both:
        return "both"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Cursor> value_id_to_cursor(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Auto:
        return Cursor::Auto;
    case ValueID::Default:
        return Cursor::Default;
    case ValueID::None:
        return Cursor::None;
    case ValueID::ContextMenu:
        return Cursor::ContextMenu;
    case ValueID::Help:
        return Cursor::Help;
    case ValueID::Pointer:
        return Cursor::Pointer;
    case ValueID::Progress:
        return Cursor::Progress;
    case ValueID::Wait:
        return Cursor::Wait;
    case ValueID::Cell:
        return Cursor::Cell;
    case ValueID::Crosshair:
        return Cursor::Crosshair;
    case ValueID::Text:
        return Cursor::Text;
    case ValueID::VerticalText:
        return Cursor::VerticalText;
    case ValueID::Alias:
        return Cursor::Alias;
    case ValueID::Copy:
        return Cursor::Copy;
    case ValueID::Move:
        return Cursor::Move;
    case ValueID::NoDrop:
        return Cursor::NoDrop;
    case ValueID::NotAllowed:
        return Cursor::NotAllowed;
    case ValueID::Grab:
        return Cursor::Grab;
    case ValueID::Grabbing:
        return Cursor::Grabbing;
    case ValueID::EResize:
        return Cursor::EResize;
    case ValueID::NResize:
        return Cursor::NResize;
    case ValueID::NeResize:
        return Cursor::NeResize;
    case ValueID::NwResize:
        return Cursor::NwResize;
    case ValueID::SResize:
        return Cursor::SResize;
    case ValueID::SeResize:
        return Cursor::SeResize;
    case ValueID::SwResize:
        return Cursor::SwResize;
    case ValueID::WResize:
        return Cursor::WResize;
    case ValueID::EwResize:
        return Cursor::EwResize;
    case ValueID::NsResize:
        return Cursor::NsResize;
    case ValueID::NeswResize:
        return Cursor::NeswResize;
    case ValueID::NwseResize:
        return Cursor::NwseResize;
    case ValueID::ColResize:
        return Cursor::ColResize;
    case ValueID::RowResize:
        return Cursor::RowResize;
    case ValueID::AllScroll:
        return Cursor::AllScroll;
    case ValueID::ZoomIn:
        return Cursor::ZoomIn;
    case ValueID::ZoomOut:
        return Cursor::ZoomOut;
    default:
        return {};
    }
}

ValueID to_value_id(Cursor cursor_value)
{
    switch (cursor_value) {
    case Cursor::Auto:
        return ValueID::Auto;
    case Cursor::Default:
        return ValueID::Default;
    case Cursor::None:
        return ValueID::None;
    case Cursor::ContextMenu:
        return ValueID::ContextMenu;
    case Cursor::Help:
        return ValueID::Help;
    case Cursor::Pointer:
        return ValueID::Pointer;
    case Cursor::Progress:
        return ValueID::Progress;
    case Cursor::Wait:
        return ValueID::Wait;
    case Cursor::Cell:
        return ValueID::Cell;
    case Cursor::Crosshair:
        return ValueID::Crosshair;
    case Cursor::Text:
        return ValueID::Text;
    case Cursor::VerticalText:
        return ValueID::VerticalText;
    case Cursor::Alias:
        return ValueID::Alias;
    case Cursor::Copy:
        return ValueID::Copy;
    case Cursor::Move:
        return ValueID::Move;
    case Cursor::NoDrop:
        return ValueID::NoDrop;
    case Cursor::NotAllowed:
        return ValueID::NotAllowed;
    case Cursor::Grab:
        return ValueID::Grab;
    case Cursor::Grabbing:
        return ValueID::Grabbing;
    case Cursor::EResize:
        return ValueID::EResize;
    case Cursor::NResize:
        return ValueID::NResize;
    case Cursor::NeResize:
        return ValueID::NeResize;
    case Cursor::NwResize:
        return ValueID::NwResize;
    case Cursor::SResize:
        return ValueID::SResize;
    case Cursor::SeResize:
        return ValueID::SeResize;
    case Cursor::SwResize:
        return ValueID::SwResize;
    case Cursor::WResize:
        return ValueID::WResize;
    case Cursor::EwResize:
        return ValueID::EwResize;
    case Cursor::NsResize:
        return ValueID::NsResize;
    case Cursor::NeswResize:
        return ValueID::NeswResize;
    case Cursor::NwseResize:
        return ValueID::NwseResize;
    case Cursor::ColResize:
        return ValueID::ColResize;
    case Cursor::RowResize:
        return ValueID::RowResize;
    case Cursor::AllScroll:
        return ValueID::AllScroll;
    case Cursor::ZoomIn:
        return ValueID::ZoomIn;
    case Cursor::ZoomOut:
        return ValueID::ZoomOut;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Cursor value)
{
    switch (value) {
    case Cursor::Auto:
        return "auto"sv;
    case Cursor::Default:
        return "default"sv;
    case Cursor::None:
        return "none"sv;
    case Cursor::ContextMenu:
        return "context-menu"sv;
    case Cursor::Help:
        return "help"sv;
    case Cursor::Pointer:
        return "pointer"sv;
    case Cursor::Progress:
        return "progress"sv;
    case Cursor::Wait:
        return "wait"sv;
    case Cursor::Cell:
        return "cell"sv;
    case Cursor::Crosshair:
        return "crosshair"sv;
    case Cursor::Text:
        return "text"sv;
    case Cursor::VerticalText:
        return "vertical-text"sv;
    case Cursor::Alias:
        return "alias"sv;
    case Cursor::Copy:
        return "copy"sv;
    case Cursor::Move:
        return "move"sv;
    case Cursor::NoDrop:
        return "no-drop"sv;
    case Cursor::NotAllowed:
        return "not-allowed"sv;
    case Cursor::Grab:
        return "grab"sv;
    case Cursor::Grabbing:
        return "grabbing"sv;
    case Cursor::EResize:
        return "e-resize"sv;
    case Cursor::NResize:
        return "n-resize"sv;
    case Cursor::NeResize:
        return "ne-resize"sv;
    case Cursor::NwResize:
        return "nw-resize"sv;
    case Cursor::SResize:
        return "s-resize"sv;
    case Cursor::SeResize:
        return "se-resize"sv;
    case Cursor::SwResize:
        return "sw-resize"sv;
    case Cursor::WResize:
        return "w-resize"sv;
    case Cursor::EwResize:
        return "ew-resize"sv;
    case Cursor::NsResize:
        return "ns-resize"sv;
    case Cursor::NeswResize:
        return "nesw-resize"sv;
    case Cursor::NwseResize:
        return "nwse-resize"sv;
    case Cursor::ColResize:
        return "col-resize"sv;
    case Cursor::RowResize:
        return "row-resize"sv;
    case Cursor::AllScroll:
        return "all-scroll"sv;
    case Cursor::ZoomIn:
        return "zoom-in"sv;
    case Cursor::ZoomOut:
        return "zoom-out"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<FlexDirection> value_id_to_flex_direction(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Row:
        return FlexDirection::Row;
    case ValueID::RowReverse:
        return FlexDirection::RowReverse;
    case ValueID::Column:
        return FlexDirection::Column;
    case ValueID::ColumnReverse:
        return FlexDirection::ColumnReverse;
    default:
        return {};
    }
}

ValueID to_value_id(FlexDirection flex_direction_value)
{
    switch (flex_direction_value) {
    case FlexDirection::Row:
        return ValueID::Row;
    case FlexDirection::RowReverse:
        return ValueID::RowReverse;
    case FlexDirection::Column:
        return ValueID::Column;
    case FlexDirection::ColumnReverse:
        return ValueID::ColumnReverse;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(FlexDirection value)
{
    switch (value) {
    case FlexDirection::Row:
        return "row"sv;
    case FlexDirection::RowReverse:
        return "row-reverse"sv;
    case FlexDirection::Column:
        return "column"sv;
    case FlexDirection::ColumnReverse:
        return "column-reverse"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<FlexWrap> value_id_to_flex_wrap(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Nowrap:
        return FlexWrap::Nowrap;
    case ValueID::Wrap:
        return FlexWrap::Wrap;
    case ValueID::WrapReverse:
        return FlexWrap::WrapReverse;
    default:
        return {};
    }
}

ValueID to_value_id(FlexWrap flex_wrap_value)
{
    switch (flex_wrap_value) {
    case FlexWrap::Nowrap:
        return ValueID::Nowrap;
    case FlexWrap::Wrap:
        return ValueID::Wrap;
    case FlexWrap::WrapReverse:
        return ValueID::WrapReverse;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(FlexWrap value)
{
    switch (value) {
    case FlexWrap::Nowrap:
        return "nowrap"sv;
    case FlexWrap::Wrap:
        return "wrap"sv;
    case FlexWrap::WrapReverse:
        return "wrap-reverse"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Float> value_id_to_float(ValueID value_id)
{
    switch (value_id) {
    case ValueID::None:
        return Float::None;
    case ValueID::Left:
        return Float::Left;
    case ValueID::Right:
        return Float::Right;
    default:
        return {};
    }
}

ValueID to_value_id(Float float_value)
{
    switch (float_value) {
    case Float::None:
        return ValueID::None;
    case Float::Left:
        return ValueID::Left;
    case Float::Right:
        return ValueID::Right;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Float value)
{
    switch (value) {
    case Float::None:
        return "none"sv;
    case Float::Left:
        return "left"sv;
    case Float::Right:
        return "right"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<FontVariant> value_id_to_font_variant(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Normal:
        return FontVariant::Normal;
    case ValueID::SmallCaps:
        return FontVariant::SmallCaps;
    default:
        return {};
    }
}

ValueID to_value_id(FontVariant font_variant_value)
{
    switch (font_variant_value) {
    case FontVariant::Normal:
        return ValueID::Normal;
    case FontVariant::SmallCaps:
        return ValueID::SmallCaps;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(FontVariant value)
{
    switch (value) {
    case FontVariant::Normal:
        return "normal"sv;
    case FontVariant::SmallCaps:
        return "small-caps"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<ImageRendering> value_id_to_image_rendering(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Auto:
        return ImageRendering::Auto;
    case ValueID::CrispEdges:
        return ImageRendering::CrispEdges;
    case ValueID::HighQuality:
        return ImageRendering::HighQuality;
    case ValueID::Pixelated:
        return ImageRendering::Pixelated;
    case ValueID::Smooth:
        return ImageRendering::Smooth;
    default:
        return {};
    }
}

ValueID to_value_id(ImageRendering image_rendering_value)
{
    switch (image_rendering_value) {
    case ImageRendering::Auto:
        return ValueID::Auto;
    case ImageRendering::CrispEdges:
        return ValueID::CrispEdges;
    case ImageRendering::HighQuality:
        return ValueID::HighQuality;
    case ImageRendering::Pixelated:
        return ValueID::Pixelated;
    case ImageRendering::Smooth:
        return ValueID::Smooth;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(ImageRendering value)
{
    switch (value) {
    case ImageRendering::Auto:
        return "auto"sv;
    case ImageRendering::CrispEdges:
        return "crisp-edges"sv;
    case ImageRendering::HighQuality:
        return "high-quality"sv;
    case ImageRendering::Pixelated:
        return "pixelated"sv;
    case ImageRendering::Smooth:
        return "smooth"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<JustifyContent> value_id_to_justify_content(ValueID value_id)
{
    switch (value_id) {
    case ValueID::FlexStart:
        return JustifyContent::FlexStart;
    case ValueID::FlexEnd:
        return JustifyContent::FlexEnd;
    case ValueID::Center:
        return JustifyContent::Center;
    case ValueID::SpaceBetween:
        return JustifyContent::SpaceBetween;
    case ValueID::SpaceAround:
        return JustifyContent::SpaceAround;
    default:
        return {};
    }
}

ValueID to_value_id(JustifyContent justify_content_value)
{
    switch (justify_content_value) {
    case JustifyContent::FlexStart:
        return ValueID::FlexStart;
    case JustifyContent::FlexEnd:
        return ValueID::FlexEnd;
    case JustifyContent::Center:
        return ValueID::Center;
    case JustifyContent::SpaceBetween:
        return ValueID::SpaceBetween;
    case JustifyContent::SpaceAround:
        return ValueID::SpaceAround;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(JustifyContent value)
{
    switch (value) {
    case JustifyContent::FlexStart:
        return "flex-start"sv;
    case JustifyContent::FlexEnd:
        return "flex-end"sv;
    case JustifyContent::Center:
        return "center"sv;
    case JustifyContent::SpaceBetween:
        return "space-between"sv;
    case JustifyContent::SpaceAround:
        return "space-around"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<LineStyle> value_id_to_line_style(ValueID value_id)
{
    switch (value_id) {
    case ValueID::None:
        return LineStyle::None;
    case ValueID::Hidden:
        return LineStyle::Hidden;
    case ValueID::Dotted:
        return LineStyle::Dotted;
    case ValueID::Dashed:
        return LineStyle::Dashed;
    case ValueID::Solid:
        return LineStyle::Solid;
    case ValueID::Double:
        return LineStyle::Double;
    case ValueID::Groove:
        return LineStyle::Groove;
    case ValueID::Ridge:
        return LineStyle::Ridge;
    case ValueID::Inset:
        return LineStyle::Inset;
    case ValueID::Outset:
        return LineStyle::Outset;
    default:
        return {};
    }
}

ValueID to_value_id(LineStyle line_style_value)
{
    switch (line_style_value) {
    case LineStyle::None:
        return ValueID::None;
    case LineStyle::Hidden:
        return ValueID::Hidden;
    case LineStyle::Dotted:
        return ValueID::Dotted;
    case LineStyle::Dashed:
        return ValueID::Dashed;
    case LineStyle::Solid:
        return ValueID::Solid;
    case LineStyle::Double:
        return ValueID::Double;
    case LineStyle::Groove:
        return ValueID::Groove;
    case LineStyle::Ridge:
        return ValueID::Ridge;
    case LineStyle::Inset:
        return ValueID::Inset;
    case LineStyle::Outset:
        return ValueID::Outset;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(LineStyle value)
{
    switch (value) {
    case LineStyle::None:
        return "none"sv;
    case LineStyle::Hidden:
        return "hidden"sv;
    case LineStyle::Dotted:
        return "dotted"sv;
    case LineStyle::Dashed:
        return "dashed"sv;
    case LineStyle::Solid:
        return "solid"sv;
    case LineStyle::Double:
        return "double"sv;
    case LineStyle::Groove:
        return "groove"sv;
    case LineStyle::Ridge:
        return "ridge"sv;
    case LineStyle::Inset:
        return "inset"sv;
    case LineStyle::Outset:
        return "outset"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<ListStyleType> value_id_to_list_style_type(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Circle:
        return ListStyleType::Circle;
    case ValueID::Decimal:
        return ListStyleType::Decimal;
    case ValueID::DecimalLeadingZero:
        return ListStyleType::DecimalLeadingZero;
    case ValueID::Disc:
        return ListStyleType::Disc;
    case ValueID::LowerAlpha:
        return ListStyleType::LowerAlpha;
    case ValueID::LowerLatin:
        return ListStyleType::LowerLatin;
    case ValueID::LowerRoman:
        return ListStyleType::LowerRoman;
    case ValueID::None:
        return ListStyleType::None;
    case ValueID::Square:
        return ListStyleType::Square;
    case ValueID::UpperAlpha:
        return ListStyleType::UpperAlpha;
    case ValueID::UpperLatin:
        return ListStyleType::UpperLatin;
    case ValueID::UpperRoman:
        return ListStyleType::UpperRoman;
    default:
        return {};
    }
}

ValueID to_value_id(ListStyleType list_style_type_value)
{
    switch (list_style_type_value) {
    case ListStyleType::Circle:
        return ValueID::Circle;
    case ListStyleType::Decimal:
        return ValueID::Decimal;
    case ListStyleType::DecimalLeadingZero:
        return ValueID::DecimalLeadingZero;
    case ListStyleType::Disc:
        return ValueID::Disc;
    case ListStyleType::LowerAlpha:
        return ValueID::LowerAlpha;
    case ListStyleType::LowerLatin:
        return ValueID::LowerLatin;
    case ListStyleType::LowerRoman:
        return ValueID::LowerRoman;
    case ListStyleType::None:
        return ValueID::None;
    case ListStyleType::Square:
        return ValueID::Square;
    case ListStyleType::UpperAlpha:
        return ValueID::UpperAlpha;
    case ListStyleType::UpperLatin:
        return ValueID::UpperLatin;
    case ListStyleType::UpperRoman:
        return ValueID::UpperRoman;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(ListStyleType value)
{
    switch (value) {
    case ListStyleType::Circle:
        return "circle"sv;
    case ListStyleType::Decimal:
        return "decimal"sv;
    case ListStyleType::DecimalLeadingZero:
        return "decimal-leading-zero"sv;
    case ListStyleType::Disc:
        return "disc"sv;
    case ListStyleType::LowerAlpha:
        return "lower-alpha"sv;
    case ListStyleType::LowerLatin:
        return "lower-latin"sv;
    case ListStyleType::LowerRoman:
        return "lower-roman"sv;
    case ListStyleType::None:
        return "none"sv;
    case ListStyleType::Square:
        return "square"sv;
    case ListStyleType::UpperAlpha:
        return "upper-alpha"sv;
    case ListStyleType::UpperLatin:
        return "upper-latin"sv;
    case ListStyleType::UpperRoman:
        return "upper-roman"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Overflow> value_id_to_overflow(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Auto:
        return Overflow::Auto;
    case ValueID::Clip:
        return Overflow::Clip;
    case ValueID::Hidden:
        return Overflow::Hidden;
    case ValueID::Scroll:
        return Overflow::Scroll;
    case ValueID::Visible:
        return Overflow::Visible;
    default:
        return {};
    }
}

ValueID to_value_id(Overflow overflow_value)
{
    switch (overflow_value) {
    case Overflow::Auto:
        return ValueID::Auto;
    case Overflow::Clip:
        return ValueID::Clip;
    case Overflow::Hidden:
        return ValueID::Hidden;
    case Overflow::Scroll:
        return ValueID::Scroll;
    case Overflow::Visible:
        return ValueID::Visible;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Overflow value)
{
    switch (value) {
    case Overflow::Auto:
        return "auto"sv;
    case Overflow::Clip:
        return "clip"sv;
    case Overflow::Hidden:
        return "hidden"sv;
    case Overflow::Scroll:
        return "scroll"sv;
    case Overflow::Visible:
        return "visible"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<PointerEvents> value_id_to_pointer_events(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Auto:
        return PointerEvents::Auto;
    case ValueID::All:
        return PointerEvents::All;
    case ValueID::None:
        return PointerEvents::None;
    default:
        return {};
    }
}

ValueID to_value_id(PointerEvents pointer_events_value)
{
    switch (pointer_events_value) {
    case PointerEvents::Auto:
        return ValueID::Auto;
    case PointerEvents::All:
        return ValueID::All;
    case PointerEvents::None:
        return ValueID::None;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(PointerEvents value)
{
    switch (value) {
    case PointerEvents::Auto:
        return "auto"sv;
    case PointerEvents::All:
        return "all"sv;
    case PointerEvents::None:
        return "none"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Position> value_id_to_position(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Absolute:
        return Position::Absolute;
    case ValueID::Fixed:
        return Position::Fixed;
    case ValueID::Relative:
        return Position::Relative;
    case ValueID::Static:
        return Position::Static;
    case ValueID::Sticky:
        return Position::Sticky;
    default:
        return {};
    }
}

ValueID to_value_id(Position position_value)
{
    switch (position_value) {
    case Position::Absolute:
        return ValueID::Absolute;
    case Position::Fixed:
        return ValueID::Fixed;
    case Position::Relative:
        return ValueID::Relative;
    case Position::Static:
        return ValueID::Static;
    case Position::Sticky:
        return ValueID::Sticky;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Position value)
{
    switch (value) {
    case Position::Absolute:
        return "absolute"sv;
    case Position::Fixed:
        return "fixed"sv;
    case Position::Relative:
        return "relative"sv;
    case Position::Static:
        return "static"sv;
    case Position::Sticky:
        return "sticky"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<PositionEdge> value_id_to_position_edge(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Left:
        return PositionEdge::Left;
    case ValueID::Right:
        return PositionEdge::Right;
    case ValueID::Top:
        return PositionEdge::Top;
    case ValueID::Bottom:
        return PositionEdge::Bottom;
    default:
        return {};
    }
}

ValueID to_value_id(PositionEdge position_edge_value)
{
    switch (position_edge_value) {
    case PositionEdge::Left:
        return ValueID::Left;
    case PositionEdge::Right:
        return ValueID::Right;
    case PositionEdge::Top:
        return ValueID::Top;
    case PositionEdge::Bottom:
        return ValueID::Bottom;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(PositionEdge value)
{
    switch (value) {
    case PositionEdge::Left:
        return "left"sv;
    case PositionEdge::Right:
        return "right"sv;
    case PositionEdge::Top:
        return "top"sv;
    case PositionEdge::Bottom:
        return "bottom"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Repeat> value_id_to_repeat(ValueID value_id)
{
    switch (value_id) {
    case ValueID::NoRepeat:
        return Repeat::NoRepeat;
    case ValueID::Repeat:
        return Repeat::Repeat;
    case ValueID::Round:
        return Repeat::Round;
    case ValueID::Space:
        return Repeat::Space;
    default:
        return {};
    }
}

ValueID to_value_id(Repeat repeat_value)
{
    switch (repeat_value) {
    case Repeat::NoRepeat:
        return ValueID::NoRepeat;
    case Repeat::Repeat:
        return ValueID::Repeat;
    case Repeat::Round:
        return ValueID::Round;
    case Repeat::Space:
        return ValueID::Space;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Repeat value)
{
    switch (value) {
    case Repeat::NoRepeat:
        return "no-repeat"sv;
    case Repeat::Repeat:
        return "repeat"sv;
    case Repeat::Round:
        return "round"sv;
    case Repeat::Space:
        return "space"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<TextAlign> value_id_to_text_align(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Center:
        return TextAlign::Center;
    case ValueID::Justify:
        return TextAlign::Justify;
    case ValueID::Left:
        return TextAlign::Left;
    case ValueID::Right:
        return TextAlign::Right;
    case ValueID::LibwebCenter:
        return TextAlign::LibwebCenter;
    default:
        return {};
    }
}

ValueID to_value_id(TextAlign text_align_value)
{
    switch (text_align_value) {
    case TextAlign::Center:
        return ValueID::Center;
    case TextAlign::Justify:
        return ValueID::Justify;
    case TextAlign::Left:
        return ValueID::Left;
    case TextAlign::Right:
        return ValueID::Right;
    case TextAlign::LibwebCenter:
        return ValueID::LibwebCenter;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(TextAlign value)
{
    switch (value) {
    case TextAlign::Center:
        return "center"sv;
    case TextAlign::Justify:
        return "justify"sv;
    case TextAlign::Left:
        return "left"sv;
    case TextAlign::Right:
        return "right"sv;
    case TextAlign::LibwebCenter:
        return "-libweb-center"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<TextDecorationLine> value_id_to_text_decoration_line(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Blink:
        return TextDecorationLine::Blink;
    case ValueID::LineThrough:
        return TextDecorationLine::LineThrough;
    case ValueID::None:
        return TextDecorationLine::None;
    case ValueID::Overline:
        return TextDecorationLine::Overline;
    case ValueID::Underline:
        return TextDecorationLine::Underline;
    default:
        return {};
    }
}

ValueID to_value_id(TextDecorationLine text_decoration_line_value)
{
    switch (text_decoration_line_value) {
    case TextDecorationLine::Blink:
        return ValueID::Blink;
    case TextDecorationLine::LineThrough:
        return ValueID::LineThrough;
    case TextDecorationLine::None:
        return ValueID::None;
    case TextDecorationLine::Overline:
        return ValueID::Overline;
    case TextDecorationLine::Underline:
        return ValueID::Underline;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(TextDecorationLine value)
{
    switch (value) {
    case TextDecorationLine::Blink:
        return "blink"sv;
    case TextDecorationLine::LineThrough:
        return "line-through"sv;
    case TextDecorationLine::None:
        return "none"sv;
    case TextDecorationLine::Overline:
        return "overline"sv;
    case TextDecorationLine::Underline:
        return "underline"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<TextDecorationStyle> value_id_to_text_decoration_style(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Dashed:
        return TextDecorationStyle::Dashed;
    case ValueID::Dotted:
        return TextDecorationStyle::Dotted;
    case ValueID::Double:
        return TextDecorationStyle::Double;
    case ValueID::Solid:
        return TextDecorationStyle::Solid;
    case ValueID::Wavy:
        return TextDecorationStyle::Wavy;
    default:
        return {};
    }
}

ValueID to_value_id(TextDecorationStyle text_decoration_style_value)
{
    switch (text_decoration_style_value) {
    case TextDecorationStyle::Dashed:
        return ValueID::Dashed;
    case TextDecorationStyle::Dotted:
        return ValueID::Dotted;
    case TextDecorationStyle::Double:
        return ValueID::Double;
    case TextDecorationStyle::Solid:
        return ValueID::Solid;
    case TextDecorationStyle::Wavy:
        return ValueID::Wavy;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(TextDecorationStyle value)
{
    switch (value) {
    case TextDecorationStyle::Dashed:
        return "dashed"sv;
    case TextDecorationStyle::Dotted:
        return "dotted"sv;
    case TextDecorationStyle::Double:
        return "double"sv;
    case TextDecorationStyle::Solid:
        return "solid"sv;
    case TextDecorationStyle::Wavy:
        return "wavy"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<TextJustify> value_id_to_text_justify(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Auto:
        return TextJustify::Auto;
    case ValueID::None:
        return TextJustify::None;
    case ValueID::InterWord:
        return TextJustify::InterWord;
    case ValueID::InterCharacter:
        return TextJustify::InterCharacter;
    case ValueID::Distribute:
        return TextJustify::InterCharacter;
    default:
        return {};
    }
}

ValueID to_value_id(TextJustify text_justify_value)
{
    switch (text_justify_value) {
    case TextJustify::Auto:
        return ValueID::Auto;
    case TextJustify::None:
        return ValueID::None;
    case TextJustify::InterWord:
        return ValueID::InterWord;
    case TextJustify::InterCharacter:
        return ValueID::InterCharacter;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(TextJustify value)
{
    switch (value) {
    case TextJustify::Auto:
        return "auto"sv;
    case TextJustify::None:
        return "none"sv;
    case TextJustify::InterWord:
        return "inter-word"sv;
    case TextJustify::InterCharacter:
        return "inter-character"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<TextTransform> value_id_to_text_transform(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Capitalize:
        return TextTransform::Capitalize;
    case ValueID::FullSizeKana:
        return TextTransform::FullSizeKana;
    case ValueID::FullWidth:
        return TextTransform::FullWidth;
    case ValueID::Lowercase:
        return TextTransform::Lowercase;
    case ValueID::None:
        return TextTransform::None;
    case ValueID::Uppercase:
        return TextTransform::Uppercase;
    default:
        return {};
    }
}

ValueID to_value_id(TextTransform text_transform_value)
{
    switch (text_transform_value) {
    case TextTransform::Capitalize:
        return ValueID::Capitalize;
    case TextTransform::FullSizeKana:
        return ValueID::FullSizeKana;
    case TextTransform::FullWidth:
        return ValueID::FullWidth;
    case TextTransform::Lowercase:
        return ValueID::Lowercase;
    case TextTransform::None:
        return ValueID::None;
    case TextTransform::Uppercase:
        return ValueID::Uppercase;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(TextTransform value)
{
    switch (value) {
    case TextTransform::Capitalize:
        return "capitalize"sv;
    case TextTransform::FullSizeKana:
        return "full-size-kana"sv;
    case TextTransform::FullWidth:
        return "full-width"sv;
    case TextTransform::Lowercase:
        return "lowercase"sv;
    case TextTransform::None:
        return "none"sv;
    case TextTransform::Uppercase:
        return "uppercase"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<VerticalAlign> value_id_to_vertical_align(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Baseline:
        return VerticalAlign::Baseline;
    case ValueID::Bottom:
        return VerticalAlign::Bottom;
    case ValueID::Middle:
        return VerticalAlign::Middle;
    case ValueID::Sub:
        return VerticalAlign::Sub;
    case ValueID::Super:
        return VerticalAlign::Super;
    case ValueID::TextBottom:
        return VerticalAlign::TextBottom;
    case ValueID::TextTop:
        return VerticalAlign::TextTop;
    case ValueID::Top:
        return VerticalAlign::Top;
    default:
        return {};
    }
}

ValueID to_value_id(VerticalAlign vertical_align_value)
{
    switch (vertical_align_value) {
    case VerticalAlign::Baseline:
        return ValueID::Baseline;
    case VerticalAlign::Bottom:
        return ValueID::Bottom;
    case VerticalAlign::Middle:
        return ValueID::Middle;
    case VerticalAlign::Sub:
        return ValueID::Sub;
    case VerticalAlign::Super:
        return ValueID::Super;
    case VerticalAlign::TextBottom:
        return ValueID::TextBottom;
    case VerticalAlign::TextTop:
        return ValueID::TextTop;
    case VerticalAlign::Top:
        return ValueID::Top;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(VerticalAlign value)
{
    switch (value) {
    case VerticalAlign::Baseline:
        return "baseline"sv;
    case VerticalAlign::Bottom:
        return "bottom"sv;
    case VerticalAlign::Middle:
        return "middle"sv;
    case VerticalAlign::Sub:
        return "sub"sv;
    case VerticalAlign::Super:
        return "super"sv;
    case VerticalAlign::TextBottom:
        return "text-bottom"sv;
    case VerticalAlign::TextTop:
        return "text-top"sv;
    case VerticalAlign::Top:
        return "top"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<Visibility> value_id_to_visibility(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Collapse:
        return Visibility::Collapse;
    case ValueID::Hidden:
        return Visibility::Hidden;
    case ValueID::Visible:
        return Visibility::Visible;
    default:
        return {};
    }
}

ValueID to_value_id(Visibility visibility_value)
{
    switch (visibility_value) {
    case Visibility::Collapse:
        return ValueID::Collapse;
    case Visibility::Hidden:
        return ValueID::Hidden;
    case Visibility::Visible:
        return ValueID::Visible;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(Visibility value)
{
    switch (value) {
    case Visibility::Collapse:
        return "collapse"sv;
    case Visibility::Hidden:
        return "hidden"sv;
    case Visibility::Visible:
        return "visible"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<WhiteSpace> value_id_to_white_space(ValueID value_id)
{
    switch (value_id) {
    case ValueID::Normal:
        return WhiteSpace::Normal;
    case ValueID::Nowrap:
        return WhiteSpace::Nowrap;
    case ValueID::Pre:
        return WhiteSpace::Pre;
    case ValueID::PreLine:
        return WhiteSpace::PreLine;
    case ValueID::PreWrap:
        return WhiteSpace::PreWrap;
    default:
        return {};
    }
}

ValueID to_value_id(WhiteSpace white_space_value)
{
    switch (white_space_value) {
    case WhiteSpace::Normal:
        return ValueID::Normal;
    case WhiteSpace::Nowrap:
        return ValueID::Nowrap;
    case WhiteSpace::Pre:
        return ValueID::Pre;
    case WhiteSpace::PreLine:
        return ValueID::PreLine;
    case WhiteSpace::PreWrap:
        return ValueID::PreWrap;
    default:
        VERIFY_NOT_REACHED();
    }
}

StringView to_string(WhiteSpace value)
{
    switch (value) {
    case WhiteSpace::Normal:
        return "normal"sv;
    case WhiteSpace::Nowrap:
        return "nowrap"sv;
    case WhiteSpace::Pre:
        return "pre"sv;
    case WhiteSpace::PreLine:
        return "pre-line"sv;
    case WhiteSpace::PreWrap:
        return "pre-wrap"sv;
    default:
        VERIFY_NOT_REACHED();
    }
}
}
