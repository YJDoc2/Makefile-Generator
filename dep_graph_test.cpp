#include <iostream>
#include "./dependency_graph.cpp"





int main(){
    file f1("a.c");
    file f2("b.c");
    file f3("c.c");

    dependency_graph dg;
    dg.add_dependency(f1,f2);
    dg.add_dependency(f1,f3);
    auto g = dg.get_set();

    if(dg.is_dependent(f1,f2)){
        std::cout<<"f1 depends on f2"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }

    if(dg.is_dependent(f2,f3)){
        std::cout<<"Err"<<std::endl;
    }else{
        std::cout<<"f2 does not depend on f3"<<std::endl;
    }

    if(dg.is_dependent(f2,f1)){
        std::cout<<"Err"<<std::endl;
    }else{
        std::cout<<"f2 does not depend on f1"<<std::endl;
    }

    return 0;
}