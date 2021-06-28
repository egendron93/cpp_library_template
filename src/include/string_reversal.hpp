/**
 * @file string_reversal.hpp
 * @date 2021-06-28
 * @brief Write a function that reverses a string. 
 * The input string is given as an array of characters s.
 * @link https://leetcode.com/problems/reverse-string/
 * @note Would obviously just use std::reverse algorithm
 * https://en.cppreference.com/w/cpp/algorithm/reverse
 */

#ifndef STRING_REVERSAL_HPP
#define STRING_REVERSAL_HPP

#include <array>
#include <string>

namespace string_reversal {

constexpr auto kPrintableAsciiCount = size_t{95};

constexpr std::array<char, kPrintableAsciiCount> GetPrintableAsciiCharacters();

bool IsPrintableAsciiCharacters(std::string& s);

/**
 * @brief Reverses a string of characters.
 * @pre 1 <= s.length <= 10^5
 * @pre s[i] is a printable ascii character. (this is more of an assertion)
 * @note Do not allocate extra space. Modify the input in-place with O(1) extra 
 *  memory.
 * @note Time complexity: O(N)
 * @note Space complexity: O(1)
 */
void ReverseString(std::string& s);

} /* namespace hello */

 #endif /* STRING_REVERSAL_HPP */