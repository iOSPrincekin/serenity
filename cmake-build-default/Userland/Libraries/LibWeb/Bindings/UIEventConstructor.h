
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class UIEventConstructor : public JS::NativeFunction {
    JS_OBJECT(UIEventConstructor, JS::NativeFunction);
public:
    explicit UIEventConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~UIEventConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

