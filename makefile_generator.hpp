
#include <iostream>

#include "file.hpp";
#include "./dependency_graph_generator.hpp"

struct mk_data{
    std::string c_comp = "gcc";
    std::string cpp_comp = "g++";
    std::string comp_op ="";
    std::string out_name = "a.out";
    bool clean_o = true;

};

class makefile_generator{

    private:
        mk_data data;
        
    public:
        void set_compile_options(mk_data in_data);
        void generate_makefile(std::string main_file) const;



};