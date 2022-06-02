
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

namespace Web::Bindings {

class URLSearchParamsIteratorWrapper : public Wrapper {
    JS_OBJECT(URLSearchParamsIterator, Wrapper);
public:
    static URLSearchParamsIteratorWrapper* create(JS::GlobalObject&, URL::URLSearchParamsIterator&);

    URLSearchParamsIteratorWrapper(JS::GlobalObject&, URL::URLSearchParamsIterator&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~URLSearchParamsIteratorWrapper() override;

    URL::URLSearchParamsIterator& impl() { return *m_impl; }
    URL::URLSearchParamsIterator const& impl() const { return *m_impl; }

private:
    virtual void visit_edges(Cell::Visitor&) override; // The Iterator implementation has to visit the wrapper it's iterating

    NonnullRefPtr<URL::URLSearchParamsIterator> m_impl;
};

URLSearchParamsIteratorWrapper* wrap(JS::GlobalObject&, URL::URLSearchParamsIterator&);

} // namespace Web::Bindings

