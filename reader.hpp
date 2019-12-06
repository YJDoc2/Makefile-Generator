#include <string>
#include <list>
#include <algorithm>
#include <fstream>

#include "./file.hpp"

#ifndef _reader_
#define _reader_
class reader{

    private:
        file read_file;
        bool scanned_all_dependencies = false;
        std::ifstream instream;
        

    public:
        reader(std::string name):read_file(name),instream(read_file.get_file_name()){
            
        }
        file get_next_custom_dependency();
        bool is_done(){
            return scanned_all_dependencies;
        }

};
#endif