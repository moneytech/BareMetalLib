#
# Copyright (c) 2019 Wee Loong Kuan
#
# BareMetalLib is based on libc++ (https://libcxx.llvm.org/).
# 
# This file is licensed under under the Apache License v2.0 with LLVM Exceptions. For more details,
# see the LICENSE.md file in the top-level directory of this distribution, or copy at 
# https://llvm.org/LICENSE.txt.
#
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#

bml_add_test("containers.variant" variant.cpp)
bml_add_compile_failure_test("containers.variant.fail.ctor_invalid_index"
    variant.fail.ctor_invalid_index.cpp "variant index is out of bounds.")
bml_add_compile_failure_test("containers.variant.fail.emplace_invalid_index"
    variant.fail.emplace_invalid_index.cpp "variant index is out of bounds.")
bml_add_compile_failure_test("containers.variant.fail.mem_get_invalid_index"
    variant.fail.mem_get_invalid_index.cpp "variant index is out of bounds.")
bml_add_compile_failure_test("containers.variant.fail.free_get_invalid_index"
    variant.fail.free_get_invalid_index.cpp "variant index is out of bounds.")
bml_add_compile_failure_test("containers.variant.fail.no_alts"
    variant.fail.no_alts.cpp "variant should have at least 1 alternative.")
bml_add_compile_failure_test("containers.variant.fail.void_alt"
    variant.fail.void_alt.cpp "variant cannot hold void types.")
bml_add_compile_failure_test("containers.variant.fail.array_alt"
    variant.fail.array_alt.cpp "variant cannot hold array types.")
bml_add_compile_failure_test("containers.variant.fail.ref_alt"
    variant.fail.ref_alt.cpp "variant cannot hold reference types.")