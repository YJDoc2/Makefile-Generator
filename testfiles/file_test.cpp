#include <iostream>

#include "./file.cpp"

void print_files(std::string file){
    std::cout<<"File : "<<file<<std::endl;
    std::cout<<"Code-File : "<<get_code_file(file)<<std::endl;
    std::cout<<"H-File : "<<get_H_file(file)<<std::endl;
    std::cout<<"O-File : "<<get_o_file(file)<<std::endl;
    std::cout<<std::endl;
}

int main(){

    auto c_file = "xyz.c";
    auto h_file = "xyz.h";
    auto cpp_file = "xyz.cpp";
    auto hpp_file = "xyz.hpp";

    print_files(c_file);
    print_files(h_file);
    print_files(cpp_file);
    print_files(hpp_file);

    
    


    return 0;
}