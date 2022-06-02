
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/CSS/Screen.h>

namespace Web::Bindings {

class ScreenWrapper : public Wrapper {
    JS_OBJECT(Screen, Wrapper);
public:
    static ScreenWrapper* create(JS::GlobalObject&, CSS::Screen&);

    ScreenWrapper(JS::GlobalObject&, CSS::Screen&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ScreenWrapper() override;

    CSS::Screen& impl() { return *m_impl; }
    CSS::Screen const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<CSS::Screen> m_impl;
        
};

ScreenWrapper* wrap(JS::GlobalObject&, CSS::Screen&);

} // namespace Web::Bindings

