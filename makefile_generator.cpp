

#include "./makefile_generator.hpp"

void makefile_generator::prepare_maps(const dependency_graph& dg){
    auto& graph = dg.get_graph();
    visited.clear();
    rec_stack.clear();
    for(auto itr = graph.begin();itr!= graph.end();++itr){
        auto vertex = itr->first;
        visited[vertex] = false;
        rec_stack[vertex] = false;
    }
}

bool makefile_generator::conatains_circular_dependencies(const dependency_graph& dg){

    prepare_maps(dg);
    auto& graph = dg.get_graph();
    for(auto itr = graph.begin();itr!= graph.end();++itr){
        auto vertex = itr->first;  
        dg.get_adjecency_list(vertex);
        if(is_cyclic(vertex,dg)){
            return true;
        }
    }
    return false;
}

//Check 
bool makefile_generator::is_cyclic(std::string current,const dependency_graph& dg){
    
    if(!visited[current]){
        visited[current] = true;;
        rec_stack[current] = true;

        auto adj_list = dg.get_adjecency_list(current);
        
        for(auto itr = adj_list.begin();itr!= adj_list.end();++itr){
            auto adj_v = *itr;
            if(!visited[adj_v] && is_cyclic(adj_v,dg)){
                return true;
            }else if(rec_stack[adj_v]){
                return true;
            }
        }
         
    }
    rec_stack[current] = false;
    return false;
}