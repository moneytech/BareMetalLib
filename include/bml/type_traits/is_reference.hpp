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

#pragma once
#include "bool_constant.hpp"
#include "is_lvalue_reference.hpp"
#include "is_rvalue_reference.hpp"

namespace bml
{
    //
    // See std::is_reference.
    //
    template <typename T>
    struct is_reference : bool_constant<is_lvalue_reference_v<T> || is_rvalue_reference_v<T>> {};

    //
    // See std::is_reference_v.
    //
    template <typename T>
    inline constexpr auto is_reference_v = bool(is_reference<T>::value);
}
