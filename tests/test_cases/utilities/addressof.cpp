//
// Copyright (c) 2019 Wee Loong Kuan
//
// BareMetalLib is based on libc++ (https://libcxx.llvm.org/).
// 
// This file is licensed under under the Apache License v2.0 with LLVM Exceptions. For more details,
// see the LICENSE.md file in the top-level directory of this distribution, or copy at 
// https://llvm.org/LICENSE.txt.
//
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//

#include <bml_testbench.hpp>
#include <bml/utilities/addressof.hpp>

struct empty {};

struct overloaded_addr_op
{
    auto operator&() -> void {}
    
    auto my_addr() noexcept -> overloaded_addr_op*
    {
        return this;
    }
    
    constexpr auto my_addr() const noexcept -> overloaded_addr_op const*
    {
        return this;
    }
};

union overloaded_mem
{
    int i;
    overloaded_addr_op o;
};

auto test_main() noexcept -> int
{
    // Check that addressof returns the address of lvalues when their types do not have overloaded
    // address-of operators.
    {
        auto i = 1;
        auto const ci = 1;
        auto volatile vi = 1;
        auto const volatile cvi = 1;
        
        static_assert(bml::addressof(i) == &i);
        static_assert(bml::addressof(ci) == &ci);
        static_assert(bml::addressof(vi) == &vi);
        static_assert(bml::addressof(cvi) == &cvi);
        
        auto e = empty();
        auto const ce = empty();
        auto volatile ve = empty();
        auto const volatile cve = empty();
        
        static_assert(bml::addressof(e) == &e);
        static_assert(bml::addressof(ce) == &ce);
        static_assert(bml::addressof(ve) == &ve);
        static_assert(bml::addressof(cve) == &cve);
    }
    
    // Check that addressof returns the address of lvalues when their types have overloaded
    // address-of operators.
    {
        auto o = overloaded_addr_op();
        bmltb_assert(bml::addressof(o) == o.my_addr());
        
        constexpr auto co = overloaded_addr_op();
        static_assert(bml::addressof(co) == co.my_addr());
    }
    
    // Check that addressof returns the same result for union members.
    {
        union
        {
            int i;
            double d;
            overloaded_addr_op o;
        };
        
        bmltb_assert(bml::addressof(i) == &i);
        bmltb_assert(static_cast<void*>(bml::addressof(i)) == bml::addressof(d));
        bmltb_assert(static_cast<void*>(bml::addressof(i)) == bml::addressof(o));
    }
    
    return 0;
}
