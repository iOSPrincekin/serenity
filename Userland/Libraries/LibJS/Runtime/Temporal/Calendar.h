/*
 * Copyright (c) 2021, Idan Horowitz <idan.horowitz@serenityos.org>
 * Copyright (c) 2021, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Object.h>
#include <LibJS/Runtime/Temporal/AbstractOperations.h>
#include <LibJS/Runtime/Value.h>

namespace JS::Temporal {

class Calendar final : public Object {
    JS_OBJECT(Calendar, Object);

public:
    Calendar(String identifier, Object& prototype);
    virtual ~Calendar() override = default;

    String const& identifier() const { return m_identifier; }

private:
    // 12.5 Properties of Temporal.Calendar Instances, https://tc39.es/proposal-temporal/#sec-properties-of-temporal-calendar-instances

    // [[Identifier]]
    String m_identifier;
};

Calendar* create_temporal_calendar(GlobalObject&, String const& identifier, FunctionObject* new_target = nullptr);
bool is_builtin_calendar(String const& identifier);
Calendar* get_builtin_calendar(GlobalObject&, String const& identifier);
Calendar* get_iso8601_calendar(GlobalObject&);
Vector<String> calendar_fields(GlobalObject&, Object& calendar, Vector<StringView> const& field_names);
double calendar_year(GlobalObject&, Object& calendar, Object& date_like);
double calendar_month(GlobalObject&, Object& calendar, Object& date_like);
String calendar_month_code(GlobalObject&, Object& calendar, Object& date_like);
Object* to_temporal_calendar(GlobalObject&, Value);
Object* to_temporal_calendar_with_iso_default(GlobalObject&, Value);
Object* get_temporal_calendar_with_iso_default(GlobalObject&, Object&);
PlainDate* date_from_fields(GlobalObject&, Object& calendar, Object& fields, Object& options);
bool calendar_equals(GlobalObject&, Object& one, Object& two);
bool is_iso_leap_year(i32 year);
i32 iso_days_in_month(i32 year, i32 month);
String build_iso_month_code(i32 month);
double resolve_iso_month(GlobalObject&, Object& fields);
Optional<TemporalDate> iso_date_from_fields(GlobalObject&, Object& fields, Object& options);
i32 iso_year(Object& temporal_object);
u8 iso_month(Object& temporal_object);
String iso_month_code(Object& temporal_object);

}
