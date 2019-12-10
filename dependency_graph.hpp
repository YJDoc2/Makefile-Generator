#include <map>
#include <set>

#include "./reader.hpp"

#ifndef _dep_graph_
#define _dep_graph_

class dependency_graph{

    private:
        std::map<std::string,std::set<std::string>> graph;
    
    public:
        dependency_graph(){
        }
        void add_dependency(const std::string of,const std::string dependency);
        bool is_dependent(const std::string& from,const std::string& dependency);
        std::set<std::string> get_adjecency_list(const std::string& vertex) const;
        void print_dependencies();
        auto& get_graph() const {
            return graph;
        }

};
#endif