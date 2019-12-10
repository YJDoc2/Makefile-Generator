#include <string>
#include <list>
#include <algorithm>
#include <fstream>

#include "./file.hpp"

#ifndef _reader_
#define _reader_
class reader{

    private:
        std::string filename;
        bool scanned_all_dependencies = false;
        std::ifstream instream;
        

    public:
        reader(std::string name):filename(name),instream(name){
            
        }
        std::string get_next_custom_dependency();
        bool is_done(){
            return scanned_all_dependencies;
        }

};
#endif