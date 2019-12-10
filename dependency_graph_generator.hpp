#include <set>
#include <list>

#include "./dependency_graph.hpp"

class dependency_graph_generator{

    private:
        std::set<std::string> visited;
        std::list<std::string> enqued;
        dependency_graph dg;

    public:
        dependency_graph get_dependency_graph(const std::string& f);
        void generate_dependencies(const std::string& f);
        bool is_visited(const std::string& f);


};