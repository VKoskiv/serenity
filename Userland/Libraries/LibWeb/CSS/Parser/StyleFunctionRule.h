/*
 * Copyright (c) 2020-2021, the SerenityOS developers.
 * Copyright (c) 2021, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/RefCounted.h>
#include <AK/String.h>
#include <AK/Vector.h>

namespace Web::CSS {

class StyleComponentValueRule;

class StyleFunctionRule : public RefCounted<StyleFunctionRule> {
    friend class Parser;

public:
    StyleFunctionRule(String name);
    ~StyleFunctionRule();

    String const& name() const { return m_name; }
    Vector<StyleComponentValueRule> const& values() const { return m_values; }
    // FIXME: This method is a temporary hack while much of the parser still expects a string, rather than tokens.
    String values_as_string() const
    {
        return "";
    }

    String to_string() const;

private:
    String m_name;
    Vector<StyleComponentValueRule> m_values;
};
}
