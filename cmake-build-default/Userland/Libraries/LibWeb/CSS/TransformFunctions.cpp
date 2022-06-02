
#include <LibWeb/CSS/TransformFunctions.h>
#include <AK/Assertions.h>

namespace Web::CSS {

Optional<TransformFunction> transform_function_from_string(StringView name)
{

    if (name.equals_ignoring_case("matrix"sv))
        return TransformFunction::Matrix;

    if (name.equals_ignoring_case("translate"sv))
        return TransformFunction::Translate;

    if (name.equals_ignoring_case("translateX"sv))
        return TransformFunction::TranslateX;

    if (name.equals_ignoring_case("translateY"sv))
        return TransformFunction::TranslateY;

    if (name.equals_ignoring_case("scale"sv))
        return TransformFunction::Scale;

    if (name.equals_ignoring_case("scaleX"sv))
        return TransformFunction::ScaleX;

    if (name.equals_ignoring_case("scaleY"sv))
        return TransformFunction::ScaleY;

    if (name.equals_ignoring_case("rotate"sv))
        return TransformFunction::Rotate;

    if (name.equals_ignoring_case("skew"sv))
        return TransformFunction::Skew;

    if (name.equals_ignoring_case("skewX"sv))
        return TransformFunction::SkewX;

    if (name.equals_ignoring_case("skewY"sv))
        return TransformFunction::SkewY;

    return {};
}

StringView to_string(TransformFunction transform_function)
{
    switch (transform_function) {

    case TransformFunction::Matrix:
        return "matrix"sv;

    case TransformFunction::Translate:
        return "translate"sv;

    case TransformFunction::TranslateX:
        return "translateX"sv;

    case TransformFunction::TranslateY:
        return "translateY"sv;

    case TransformFunction::Scale:
        return "scale"sv;

    case TransformFunction::ScaleX:
        return "scaleX"sv;

    case TransformFunction::ScaleY:
        return "scaleY"sv;

    case TransformFunction::Rotate:
        return "rotate"sv;

    case TransformFunction::Skew:
        return "skew"sv;

    case TransformFunction::SkewX:
        return "skewX"sv;

    case TransformFunction::SkewY:
        return "skewY"sv;

    default:
        VERIFY_NOT_REACHED();
    }
}

TransformFunctionMetadata transform_function_metadata(TransformFunction transform_function)
{
    switch (transform_function) {

    case TransformFunction::Matrix:
        return TransformFunctionMetadata {
            .min_parameters = 6,
            .max_parameters = 6,
            .parameter_type = TransformFunctionParameterType::Number
        };

    case TransformFunction::Translate:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 2,
            .parameter_type = TransformFunctionParameterType::LengthPercentage
        };

    case TransformFunction::TranslateX:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::LengthPercentage
        };

    case TransformFunction::TranslateY:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::LengthPercentage
        };

    case TransformFunction::Scale:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 2,
            .parameter_type = TransformFunctionParameterType::Number
        };

    case TransformFunction::ScaleX:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::Number
        };

    case TransformFunction::ScaleY:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::Number
        };

    case TransformFunction::Rotate:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::Angle
        };

    case TransformFunction::Skew:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 2,
            .parameter_type = TransformFunctionParameterType::Angle
        };

    case TransformFunction::SkewX:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::Angle
        };

    case TransformFunction::SkewY:
        return TransformFunctionMetadata {
            .min_parameters = 1,
            .max_parameters = 1,
            .parameter_type = TransformFunctionParameterType::Angle
        };

    default:
        VERIFY_NOT_REACHED();
    }
}

}
