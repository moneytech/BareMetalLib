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
#include "../detail/macros/compiler_specific_file.hpp"
#include BML_COMPILER_SPECIFIC_FILE(detail/compiler, is_abstract.hpp)

namespace bml
{
    //
    // See std::is_abstract.
    //
    template <typename T>
    struct is_abstract : detail::is_abstract_detail::impl<T> {};

    //
    // See std::is_abstract_v.
    //
    template <typename T>
    inline constexpr auto is_abstract_v = bool(is_abstract<T>::value);
}
