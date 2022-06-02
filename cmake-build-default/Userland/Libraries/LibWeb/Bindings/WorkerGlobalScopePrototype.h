
#pragma once

#include <LibJS/Runtime/Object.h>

namespace Web::Bindings {

class WorkerGlobalScopePrototype : public JS::Object {
    JS_OBJECT(WorkerGlobalScopePrototype, JS::Object);
public:
    explicit WorkerGlobalScopePrototype(JS::GlobalObject&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~WorkerGlobalScopePrototype() override;
private:

    JS_DECLARE_NATIVE_FUNCTION(import_scripts);
        
    JS_DECLARE_NATIVE_FUNCTION(btoa);
        
    JS_DECLARE_NATIVE_FUNCTION(atob);
        
    JS_DECLARE_NATIVE_FUNCTION(self_getter);

    JS_DECLARE_NATIVE_FUNCTION(location_getter);

    JS_DECLARE_NATIVE_FUNCTION(navigator_getter);

    JS_DECLARE_NATIVE_FUNCTION(onerror_getter);

    JS_DECLARE_NATIVE_FUNCTION(onerror_setter);

    JS_DECLARE_NATIVE_FUNCTION(onlanguagechange_getter);

    JS_DECLARE_NATIVE_FUNCTION(onlanguagechange_setter);

    JS_DECLARE_NATIVE_FUNCTION(onoffline_getter);

    JS_DECLARE_NATIVE_FUNCTION(onoffline_setter);

    JS_DECLARE_NATIVE_FUNCTION(ononline_getter);

    JS_DECLARE_NATIVE_FUNCTION(ononline_setter);

    JS_DECLARE_NATIVE_FUNCTION(onrejectionhandled_getter);

    JS_DECLARE_NATIVE_FUNCTION(onrejectionhandled_setter);

    JS_DECLARE_NATIVE_FUNCTION(onunhandledrejection_getter);

    JS_DECLARE_NATIVE_FUNCTION(onunhandledrejection_setter);

    JS_DECLARE_NATIVE_FUNCTION(origin_getter);

    JS_DECLARE_NATIVE_FUNCTION(is_secure_context_getter);

    JS_DECLARE_NATIVE_FUNCTION(cross_origin_isolated_getter);

};

} // namespace Web::Bindings
    
