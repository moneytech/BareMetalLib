//
// Copyright (c) 2019 Wee Loong Kuan
//
// This file is licensed under the MIT license. For more details, see the LICENSE.md file in the
// top-level directory of this distribution.
//

#include <bml_testbench.hpp>
#include <bml/utilities/forward.hpp>

struct arg {};
auto get_arg_cv() noexcept -> arg const volatile { return arg(); };

auto test_main() noexcept -> int
{
    // Check that a compile error occurs when forward is invoked with a cv-qualified rvalue argument
    // and T does not have the same level of cv-qualification.
    {
        static_cast<void>(bml::forward<arg const&>(get_arg_cv()));
    }

    return 0;
}