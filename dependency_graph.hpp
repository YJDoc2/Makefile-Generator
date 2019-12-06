#include <map>
#include <set>

#include "./file.hpp"
#include "./reader.cpp"

#ifndef _dep_graph_
#define _dep_graph_

struct temp{
    bool operator()(const file& f1, const file& f2) const {
        std::string temp1 = f1.get_file_name();
        std::string temp2 = f2.get_file_name();
        return (temp1.compare(temp2)==0);
    }
};

class dependency_graph{

    private:
        std::map<std::string,std::set<std::string>> graph;
    
    public:
        dependency_graph():graph({}){
        }
        void add_dependency(file of,file dependency);
        bool is_dependent(const file& from,const file& dependency);
        auto get_set(){
            return graph;
        }

};
#endif