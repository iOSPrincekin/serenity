
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class HTMLHRElementConstructor : public JS::NativeFunction {
    JS_OBJECT(HTMLHRElementConstructor, JS::NativeFunction);
public:
    explicit HTMLHRElementConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~HTMLHRElementConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

