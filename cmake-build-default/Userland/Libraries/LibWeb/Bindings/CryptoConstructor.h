
#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace Web::Bindings {

class CryptoConstructor : public JS::NativeFunction {
    JS_OBJECT(CryptoConstructor, JS::NativeFunction);
public:
    explicit CryptoConstructor(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CryptoConstructor() override;

    virtual JS::ThrowCompletionOr<JS::Value> call() override;
    virtual JS::ThrowCompletionOr<JS::Object*> construct(JS::FunctionObject& new_target) override;

private:
    virtual bool has_constructor() const override { return true; }

};

} // namespace Web::Bindings

