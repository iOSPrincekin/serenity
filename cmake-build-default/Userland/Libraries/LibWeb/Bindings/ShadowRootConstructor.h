
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class ShadowRootConstructor : public JS::NativeFunction {
    JS_OBJECT(ShadowRootConstructor, JS::NativeFunction);
public:
    explicit ShadowRootConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ShadowRootConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

