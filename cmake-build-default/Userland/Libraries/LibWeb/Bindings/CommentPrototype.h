
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class CommentPrototype : public JS::Object {
    JS_OBJECT(CommentPrototype, JS::Object);
public:
    explicit CommentPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~CommentPrototype() override;
private:

};

} // namespace Web::Bindings
    
