/**
 * @file string_reversal_unit.cpp
 * @author Edwin Gendron
 * @date 2021-06-28
 */

#include <gtest/gtest.h>

#include <string_reversal.hpp>

using namespace string_reversal;
using namespace string_reversal::detail;

/**
 * @pre empty string
 * @post returns false
 */
TEST(StringReversalUnit, IsPrintableAsciiCharactersEmptyStringReturnsFalse) {
    const auto empty_string = std::string{};
    ASSERT_FALSE(IsPrintableAsciiCharacters(empty_string));
}

/**
 * @pre string contains all printable characters
 * @post returns true
 */
TEST(StringReversalUnit, IsPrintableAsciiCharactersAllPrintableCharactersReturnsTrue) {
    const auto printable = std::string{"yay all printable characters"};
    ASSERT_TRUE(IsPrintableAsciiCharacters(printable));
}

/**
 * @pre empty string
 * @post program terminated
 */
TEST(StringReversalUnit, ReverseStringEmptyStringExceptionThrown) {
    auto empty_string = std::string{};
    ASSERT_DEATH(ReverseString(empty_string), "");
}

/**
 * @pre string of size 1
 * @post string remains the same
 */
TEST(StringReversalUnit, ReverseStringStringSizeOneExceptionThrown) {
    auto test_string = std::string{"a"};
    auto temp_test_string = std::string{test_string};
    ReverseString(test_string);
    ASSERT_EQ(temp_test_string, test_string);
}

/**
 * @pre string of size 100005, 5 chars too large.
 * @post program terminated
 */
TEST(StringReversalUnit, ReverseStringStringSizeTooLargeExceptionThrown) {
    auto test_string = std::string(100005, 'a');
    ASSERT_DEATH(ReverseString(test_string), "");
}

/**
 * @pre string to reverse within the specified size and larger than 1 char
 * @post string is reversed
 */
TEST(StringReversalUnit, ReverseStringStringSizeAcceptableAndGreaterThanOneReversedStringReturned) {
    auto test_string = std::string{"abcdefghijklmnopqrstuvwxyz"};
    const auto expected_reversed_result = 
        std::string{"zyxwvutsrqponmlkjihgfedcba"};
    ReverseString(test_string);
    ASSERT_EQ(test_string, expected_reversed_result);
}
