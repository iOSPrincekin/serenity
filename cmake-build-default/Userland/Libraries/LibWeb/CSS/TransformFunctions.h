
#pragma once

#include <AK/Optional.h>
#include <AK/StringView.h>

namespace Web::CSS {

enum class TransformFunction {
    Matrix,
    Translate,
    TranslateX,
    TranslateY,
    Scale,
    ScaleX,
    ScaleY,
    Rotate,
    Skew,
    SkewX,
    SkewY,
};
Optional<TransformFunction> transform_function_from_string(StringView);
StringView to_string(TransformFunction);

enum class TransformFunctionParameterType {
    Angle,
    LengthPercentage,
    Number,
};

struct TransformFunctionMetadata {
    size_t min_parameters;
    size_t max_parameters;
    TransformFunctionParameterType parameter_type;
};
TransformFunctionMetadata transform_function_metadata(TransformFunction);

}
