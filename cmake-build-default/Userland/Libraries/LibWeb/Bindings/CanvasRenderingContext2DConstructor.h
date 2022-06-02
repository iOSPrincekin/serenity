
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class CanvasRenderingContext2DConstructor : public JS::NativeFunction {
    JS_OBJECT(CanvasRenderingContext2DConstructor, JS::NativeFunction);
public:
    explicit CanvasRenderingContext2DConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CanvasRenderingContext2DConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

