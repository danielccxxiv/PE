
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <cstddef>
#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <boost/filesystem/fstream.hpp>

static const size_t num_len = 1000;
static const size_t prod_len = 13;

void read_file(std::string filename, int32_t** param);
int64_t product(int32_t* digits, size_t start);

#endif
