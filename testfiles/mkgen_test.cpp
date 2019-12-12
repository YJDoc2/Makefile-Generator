#include <iostream>

#include "./makefile_generator.hpp"

int main(){

    makefile_generator mkgen;
    mk_data data;
    data.out_name = "test";
    data.mkf_name = "./mktest";
    mkgen.set_compile_options(data);
    mkgen.generate_makefile("./mkgen_test.cpp");

    return 0;
}

