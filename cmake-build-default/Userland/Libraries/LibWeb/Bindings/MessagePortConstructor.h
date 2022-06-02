
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class MessagePortConstructor : public JS::NativeFunction {
    JS_OBJECT(MessagePortConstructor, JS::NativeFunction);
public:
    explicit MessagePortConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~MessagePortConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

