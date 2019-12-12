#include <iostream>
#include <exception>

#include "./makefile_generator.hpp"

int main(){

    makefile_generator mkgen;
    mk_data data;
    data.out_name = "test";
    data.mkf_name = "./mktest";
    mkgen.set_options(data);
    try{
        mkgen.generate_makefile("./main.cpp");
    }catch(const mkgen_exception& e){
        std::cerr<<"Err  :"<<e.what()<<std::endl;
    }

    return 0;
}

