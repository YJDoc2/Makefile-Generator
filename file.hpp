#include <string>
#include <exception>

#ifndef _file_
#define _file_

enum filetype{
    C,
    H,
    CPP,
    HPP,
    EMPTY
};



filetype get_type(const std::string& in);

#endif