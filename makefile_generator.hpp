
#include <iostream>
#include <fstream>

#include "./topological_util.hpp"


class makefile_generator{

    private:
        mk_data data;
        std::ofstream writer;
        dependency_graph dg;
        void add_outputfile_to_mkf(std::list<std::string> t_order);
        void add_dependencies_to_mkf(std::list<std::string> t_order);
        
        
    public:
        void set_options(mk_data& in_data);
        void generate_makefile(std::string main_file);



};