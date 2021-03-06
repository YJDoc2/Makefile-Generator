mkgen : ./dependency_graph.o ./dependency_graph_generator.o ./file.o ./makefile_generator.o ./reader.o ./topological_util.o main.o 
	g++ -std=c++17 -o mkgen ./dependency_graph.o ./dependency_graph_generator.o ./file.o ./makefile_generator.o ./reader.o ./topological_util.o main.o 
	rm ./*.o

main.o : ./file.hpp ./makefile_generator.hpp 
	g++ -c -std=c++17 main.cpp

./makefile_generator.o : ./makefile_generator.hpp ./topological_util.hpp 
	g++ -c -std=c++17 ./makefile_generator.cpp

./topological_util.o : ./topological_util.hpp ./dependency_graph_generator.hpp 
	g++ -c -std=c++17 ./topological_util.cpp

./dependency_graph_generator.o : ./dependency_graph_generator.hpp ./dependency_graph.hpp 
	g++ -c -std=c++17 ./dependency_graph_generator.cpp

./dependency_graph.o : ./dependency_graph.hpp ./reader.hpp 
	g++ -c -std=c++17 ./dependency_graph.cpp

./reader.o : ./reader.hpp ./file.hpp 
	g++ -c -std=c++17 ./reader.cpp

./file.o : ./file.hpp ./mkgen_exception.hpp 
	g++ -c -std=c++17 ./file.cpp

