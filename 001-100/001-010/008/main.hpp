
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

#include <boost/filesystem/fstream.hpp>

static const uint32_t num_len = 1000;
static const uint32_t prod_len = 13;

void read_file(std::string filename, uint32_t** param);

uint64_t product(uint32_t* digits, uint32_t start);

#endif
