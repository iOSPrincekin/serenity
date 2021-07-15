/*
 * Copyright (c) 2021, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Object.h>

namespace JS::Temporal {

class DurationPrototype final : public Object {
    JS_OBJECT(DurationPrototype, Object);

public:
    explicit DurationPrototype(GlobalObject&);
    virtual void initialize(GlobalObject&) override;
    virtual ~DurationPrototype() override = default;
};

}
