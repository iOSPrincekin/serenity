
#pragma once

#include <LibWeb/Bindings/Wrapper.h>

#include <LibWeb/HTML/ImageData.h>

namespace Web::Bindings {

class ImageDataWrapper : public Wrapper {
    JS_OBJECT(ImageData, Wrapper);
public:
    static ImageDataWrapper* create(JS::GlobalObject&, HTML::ImageData&);

    ImageDataWrapper(JS::GlobalObject&, HTML::ImageData&);
    virtual void initialize(JS::GlobalObject&) override;
    virtual ~ImageDataWrapper() override;

    HTML::ImageData& impl() { return *m_impl; }
    HTML::ImageData const& impl() const { return *m_impl; }

private:

    NonnullRefPtr<HTML::ImageData> m_impl;
        
};

ImageDataWrapper* wrap(JS::GlobalObject&, HTML::ImageData&);

} // namespace Web::Bindings

