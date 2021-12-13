
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

#include <cstring>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

void read_file(std::string filename, std::vector<int32_t>& data);

#endif
