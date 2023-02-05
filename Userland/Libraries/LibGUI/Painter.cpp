/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibGUI/Painter.h>
#include <LibGUI/Widget.h>
#include <LibGUI/Window.h>
#include <LibGfx/Bitmap.h>

//#define Debug_Painter

namespace GUI {
Painter::Painter(Gfx::Bitmap& bitmap)
    : Gfx::Painter(bitmap)
{
}

Painter::Painter(Widget& widget)
    : Painter(*widget.window()->back_bitmap())
{
    state().font = &widget.font();
    auto origin_rect = widget.window_relative_rect();
#ifdef Debug_Painter
    dbgln("Painter::Painter(Widget& widget),origin_rect.x():{},origin_rect.y():{},origin_rect.width():{},origin_rect.height():{}",origin_rect.x(),origin_rect.y(),origin_rect.width(),origin_rect.height());
#endif
    state().translation = origin_rect.location();
#ifdef Debug_Painter
    dbgln("Painter::Painter(Widget& widget),state().translation.x():{},state().translation.y():{}",state().translation.x(),state().translation.y());
#endif
    state().clip_rect = origin_rect.intersected(m_target->rect());
#ifdef Debug_Painter
    dbgln("Painter::Painter(Widget& widget),m_target->rect().x():{},m_target->rect().y():{},m_target->rect().width():{},m_target->rect().height():{}",m_target->rect().x(),m_target->rect().y(),m_target->rect().width(),m_target->rect().height());
#endif
    m_clip_origin = state().clip_rect;
#ifdef Debug_Painter
    dbgln("Painter::Painter(Widget& widget),m_clip_origin.x():{},m_clip_origin.y():{},m_clip_origin.width():{},m_clip_origin.height():{}",m_clip_origin.x(),m_clip_origin.y(),m_clip_origin.width(),m_clip_origin.height());
#endif
}

}
