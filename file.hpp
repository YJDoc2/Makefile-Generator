#include <string>
#include <set>

#include "./mkgen_exception.hpp"

#ifndef _file_
#define _file_

enum filetype{
    C,
    H,
    CPP,
    HPP,
    EMPTY
};

struct mk_data{
    std::string mkf_name = "makefile";
    std::string c_comp = "gcc";
    std::string cpp_comp = "g++";
    std::string c_flags ="";
    std::string out_name = "a.out";
    bool clean_o = false;

};


filetype get_type(const std::string& in);
std::string get_o_file(const std::string);
std::string get_code_file(const std::string);
std::string get_H_file(const std::string);
std::string get_compiler(const std::string file,const mk_data data);
std::string get_dep_str(const std::string file,const std::set<std::string> list);
#endif