
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class WebSocketConstructor : public JS::NativeFunction {
    JS_OBJECT(WebSocketConstructor, JS::NativeFunction);
public:
    explicit WebSocketConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WebSocketConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

