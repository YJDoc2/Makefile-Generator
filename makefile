a.out : reader.o dependency_graph.o dependency_graph_generator.o topological_util.o topo_sort_test.o file.o
	g++ topo_sort_test.o dependency_graph.o dependency_graph_generator.o reader.o makefile_generator.o file.o

topo_sort_test.o:
	g++ -c topo_sort_test.cpp

topological_util.o:
	g++ -c topological_util.cpp

dependency_graph_generator.o:
	g++ -c dependency_graph_generator.cpp

dependency_graph.o:
	g++ -c dependency_graph.cpp


reader.o : 
	g++ -c reader.cpp

file.o:
	g++ -c file.cpp