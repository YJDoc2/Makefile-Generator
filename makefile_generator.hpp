#include <map>
#include "./dependency_graph.cpp"

class makefile_generator{

    private:
        std::map<std::string,bool> visited;
        std::map<std::string,bool> rec_stack;
        bool is_cyclic(std::string current,const dependency_graph& dg);
        void prepare_maps(const dependency_graph& dg);

    public:
        bool conatains_circular_dependencies(const dependency_graph& dg);


};