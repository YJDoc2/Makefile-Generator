#include <set>
#include <list>
#include <fstream>
#include <iostream>

#include "./dependency_graph_generator.hpp"


using dgg = dependency_graph_generator;

dependency_graph dgg::get_dependency_graph(const std::string& f){
    enqued.push_back(f);
    while(!enqued.empty()){
        std::string f = enqued.front();
        enqued.pop_front();
        visited.insert(f);
        generate_dependencies(f);
    }
    return dg;
}

void dgg::generate_dependencies(const std::string& f){

    reader r_code(f);
    while(!r_code.is_done()){
        std::string tmp = r_code.get_next_custom_dependency();
        if(tmp.compare("")==0){
            continue;
        }
        dg.add_dependency(f,tmp);
        if(!is_visited(tmp)){
            enqued.push_back(tmp);
        }
    }
}

bool dgg::is_visited(const std::string& f){
    return (visited.find(f) != visited.end());
    
}
