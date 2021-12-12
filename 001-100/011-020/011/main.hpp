
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

#include <algorithm>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

static const uint32_t N = 20;

void read_file(std::string filename, uint32_t** param);

#endif
