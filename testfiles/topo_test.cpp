#include <iostream>

#include "topological_util.cpp"


int main(){

    dependency_graph dg1,dg2,dg3,dg4,dg5,dg6,dg7;
    topological_util mkgen;


    dg1.add_dependency("f1","f2");
    dg1.add_dependency("f2","f3");
    dg1.add_dependency("f2","f4");
    
    if(mkgen.conatains_circular_dependencies(dg1)){
        std::cout<<"Err"<<std::endl;
    }else{
        std::cout<<"First Graph does not contain any cycles"<<std::endl;
    }

    std::cout<<"Topological Order is :";
    mkgen.print_topologic_order(dg1);
    std::cout<<std::endl;


    dg2.add_dependency("f1","f2");
    dg2.add_dependency("f2","f3");
    dg2.add_dependency("f3","f1");

    if(mkgen.conatains_circular_dependencies(dg2)){
        std::cout<<"Second Graph does contains cyclic dependencies"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }

    dg3.add_dependency("f1","f2");
    dg3.add_dependency("f2","f4");
    dg3.add_dependency("f2","f3");
    dg3.add_dependency("f2","f5");
    dg3.add_dependency("f4","f5");

    if(mkgen.conatains_circular_dependencies(dg3)){
        std::cout<<"Err"<<std::endl;
    }else{
        std::cout<<"Third Graph does not contain any cyclic dependencies"<<std::endl;
        
    }

    std::cout<<"Topological Order is :";
    mkgen.print_topologic_order(dg3);
    std::cout<<std::endl;

    dg4.add_dependency("f1","f3");
    dg4.add_dependency("f2","f3");
    dg4.add_dependency("f3","f4");

    if(mkgen.conatains_circular_dependencies(dg4)){
        std::cout<<"Err"<<std::endl;
    }else{
        std::cout<<"Fourth Graph does not contain any cyclic dependencies"<<std::endl;
        
    }

    std::cout<<"Topological Order is :";
    mkgen.print_topologic_order(dg4);
    std::cout<<std::endl;

    dg5.add_dependency("f1","f2");
    dg5.add_dependency("f1","f4");
    dg5.add_dependency("f2","f3");
    dg5.add_dependency("f3","f4");
    dg5.add_dependency("f4","f4");

    if(mkgen.conatains_circular_dependencies(dg5)){
        std::cout<<"Fifth Graph does contains cyclic dependencies"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }
    
    dg6.add_dependency("f1","f3");
    dg6.add_dependency("f1","f2");
    dg6.add_dependency("f2","f2");

    if(mkgen.conatains_circular_dependencies(dg6)){
        std::cout<<"Sixth Graph does contains cyclic dependencies"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }

    dg7.add_dependency("f1","f2");
    dg7.add_dependency("f1","f3");
    dg7.add_dependency("f3","f2");
    dg7.add_dependency("f2","f2");

    if(mkgen.conatains_circular_dependencies(dg7)){
        std::cout<<"Seventh Graph does contains cyclic dependencies"<<std::endl;
    }else{
        std::cout<<"Err"<<std::endl;
    }

    return 0;
}