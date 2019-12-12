#include <iostream>

#include "./file.hpp"
#include "./makefile_generator.hpp"

int main(int argc, char[][]argv){

    if(argc<2){
        std::cerr<<"Error : Please give a file to generate makefile for."<<std::endl;
        std::cerr<<"Usage : mkgen <filename> [-e]"<<std::endl;
    }


}

