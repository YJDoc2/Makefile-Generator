
#include <iostream>
#include "../topological_util.hpp"

int main(){

    dependency_graph_generator dgg;
    dependency_graph dg;
    topological_util mkgen;

    std::string f("./test_file.cpp");

    dg = dgg.get_dependency_graph(f);
    mkgen.print_topologic_order(dg);


    return 0;
}