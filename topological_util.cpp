
#include <list>
#include <iostream>
#include <exception>


#include "./topological_util.hpp"

void topological_util::prepare_maps(const dependency_graph& dg){
    auto& graph = dg.get_graph();
    visited.clear();
    circ_stack.clear();
    for(auto itr = graph.begin();itr!= graph.end();++itr){
        auto vertex = itr->first;
        visited[vertex] = false;
        circ_stack[vertex] = false;
    }
}

bool topological_util::conatains_circular_dependencies(const dependency_graph& dg){

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

bool topological_util::is_cyclic(std::string current,const dependency_graph& dg){
    
    if(!visited[current]){
        visited[current] = true;
        circ_stack[current] = true;
        dep_list.push_back(current);

        auto adj_list = dg.get_adjecency_list(current);
        
        for(auto itr = adj_list.begin();itr!= adj_list.end();++itr){
            auto adj_v = *itr;
            if(!visited[adj_v] && is_cyclic(adj_v,dg)){
                return true;
            }else if(circ_stack[adj_v]){
                return true;
            }
        }
         
    }
    circ_stack[current] = false;
    return false;
}

std::list<std::string> topological_util::get_topological_order(const dependency_graph& dg){
    
    std::list<std::string> ret;

    if(conatains_circular_dependencies(dg)){
        std::string dep_string = "";
        for (auto &dep : dep_list){
            dep_string += dep+" -> ";
        }
        throw mkgen_exception("Given Files contain Circular Dependencies : "+dep_string);
    }

    prepare_maps(dg);
    auto graph = dg.get_graph();
    
    for(auto itr = graph.begin();itr!= graph.end();++itr){
        auto vertex = itr->first;
        if(!visited[vertex]){
            topological_sort(vertex,dg);
        }
    }

    while(!topo_stack.empty()){
        ret.push_back(topo_stack.top());
        topo_stack.pop();
    }
    return ret;

}

void topological_util::topological_sort(std::string vertex,const dependency_graph& dg){

    visited[vertex] = true;

    auto adj_list = dg.get_adjecency_list(vertex);
    for(auto itr = adj_list.begin();itr!=adj_list.end();++itr){
        auto adj_v = *itr;
        if(!visited[adj_v]){
            topological_sort(adj_v,dg);
        }
    }
    topo_stack.push(vertex);
}


void topological_util::print_topologic_order(const dependency_graph& dg) const{
    
    topological_util mkgen;
    auto topo_order = mkgen.get_topological_order(dg);
    for(auto itr = topo_order.begin();itr!= topo_order.end();++itr){
        std::cout<<*itr<<"\t";
    }
    std::cout<<std::endl;
}