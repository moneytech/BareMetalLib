//
// Copyright (c) 2018 Wee Loong Kuan
//
// This file is licensed under the MIT license. For more details, see the LICENSE.md file in the
// top-level directory of this distribution.
//

#include <bml_testbench.hpp>
#include <bml/type_traits/remove_cv.hpp>
#include <bml/type_traits/is_same.hpp>

template <typename T, typename U>
auto check_result() noexcept -> void
{
    static_assert(bml::is_same_v<typename bml::remove_cv<T>::type, U>);
    static_assert(bml::is_same_v<bml::remove_cv_ty<T>, U>);
}

auto test_main() noexcept -> int
{
    // Check that the result is the same as the input when the input is unqualified.
    {
        check_result<void, void>();
        check_result<int, int>();
        check_result<int[3], int[3]>();
        check_result<int*, int*>();
        check_result<double volatile*, double volatile*>();
        check_result<bmltb::class_type, bmltb::class_type>();
        check_result<bmltb::enum_class, bmltb::enum_class>();
        check_result<bmltb::union_type, bmltb::union_type>();
        check_result<bmltb::incomplete_class, bmltb::incomplete_class>();
        check_result<int bmltb::class_type::*, int bmltb::class_type::*>();
        
        check_result<int&, int&>();
        check_result<int&&, int&&>();
        check_result<auto (int) -> void, auto (int) -> void>();
        check_result<auto (int, ...) noexcept -> void, auto (int, ...) noexcept -> void>();
        check_result<auto (int) const && -> void, auto (int) const && -> void>();
        check_result<auto () const && noexcept -> void, auto () const && noexcept -> void>();
    }
    
    // Check that the result is the same as the unqualified version of the input when the input is
    // const-qualified.
    {
        check_result<void const, void>();
        check_result<int const, int>();
        check_result<int const[3], int[3]>();
        check_result<int* const, int*>();
        check_result<double volatile* const, double volatile*>();
        check_result<bmltb::class_type const, bmltb::class_type>();
        check_result<bmltb::enum_class const, bmltb::enum_class>();
        check_result<bmltb::union_type const, bmltb::union_type>();
        check_result<bmltb::incomplete_class const, bmltb::incomplete_class>();
        check_result<int bmltb::class_type::* const, int bmltb::class_type::*>();
    }

    // Check that the result is the same as the unqualified version of the input when the input is 
    // volatile-qualified.
    {
        check_result<void volatile, void>();
        check_result<int volatile, int>();
        check_result<int volatile[3], int[3]>();
        check_result<int* volatile, int*>();
        check_result<double volatile* volatile, double volatile*>();
        check_result<bmltb::class_type volatile, bmltb::class_type>();
        check_result<bmltb::enum_class volatile, bmltb::enum_class>();
        check_result<bmltb::union_type volatile, bmltb::union_type>();
        check_result<bmltb::incomplete_class volatile, bmltb::incomplete_class>();
        check_result<int bmltb::class_type::* volatile, int bmltb::class_type::*>();
    }

    // Check that the result is the same as the unqualified version of the input when the input is
    // const-volatile-qualified.
    {
        check_result<void const volatile, void>();
        check_result<int const volatile, int>();
        check_result<int const volatile[3], int[3]>();
        check_result<int* const volatile, int*>();
        check_result<double volatile* const volatile, double volatile*>();
        check_result<bmltb::class_type const volatile, bmltb::class_type>();
        check_result<bmltb::enum_class const volatile, bmltb::enum_class>();
        check_result<bmltb::union_type const volatile, bmltb::union_type>();
        check_result<bmltb::incomplete_class const volatile, bmltb::incomplete_class>();
        check_result<int bmltb::class_type::* const volatile, int bmltb::class_type::*>();
    }
    
    return 0;
}