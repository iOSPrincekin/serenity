/*
 * Copyright (c) 2020-2021, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Interpreter.h>
#include <LibJS/Runtime/DeclarativeEnvironmentRecord.h>
#include <LibJS/Runtime/Error.h>
#include <LibJS/Runtime/Function.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/Value.h>

namespace JS {

DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord()
    : EnvironmentRecord(nullptr)
{
}

DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord(EnvironmentRecordType environment_record_type)
    : EnvironmentRecord(nullptr)
    , m_environment_record_type(environment_record_type)
{
}

DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord(EnvironmentRecord* parent_scope)
    : EnvironmentRecord(parent_scope)
{
}

DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord(HashMap<FlyString, Variable> variables, EnvironmentRecord* parent_scope)
    : EnvironmentRecord(parent_scope)
    , m_variables(move(variables))
{
}

DeclarativeEnvironmentRecord::DeclarativeEnvironmentRecord(HashMap<FlyString, Variable> variables, EnvironmentRecord* parent_scope, EnvironmentRecordType environment_record_type)
    : EnvironmentRecord(parent_scope)
    , m_environment_record_type(environment_record_type)
    , m_variables(move(variables))
{
}

DeclarativeEnvironmentRecord::~DeclarativeEnvironmentRecord()
{
}

void DeclarativeEnvironmentRecord::visit_edges(Visitor& visitor)
{
    Base::visit_edges(visitor);
    visitor.visit(m_this_value);
    visitor.visit(m_new_target);
    visitor.visit(m_current_function);
    for (auto& it : m_variables)
        visitor.visit(it.value.value);
}

Optional<Variable> DeclarativeEnvironmentRecord::get_from_environment_record(FlyString const& name) const
{
    return m_variables.get(name);
}

void DeclarativeEnvironmentRecord::put_into_environment_record(FlyString const& name, Variable variable)
{
    m_variables.set(name, variable);
}

bool DeclarativeEnvironmentRecord::delete_from_environment_record(FlyString const& name)
{
    return m_variables.remove(name);
}

Value DeclarativeEnvironmentRecord::get_super_base()
{
    if (m_environment_record_type != EnvironmentRecordType::Function)
        return {};
    VERIFY(m_current_function);
    auto home_object = m_current_function->home_object();
    if (!home_object.is_object())
        return {};
    return home_object.as_object().prototype();
}

bool DeclarativeEnvironmentRecord::has_this_binding() const
{
    // More like "is_capable_of_having_a_this_binding".
    switch (m_environment_record_type) {
    case EnvironmentRecordType::Declarative:
    case EnvironmentRecordType::Object:
        return false;
    case EnvironmentRecordType::Function:
        return this_binding_status() != ThisBindingStatus::Lexical;
    case EnvironmentRecordType::Module:
        return true;
    }
    VERIFY_NOT_REACHED();
}

Value DeclarativeEnvironmentRecord::get_this_binding(GlobalObject& global_object) const
{
    VERIFY(has_this_binding());
    if (this_binding_status() == ThisBindingStatus::Uninitialized) {
        vm().throw_exception<ReferenceError>(global_object, ErrorType::ThisHasNotBeenInitialized);
        return {};
    }
    return m_this_value;
}

void DeclarativeEnvironmentRecord::bind_this_value(GlobalObject& global_object, Value this_value)
{
    VERIFY(has_this_binding());
    if (m_this_binding_status == ThisBindingStatus::Initialized) {
        vm().throw_exception<ReferenceError>(global_object, ErrorType::ThisIsAlreadyInitialized);
        return;
    }
    m_this_value = this_value;
    m_this_binding_status = ThisBindingStatus::Initialized;
}

}
