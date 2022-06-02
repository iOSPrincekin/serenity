#pragma once

#include <AK/StringView.h>
#include <AK/Traits.h>
#include <LibWeb/CSS/ValueID.h>

namespace Web::CSS {

enum class MediaFeatureValueType {
    Boolean,
    Integer,
    Length,
    Ratio,
    Resolution,
};

enum class MediaFeatureID {
    AnyHover,
    AnyPointer,
    AspectRatio,
    Color,
    ColorGamut,
    ColorIndex,
    DeviceAspectRatio,
    DeviceHeight,
    DeviceWidth,
    DisplayMode,
    DynamicRange,
    EnvironmentBlending,
    ForcedColors,
    Grid,
    Height,
    HorizontalViewportSegments,
    Hover,
    InvertedColors,
    Monochrome,
    NavControls,
    Orientation,
    OverflowBlock,
    OverflowInline,
    Pointer,
    PrefersColorScheme,
    PrefersContrast,
    PrefersReducedData,
    PrefersReducedMotion,
    PrefersReducedTransparency,
    Resolution,
    Scan,
    Scripting,
    Update,
    VerticalViewportSegments,
    VideoColorGamut,
    VideoDynamicRange,
    Width,
};

Optional<MediaFeatureID> media_feature_id_from_string(StringView);
char const* string_from_media_feature_id(MediaFeatureID);

bool media_feature_type_is_range(MediaFeatureID);
bool media_feature_accepts_type(MediaFeatureID, MediaFeatureValueType);
bool media_feature_accepts_identifier(MediaFeatureID, ValueID);

}
