#include <LibWeb/CSS/MediaFeatureID.h>

namespace Web::CSS {

Optional<MediaFeatureID> media_feature_id_from_string(StringView string)
{
    if (string.equals_ignoring_case("any-hover"sv))
        return MediaFeatureID::AnyHover;

    if (string.equals_ignoring_case("any-pointer"sv))
        return MediaFeatureID::AnyPointer;

    if (string.equals_ignoring_case("aspect-ratio"sv))
        return MediaFeatureID::AspectRatio;

    if (string.equals_ignoring_case("color"sv))
        return MediaFeatureID::Color;

    if (string.equals_ignoring_case("color-gamut"sv))
        return MediaFeatureID::ColorGamut;

    if (string.equals_ignoring_case("color-index"sv))
        return MediaFeatureID::ColorIndex;

    if (string.equals_ignoring_case("device-aspect-ratio"sv))
        return MediaFeatureID::DeviceAspectRatio;

    if (string.equals_ignoring_case("device-height"sv))
        return MediaFeatureID::DeviceHeight;

    if (string.equals_ignoring_case("device-width"sv))
        return MediaFeatureID::DeviceWidth;

    if (string.equals_ignoring_case("display-mode"sv))
        return MediaFeatureID::DisplayMode;

    if (string.equals_ignoring_case("dynamic-range"sv))
        return MediaFeatureID::DynamicRange;

    if (string.equals_ignoring_case("environment-blending"sv))
        return MediaFeatureID::EnvironmentBlending;

    if (string.equals_ignoring_case("forced-colors"sv))
        return MediaFeatureID::ForcedColors;

    if (string.equals_ignoring_case("grid"sv))
        return MediaFeatureID::Grid;

    if (string.equals_ignoring_case("height"sv))
        return MediaFeatureID::Height;

    if (string.equals_ignoring_case("horizontal-viewport-segments"sv))
        return MediaFeatureID::HorizontalViewportSegments;

    if (string.equals_ignoring_case("hover"sv))
        return MediaFeatureID::Hover;

    if (string.equals_ignoring_case("inverted-colors"sv))
        return MediaFeatureID::InvertedColors;

    if (string.equals_ignoring_case("monochrome"sv))
        return MediaFeatureID::Monochrome;

    if (string.equals_ignoring_case("nav-controls"sv))
        return MediaFeatureID::NavControls;

    if (string.equals_ignoring_case("orientation"sv))
        return MediaFeatureID::Orientation;

    if (string.equals_ignoring_case("overflow-block"sv))
        return MediaFeatureID::OverflowBlock;

    if (string.equals_ignoring_case("overflow-inline"sv))
        return MediaFeatureID::OverflowInline;

    if (string.equals_ignoring_case("pointer"sv))
        return MediaFeatureID::Pointer;

    if (string.equals_ignoring_case("prefers-color-scheme"sv))
        return MediaFeatureID::PrefersColorScheme;

    if (string.equals_ignoring_case("prefers-contrast"sv))
        return MediaFeatureID::PrefersContrast;

    if (string.equals_ignoring_case("prefers-reduced-data"sv))
        return MediaFeatureID::PrefersReducedData;

    if (string.equals_ignoring_case("prefers-reduced-motion"sv))
        return MediaFeatureID::PrefersReducedMotion;

    if (string.equals_ignoring_case("prefers-reduced-transparency"sv))
        return MediaFeatureID::PrefersReducedTransparency;

    if (string.equals_ignoring_case("resolution"sv))
        return MediaFeatureID::Resolution;

    if (string.equals_ignoring_case("scan"sv))
        return MediaFeatureID::Scan;

    if (string.equals_ignoring_case("scripting"sv))
        return MediaFeatureID::Scripting;

    if (string.equals_ignoring_case("update"sv))
        return MediaFeatureID::Update;

    if (string.equals_ignoring_case("vertical-viewport-segments"sv))
        return MediaFeatureID::VerticalViewportSegments;

    if (string.equals_ignoring_case("video-color-gamut"sv))
        return MediaFeatureID::VideoColorGamut;

    if (string.equals_ignoring_case("video-dynamic-range"sv))
        return MediaFeatureID::VideoDynamicRange;

    if (string.equals_ignoring_case("width"sv))
        return MediaFeatureID::Width;

    return {};
}

char const* string_from_media_feature_id(MediaFeatureID media_feature_id)
{
    switch (media_feature_id) {
    case MediaFeatureID::AnyHover:
        return "any-hover";
    case MediaFeatureID::AnyPointer:
        return "any-pointer";
    case MediaFeatureID::AspectRatio:
        return "aspect-ratio";
    case MediaFeatureID::Color:
        return "color";
    case MediaFeatureID::ColorGamut:
        return "color-gamut";
    case MediaFeatureID::ColorIndex:
        return "color-index";
    case MediaFeatureID::DeviceAspectRatio:
        return "device-aspect-ratio";
    case MediaFeatureID::DeviceHeight:
        return "device-height";
    case MediaFeatureID::DeviceWidth:
        return "device-width";
    case MediaFeatureID::DisplayMode:
        return "display-mode";
    case MediaFeatureID::DynamicRange:
        return "dynamic-range";
    case MediaFeatureID::EnvironmentBlending:
        return "environment-blending";
    case MediaFeatureID::ForcedColors:
        return "forced-colors";
    case MediaFeatureID::Grid:
        return "grid";
    case MediaFeatureID::Height:
        return "height";
    case MediaFeatureID::HorizontalViewportSegments:
        return "horizontal-viewport-segments";
    case MediaFeatureID::Hover:
        return "hover";
    case MediaFeatureID::InvertedColors:
        return "inverted-colors";
    case MediaFeatureID::Monochrome:
        return "monochrome";
    case MediaFeatureID::NavControls:
        return "nav-controls";
    case MediaFeatureID::Orientation:
        return "orientation";
    case MediaFeatureID::OverflowBlock:
        return "overflow-block";
    case MediaFeatureID::OverflowInline:
        return "overflow-inline";
    case MediaFeatureID::Pointer:
        return "pointer";
    case MediaFeatureID::PrefersColorScheme:
        return "prefers-color-scheme";
    case MediaFeatureID::PrefersContrast:
        return "prefers-contrast";
    case MediaFeatureID::PrefersReducedData:
        return "prefers-reduced-data";
    case MediaFeatureID::PrefersReducedMotion:
        return "prefers-reduced-motion";
    case MediaFeatureID::PrefersReducedTransparency:
        return "prefers-reduced-transparency";
    case MediaFeatureID::Resolution:
        return "resolution";
    case MediaFeatureID::Scan:
        return "scan";
    case MediaFeatureID::Scripting:
        return "scripting";
    case MediaFeatureID::Update:
        return "update";
    case MediaFeatureID::VerticalViewportSegments:
        return "vertical-viewport-segments";
    case MediaFeatureID::VideoColorGamut:
        return "video-color-gamut";
    case MediaFeatureID::VideoDynamicRange:
        return "video-dynamic-range";
    case MediaFeatureID::Width:
        return "width";
    }
    VERIFY_NOT_REACHED();
}

bool media_feature_type_is_range(MediaFeatureID media_feature_id)
{
    switch (media_feature_id) {
    case MediaFeatureID::AnyHover:
        return false;
    case MediaFeatureID::AnyPointer:
        return false;
    case MediaFeatureID::AspectRatio:
        return true;
    case MediaFeatureID::Color:
        return true;
    case MediaFeatureID::ColorGamut:
        return false;
    case MediaFeatureID::ColorIndex:
        return true;
    case MediaFeatureID::DeviceAspectRatio:
        return true;
    case MediaFeatureID::DeviceHeight:
        return true;
    case MediaFeatureID::DeviceWidth:
        return true;
    case MediaFeatureID::DisplayMode:
        return false;
    case MediaFeatureID::DynamicRange:
        return false;
    case MediaFeatureID::EnvironmentBlending:
        return false;
    case MediaFeatureID::ForcedColors:
        return false;
    case MediaFeatureID::Grid:
        return false;
    case MediaFeatureID::Height:
        return true;
    case MediaFeatureID::HorizontalViewportSegments:
        return true;
    case MediaFeatureID::Hover:
        return false;
    case MediaFeatureID::InvertedColors:
        return false;
    case MediaFeatureID::Monochrome:
        return true;
    case MediaFeatureID::NavControls:
        return false;
    case MediaFeatureID::Orientation:
        return false;
    case MediaFeatureID::OverflowBlock:
        return false;
    case MediaFeatureID::OverflowInline:
        return false;
    case MediaFeatureID::Pointer:
        return false;
    case MediaFeatureID::PrefersColorScheme:
        return false;
    case MediaFeatureID::PrefersContrast:
        return false;
    case MediaFeatureID::PrefersReducedData:
        return false;
    case MediaFeatureID::PrefersReducedMotion:
        return false;
    case MediaFeatureID::PrefersReducedTransparency:
        return false;
    case MediaFeatureID::Resolution:
        return true;
    case MediaFeatureID::Scan:
        return false;
    case MediaFeatureID::Scripting:
        return false;
    case MediaFeatureID::Update:
        return false;
    case MediaFeatureID::VerticalViewportSegments:
        return true;
    case MediaFeatureID::VideoColorGamut:
        return false;
    case MediaFeatureID::VideoDynamicRange:
        return false;
    case MediaFeatureID::Width:
        return true;
    }
    VERIFY_NOT_REACHED();
}

bool media_feature_accepts_type(MediaFeatureID media_feature_id, MediaFeatureValueType value_type)
{
    switch (media_feature_id) {
    case MediaFeatureID::AnyHover:
        return false;
    case MediaFeatureID::AnyPointer:
        return false;
    case MediaFeatureID::AspectRatio:
        switch (value_type) {
        case MediaFeatureValueType::Ratio:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Color:
        switch (value_type) {
        case MediaFeatureValueType::Integer:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::ColorGamut:
        return false;
    case MediaFeatureID::ColorIndex:
        switch (value_type) {
        case MediaFeatureValueType::Integer:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::DeviceAspectRatio:
        switch (value_type) {
        case MediaFeatureValueType::Ratio:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::DeviceHeight:
        switch (value_type) {
        case MediaFeatureValueType::Length:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::DeviceWidth:
        switch (value_type) {
        case MediaFeatureValueType::Length:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::DisplayMode:
        return false;
    case MediaFeatureID::DynamicRange:
        return false;
    case MediaFeatureID::EnvironmentBlending:
        return false;
    case MediaFeatureID::ForcedColors:
        return false;
    case MediaFeatureID::Grid:
        switch (value_type) {
        case MediaFeatureValueType::Boolean:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Height:
        switch (value_type) {
        case MediaFeatureValueType::Length:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::HorizontalViewportSegments:
        switch (value_type) {
        case MediaFeatureValueType::Integer:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Hover:
        return false;
    case MediaFeatureID::InvertedColors:
        return false;
    case MediaFeatureID::Monochrome:
        switch (value_type) {
        case MediaFeatureValueType::Integer:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::NavControls:
        return false;
    case MediaFeatureID::Orientation:
        return false;
    case MediaFeatureID::OverflowBlock:
        return false;
    case MediaFeatureID::OverflowInline:
        return false;
    case MediaFeatureID::Pointer:
        return false;
    case MediaFeatureID::PrefersColorScheme:
        return false;
    case MediaFeatureID::PrefersContrast:
        return false;
    case MediaFeatureID::PrefersReducedData:
        return false;
    case MediaFeatureID::PrefersReducedMotion:
        return false;
    case MediaFeatureID::PrefersReducedTransparency:
        return false;
    case MediaFeatureID::Resolution:
        switch (value_type) {
        case MediaFeatureValueType::Resolution:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Scan:
        return false;
    case MediaFeatureID::Scripting:
        return false;
    case MediaFeatureID::Update:
        return false;
    case MediaFeatureID::VerticalViewportSegments:
        switch (value_type) {
        case MediaFeatureValueType::Integer:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::VideoColorGamut:
        return false;
    case MediaFeatureID::VideoDynamicRange:
        return false;
    case MediaFeatureID::Width:
        switch (value_type) {
        case MediaFeatureValueType::Length:
            return true;
        default:
            return false;
        }
    }
    VERIFY_NOT_REACHED();
}

bool media_feature_accepts_identifier(MediaFeatureID media_feature_id, ValueID identifier)
{
    switch (media_feature_id) {
    case MediaFeatureID::AnyHover:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Hover:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::AnyPointer:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Coarse:
            return true;
        case ValueID::Fine:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::AspectRatio:
        return false;
    case MediaFeatureID::Color:
        return false;
    case MediaFeatureID::ColorGamut:
        switch (identifier) {
        case ValueID::Srgb:
            return true;
        case ValueID::P3:
            return true;
        case ValueID::Rec2020:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::ColorIndex:
        return false;
    case MediaFeatureID::DeviceAspectRatio:
        return false;
    case MediaFeatureID::DeviceHeight:
        return false;
    case MediaFeatureID::DeviceWidth:
        return false;
    case MediaFeatureID::DisplayMode:
        switch (identifier) {
        case ValueID::Fullscreen:
            return true;
        case ValueID::Standalone:
            return true;
        case ValueID::MinimalUi:
            return true;
        case ValueID::Browser:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::DynamicRange:
        switch (identifier) {
        case ValueID::Standard:
            return true;
        case ValueID::High:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::EnvironmentBlending:
        switch (identifier) {
        case ValueID::Opaque:
            return true;
        case ValueID::Additive:
            return true;
        case ValueID::Subtractive:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::ForcedColors:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Active:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Grid:
        return false;
    case MediaFeatureID::Height:
        return false;
    case MediaFeatureID::HorizontalViewportSegments:
        return false;
    case MediaFeatureID::Hover:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Hover:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::InvertedColors:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Inverted:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Monochrome:
        return false;
    case MediaFeatureID::NavControls:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Back:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Orientation:
        switch (identifier) {
        case ValueID::Portrait:
            return true;
        case ValueID::Landscape:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::OverflowBlock:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Scroll:
            return true;
        case ValueID::Paged:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::OverflowInline:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Scroll:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Pointer:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Coarse:
            return true;
        case ValueID::Fine:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::PrefersColorScheme:
        switch (identifier) {
        case ValueID::Light:
            return true;
        case ValueID::Dark:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::PrefersContrast:
        switch (identifier) {
        case ValueID::NoPreference:
            return true;
        case ValueID::Less:
            return true;
        case ValueID::More:
            return true;
        case ValueID::Custom:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::PrefersReducedData:
        switch (identifier) {
        case ValueID::NoPreference:
            return true;
        case ValueID::Reduce:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::PrefersReducedMotion:
        switch (identifier) {
        case ValueID::NoPreference:
            return true;
        case ValueID::Reduce:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::PrefersReducedTransparency:
        switch (identifier) {
        case ValueID::NoPreference:
            return true;
        case ValueID::Reduce:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Resolution:
        switch (identifier) {
        case ValueID::Infinite:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Scan:
        switch (identifier) {
        case ValueID::Interlace:
            return true;
        case ValueID::Progressive:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Scripting:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::InitialOnly:
            return true;
        case ValueID::Enabled:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Update:
        switch (identifier) {
        case ValueID::None:
            return true;
        case ValueID::Slow:
            return true;
        case ValueID::Fast:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::VerticalViewportSegments:
        return false;
    case MediaFeatureID::VideoColorGamut:
        switch (identifier) {
        case ValueID::Srgb:
            return true;
        case ValueID::P3:
            return true;
        case ValueID::Rec2020:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::VideoDynamicRange:
        switch (identifier) {
        case ValueID::Standard:
            return true;
        case ValueID::High:
            return true;
        default:
            return false;
        }
    case MediaFeatureID::Width:
        return false;
    }
    VERIFY_NOT_REACHED();
}

}
