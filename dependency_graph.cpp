#include <map>
#include <set>
#include <iostream>

#include "./dependency_graph.hpp"


void dependency_graph::add_dependency(const std::string of,const std::string dependency){

    auto itr = graph.find(of);
    if(itr != graph.end()){
        auto& set = graph.at(of);
        set.insert(dependency);
    }else{
        graph.insert({of,{dependency}});        
    }
}

bool dependency_graph::is_dependent(const std::string& from,const std::string& dependency){
    
    auto itr = graph.find(from);
    if(itr == graph.end()){
        return false;
    }
    auto set = graph.at(from);
    auto itr1 = set.find(dependency);
    if(itr1 ==set.end()){
        return false;
    }
    return true;

}

std::set<std::string> dependency_graph::get_adjecency_list(const std::string& v) const {
    auto itr = graph.find(v);
    if(itr != graph.end()){
       return itr->second;
    }else{
        //throw std::string("Error");
        return std::set<std::string>();
    }
}

void dependency_graph::print_dependencies(){
    for(auto t = graph.begin();t!= graph.end();++t){
        for(auto s = t->second.begin();s!=t->second.end();++s){
            std::cout<<"Key : "<<t->first.c_str()<<" Value : "<<s->c_str()<<std::endl;
        }
    }
}