
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class DOMTokenListConstructor : public JS::NativeFunction {
    JS_OBJECT(DOMTokenListConstructor, JS::NativeFunction);
public:
    explicit DOMTokenListConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~DOMTokenListConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

