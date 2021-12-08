
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstring>
#include <iostream>

#include <boost/container/set.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/tokenizer.hpp>

int read_file(std::string filename, boost::container::set<std::string>* data);

#endif
