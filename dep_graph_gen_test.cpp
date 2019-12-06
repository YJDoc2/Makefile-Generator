#include "./dependency_graph_generator.cpp"
#include <iostream>

int main(){

    dependency_graph dg;
    dependency_graph_generator dgg;
    file f("./test_file.cpp");
    //std::cout<<"IN main , file is "<<f.get_file_name()<<std::endl;
    dg = dgg.get_dependency_graph(f);

    auto g = dg.get_set();
    for(auto t = g.begin();t!= g.end();++t){
        for(auto s = t->second.begin();s!=t->second.end();++s){
            std::cout<<"Key : "<<t->first.c_str()<<" Value : "<<s->c_str()<<std::endl;
        }
    }
    if(dg.is_dependent(file("./reader.hpp"),file("./file.hpp"))){
        std::cout<<"reader.hpp is dependent on file.hpp"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }
    if(dg.is_dependent(file("./test_file.cpp"),file("./file.hpp"))){
        std::cout<<"test_file.cpp is dependent on file.hpp"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }

    if(dg.is_dependent(file("./file.cpp"),file("./file.hpp"))){
        std::cout<<"Err"<<std::endl;
    }else{
        std::cout<<"This was more of a sanity check"<<std::endl;
        
    }

    return 0;
}