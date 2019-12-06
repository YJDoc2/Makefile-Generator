#include <set>
#include <list>
#include <fstream>
#include <iostream>
#include "./file.hpp"
#include "./dependency_graph.cpp"
#include "./dependency_graph_generator.hpp"


using dgg = dependency_graph_generator;

dependency_graph dgg::get_dependency_graph(const file& f){
    enqued.push_back(f);
    while(!enqued.empty()){
        file f = enqued.front();
        enqued.pop_front();
        visited.insert(f);
        //std::cout<<"IN get_dep_graph while, File : "<<f.get_file_name()<<std::endl;
        generate_dependencies(f);
    }
    return dg;
}

void dgg::generate_dependencies(const file& f){

    reader r_code(f.get_file_name());
    //std::cout<<"IN gen_dep , File : "<<f.get_file_name()<<" Yeah..."<<std::endl;
    while(!r_code.is_done()){
        file tmp = r_code.get_next_custom_dependency();
        //std::cout<<"IN gen_dep while, File : "<<tmp.get_file_name()<<" Yeah..."<<std::endl;
        if(tmp == file("")){
            continue;
        }
        dg.add_dependency(f,tmp);
        //std::cout<<"Adding dep : To "<<f.get_file_name()<<" Of "<<tmp.get_file_name()<<std::endl;
        if(!is_visited(tmp)){
            enqued.push_back(tmp);
        }
        
    }



}

bool dgg::is_visited(const file& f){
    return (visited.find(f) != visited.end());
    
}