#include <set>
#include <list>

#include "./file.hpp"
#include "./dependency_graph.hpp"

class dependency_graph_generator{

    private:
        std::set<file> visited;
        std::list<file> enqued;
        dependency_graph dg;

    public:
        dependency_graph get_dependency_graph(const file& f);
        void generate_dependencies(const file& f);
        bool is_visited(const file& f);


};