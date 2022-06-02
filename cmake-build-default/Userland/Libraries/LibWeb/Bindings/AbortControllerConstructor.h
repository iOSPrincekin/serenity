
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class AbortControllerConstructor : public JS::NativeFunction {
    JS_OBJECT(AbortControllerConstructor, JS::NativeFunction);
public:
    explicit AbortControllerConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~AbortControllerConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

