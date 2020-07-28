/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <LibCore/ElapsedTimer.h>
#include <LibGUI/Button.h>
#include <LibGUI/TextBox.h>
#include <LibWeb/DOM/Document.h>
#include <LibWeb/DOM/Event.h>
#include <LibWeb/HTML/HTMLFormElement.h>
#include <LibWeb/HTML/HTMLInputElement.h>
#include <LibWeb/Layout/LayoutWidget.h>
#include <LibWeb/Page/Frame.h>
#include <LibWeb/PageView.h>

namespace Web::HTML {

HTMLInputElement::HTMLInputElement(DOM::Document& document, const FlyString& tag_name)
    : HTMLElement(document, tag_name)
{
}

HTMLInputElement::~HTMLInputElement()
{
}

RefPtr<LayoutNode> HTMLInputElement::create_layout_node(const CSS::StyleProperties* parent_style)
{
    ASSERT(document().frame());
    auto& frame = *document().frame();
    auto& page_view = const_cast<PageView&>(static_cast<const PageView&>(frame.page().client()));

    if (type() == "hidden")
        return nullptr;

    auto style = document().style_resolver().resolve_style(*this, parent_style);
    if (style->display() == CSS::Display::None)
        return nullptr;

    RefPtr<GUI::Widget> widget;
    if (type() == "submit") {
        auto& button = page_view.add<GUI::Button>(value());
        int text_width = Gfx::Font::default_font().width(value());
        button.set_relative_rect(0, 0, text_width + 20, 20);
        button.on_click = [this](auto) {
            if (auto* form = first_ancestor_of_type<HTMLFormElement>()) {
                // FIXME: Remove this const_cast once we have a non-const first_ancestor_of_type.
                const_cast<HTMLFormElement*>(form)->submit(this);
            }
        };
        widget = button;
    } else if (type() == "button") {
        auto& button = page_view.add<GUI::Button>(value());
        int text_width = Gfx::Font::default_font().width(value());
        button.set_relative_rect(0, 0, text_width + 20, 20);
        button.on_click = [this](auto) {
            const_cast<HTMLInputElement*>(this)->dispatch_event(DOM::Event::create("click"));
        };
        widget = button;
    } else {
        auto& text_box = page_view.add<GUI::TextBox>();
        text_box.set_text(value());
        text_box.on_change = [this] {
            auto& widget = downcast<LayoutWidget>(layout_node())->widget();
            const_cast<HTMLInputElement*>(this)->set_attribute(HTML::AttributeNames::value, static_cast<const GUI::TextBox&>(widget).text());
        };
        int text_width = Gfx::Font::default_font().width(value());
        auto size_value = attribute(HTML::AttributeNames::size);
        if (!size_value.is_null()) {
            auto size = size_value.to_uint();
            if (size.has_value())
                text_width = Gfx::Font::default_font().glyph_width('x') * size.value();
        }
        text_box.set_relative_rect(0, 0, text_width + 20, 20);
        widget = text_box;
    }

    return adopt(*new LayoutWidget(document(), *this, *widget));
}

}
