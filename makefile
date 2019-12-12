test : ./dependency_graph.o ./dependency_graph_generator.o ./file.o ./makefile_generator.o ./mkgen_test.o ./reader.o ./topological_util.o 
	g++ -o test ./dependency_graph.o ./dependency_graph_generator.o ./file.o ./makefile_generator.o ./mkgen_test.o ./reader.o ./topological_util.o 

./mkgen_test.o : ./makefile_generator.hpp 
	g++ -c ./mkgen_test.cpp

./makefile_generator.o : ./makefile_generator.hpp ./file.hpp ./topological_util.hpp 
	g++ -c ./makefile_generator.cpp

./topological_util.o : ./topological_util.hpp ./dependency_graph.hpp ./dependency_graph_generator.hpp 
	g++ -c ./topological_util.cpp

./dependency_graph_generator.o : ./dependency_graph_generator.hpp ./dependency_graph.hpp 
	g++ -c ./dependency_graph_generator.cpp

./dependency_graph.o : ./dependency_graph.hpp ./reader.hpp 
	g++ -c ./dependency_graph.cpp

./reader.o : ./reader.hpp ./file.hpp 
	g++ -c ./reader.cpp

./file.o : ./file.hpp 
	g++ -c ./file.cpp

