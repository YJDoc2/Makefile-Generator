#include <string>
#include <cctype>
#include <cstring>
#include <list>
#include <algorithm>
#include <iostream>

#include "./file.hpp"
#include "./reader.hpp"

#ifndef _temp_
#define _temp_
file reader::get_next_custom_dependency(){

    std::string line;	
    while(instream.good()){
		std::getline(instream,line);
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		//Checks for blank lines and comments(//)
		if(line.empty() || line.find("//")==0){
			continue;

		}else{

            if(line[0] != '#'){
                scanned_all_dependencies = true;
                return file("");
            }
            //A preprpcessor command but not incluse
            if((line.substr(1,7)).compare("include") != 0){
                continue;
            }
            //standard include file
            if(line[8] == '<'){
                continue;
            }
            //#include" ->9 chars,thus start from 10th char, end beofre last " char, thus -2
            std::string filename = line.substr(9,line.length()-9-1);
            //std::cout<<"IN reader get_next_dep While, read Filename is "<<filename<<std::endl;
            file f(filename);
            //std::cout<<"IN reader get_next_dep While, read File is "<<f.get_code_file()<<std::endl;
            return f;
        }
	}
    scanned_all_dependencies = true;
    return file("");
    
}

#endif