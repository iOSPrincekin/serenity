
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class TextMetricsConstructor : public JS::NativeFunction {
    JS_OBJECT(TextMetricsConstructor, JS::NativeFunction);
public:
    explicit TextMetricsConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextMetricsConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

