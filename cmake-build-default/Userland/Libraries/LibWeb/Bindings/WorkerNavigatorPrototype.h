
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class WorkerNavigatorPrototype : public JS::Object {
    JS_OBJECT(WorkerNavigatorPrototype, JS::Object);
public:
    explicit WorkerNavigatorPrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerNavigatorPrototype() override;
private:

};

} // namespace Web::Bindings
    
