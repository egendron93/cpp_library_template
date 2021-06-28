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

constexpr std::array<char, kPrintableAsciiCount> kPrintableAsciiCharacters{
    GetPrintableAsciiCharacters()};

bool IsPrintableAsciiCharacters(std::string& s) {
    const auto printable_ascii = std::string{kPrintableAsciiCharacters.begin(), 
                                             kPrintableAsciiCharacters.end()};
    return s.find_first_not_of(printable_ascii) == std::string_view::npos;
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