#include <iostream>
#include <algorithm>
#include <exception>

#include "./file.hpp"
#include "./makefile_generator.hpp"

void set_option(std::string& option,std::string val){
    std::string temp = val;
    temp.erase(std::remove_if(temp.begin(), temp.end(), isspace), temp.end());
    if(temp.length()<=0){
        return;
    }else{
        option = val;
    }

}

int main(int argc, char** argv){

    if(argc<2 || argc>3){
        std::cerr<<"Error : Please give a file to generate makefile for."<<std::endl;
        std::cerr<<"Usage : mkgen <filename> [-e]"<<std::endl;
        return 1;
    }

    std::string file = argv[1];
    mk_data data;
    std::string tmp;

    if(argc == 3){
        std::cout<<"Default Options are :"<<std::endl;
        std::cout<<"C Compiler :"<<data.c_comp<<std::endl;
        std::cout<<"C++ compiler : "<<data.cpp_comp<<std::endl;
        std::cout<<"Compiler flags : (None)"<<data.c_flags<<std::endl;
        std::cout<<"Name of Generated Makefile : "<<data.mkf_name<<std::endl;
        std::cout<<"Name of Final executable file : "<<data.out_name<<std::endl;
        std::cout<<"Add statement for removeing all .o files (rm ./*.o) in Makefile : "<<"False"<<std::endl;
    
        std::cout<<"Please give The change values , if a field is left empty then the default value will be considered."<<std::endl;

        std::cout<<"C Compiler :\t";
        std::getline(std::cin,tmp);
        set_option(data.c_comp,tmp);

        std::cout<<"C++ compiler : \t";
        std::getline(std::cin,tmp);
        set_option(data.c_comp,tmp);
        
        std::cout<<"Compiler flags : \t";
        std::getline(std::cin,tmp);
        set_option(data.c_flags,tmp);

        std::cout<<"Name of Generated Makefile : \t";
        std::getline(std::cin,tmp);
        set_option(data.mkf_name,tmp);
        std::cout<<"Name of Final executable file : \t";
        std::getline(std::cin,tmp);
        set_option(data.out_name,tmp);

        std::cout<<"Add statement for removeing all .o files (rm ./*.o) in Makefile\n"<<"(y/Y for yes , everything else is no) \t";
        std::getline(std::cin,tmp);
        if(tmp =="y" || tmp == "Y"){
            data.clean_o = true;
        }else{
            data.clean_o = false;
        }

    }    

    makefile_generator mkgen;
    mkgen.set_options(data);
    try{
        mkgen.generate_makefile(file);
    }catch(const mkgen_exception& e){
        std::cerr<<"Error Occured :\n\t";
        std::cerr<<e.what();
        return 2;
    }



    return 0;
}

