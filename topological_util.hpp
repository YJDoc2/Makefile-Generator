#include <map>
#include <stack>
#include <list>

#include "./dependency_graph_generator.hpp"

#ifndef _topo_util_
#define _topo_util_
class topological_util{

    private:
        std::map<std::string,bool> visited;
        std::map<std::string,bool> circ_stack;
        std::stack<std::string> topo_stack;
        std::list<std::string> dep_list;
        void prepare_maps(const dependency_graph& dg);
        //Taken from https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
        bool is_cyclic(std::string current,const dependency_graph& dg);
        //Taken from https://www.geeksforgeeks.org/topological-sorting/
        void topological_sort(std::string current,const dependency_graph& dg);

        

    public:
        //Taken from https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
        bool conatains_circular_dependencies(const dependency_graph& dg);
        //Taken from https://www.geeksforgeeks.org/topological-sorting/
        std::list<std::string> get_topological_order(const dependency_graph& dg);
        void print_topologic_order(const dependency_graph& dg) const;



};
#endif