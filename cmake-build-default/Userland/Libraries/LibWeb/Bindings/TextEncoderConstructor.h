
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class TextEncoderConstructor : public JS::NativeFunction {
    JS_OBJECT(TextEncoderConstructor, JS::NativeFunction);
public:
    explicit TextEncoderConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~TextEncoderConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

