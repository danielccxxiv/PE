
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstddef>
#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include "../../../Misc/Digit_Manipulation/palindrome.hpp"

int32_t odd_size_palindrome(int32_t num);
int32_t even_size_palindrome(int32_t num);

#endif
