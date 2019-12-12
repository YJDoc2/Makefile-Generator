#include <algorithm>

#include "./file.hpp"
#include "./makefile_generator.hpp"

void makefile_generator::set_compile_options(mk_data in_data){
    data = in_data;    
}

void makefile_generator::generate_makefile(std::string main_file) {

    dependency_graph dg;
    dependency_graph_generator dgg;
    topological_util tu;
    writer.open(data.mkf_name);


    dg = dgg.get_dependency_graph(main_file);
    this->dg = dg;

    if(tu.conatains_circular_dependencies(dg)){
        throw std::string("Contains circular dependencies");
    }
    auto t_order = tu.get_topological_order(dg);

    add_outputfile_to_mkf(t_order);

    add_dependencies_to_mkf(t_order);

    
}

void makefile_generator::add_outputfile_to_mkf(std::list<std::string> t_order) {

    writer<<data.out_name<<" : ";

    bool is_all_c = true;
    std::set<std::string> o_files;

    for (auto &file : t_order){
        auto type = get_type(file);
        is_all_c = is_all_c && (type == filetype::C || type == filetype::H);
        o_files.insert(get_o_file(file));
    }
    for (auto &o_file : o_files){
        writer<<o_file<<" ";
    }
    writer<<std::endl;
    writer<<"\t";
    if(is_all_c){
        writer<<data.c_comp<<" -o "<<data.out_name<<" ";
    }else{
        writer<<data.cpp_comp<<" -o "<<data.out_name<<" ";
    }
    
    for (auto &o_file : o_files){
        writer<<o_file<<" ";
    }
    writer<<std::endl<<std::endl;
}

void makefile_generator::add_dependencies_to_mkf(std::list<std::string> t_order){

    for (auto &o_dep : t_order){

        auto o_file = get_o_file(o_dep);
        auto dep_list = dg.get_adjecency_list(o_dep);

        if(dep_list.size()<2){
            std::ifstream tmp(get_code_file(o_dep));
            if(tmp.bad()){
                tmp.close();
                continue;
            }
        }

        auto dep_str = get_dep_str(o_dep,dep_list);
        writer<<o_file<<" : ";
        writer<<dep_str<<std::endl;
        writer<<"\t"<<get_compiler(o_dep,data)<<" -c "<<get_code_file(o_dep)<<std::endl<<std::endl;

    }
}