#include <map>
#include <set>
#include <iostream>

#include "./file.hpp"
#include "./reader.hpp"
#include "./dependency_graph.hpp"

void dependency_graph::add_dependency(file of,file dependency){

    /*auto itr = graph.begin();
    for(;itr!=graph.end();++itr){
        if(graph.key_comp()(itr->first,of)){
            //std::cout<<"Adding dep : To "<<of.get_file_name()<<" Of "<<dependency.get_file_name()<<std::endl;
            itr->second.insert(dependency);
            return;
        }
    }
    std::cout<<"Adding dep : To "<<of.get_file_name()<<" Of "<<dependency.get_file_name()<<std::endl;
    auto& set = graph[of];
    set.insert(dependency);
    return;*/

    auto itr = graph.find(of.get_file_name());
    if(itr != graph.end()){
        //std::cout<<"IN INsert if"<<std::endl;
        auto& set = graph.at(of.get_file_name());
        set.insert(dependency.get_file_name());
    }else{
        graph.insert({of.get_file_name(),{dependency.get_file_name()}});
        //std::cout<<"IN INsert else;"<<std::endl;
        
    }
}

bool dependency_graph::is_dependent(const file& from,const file& dependency){
    
    /*auto itr = graph.begin();
    for(;itr!=graph.end();++itr){
        if(graph.key_comp()(itr->first,from)){
            auto set_itr = itr->second.begin();
            for(;set_itr!=itr->second.end();++set_itr){
                if(graph.key_comp()(*set_itr,dependency)){
                    return true;
                }
            }
        }
    }
    return false;*/
    
    auto itr = graph.find(from.get_file_name());
    if(itr == graph.end()){
        return false;
    }
    auto set = graph.at(from.get_file_name());
    auto itr1 = set.find(dependency.get_file_name());
    if(itr1 ==set.end()){
        return false;
    }

    return true;

}