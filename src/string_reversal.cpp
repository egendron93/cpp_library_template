/**
 * @file string_reversal.cpp
 * @date 2021-06-28
 */

#include <string_reversal.hpp>

#include <gsl/gsl>

namespace string_reversal {

namespace detail {

constexpr std::array<char, kPrintableAsciiCount> GetPrintableAsciiCharacters() {
    auto printable_ascii = std::array<char, kPrintableAsciiCount>{};
    auto index = size_t{0};

    for (char i = ' '; i <= '~'; ++i) {
        printable_ascii[index] = i;
        index++;
    }
    return printable_ascii;
}

bool IsPrintableAsciiCharacters(const std::string& s) {
    if (s.empty()) return false;
    constexpr auto printable_ascii_chars = std::array<char, kPrintableAsciiCount>{
        GetPrintableAsciiCharacters()};
    const auto ascii_compare = std::string{printable_ascii_chars.begin(), 
                                             printable_ascii_chars.end()};
    return s.find_first_not_of(ascii_compare) == std::string::npos;
}

} /* namespace detail */

void ReverseString(std::string& s) {
    Expects(s.length() >= detail::kMinStringSize);
    Expects(s.length() <= detail::kMaxStringSize);
    Expects(detail::IsPrintableAsciiCharacters(s));
    auto left = size_t{0};
    auto right = size_t{s.size() - 1};
        
    while (left < right) {
        auto temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

} /* namespace hello */