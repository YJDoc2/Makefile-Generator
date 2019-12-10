#include <string>
#include <cctype>
#include <cstring>
#include <list>
#include <algorithm>
#include <iostream>

#include "./reader.hpp"

#ifndef _temp_
#define _temp_
std::string reader::get_next_custom_dependency(){

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
                return "";
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
            
            return filename;
        }
	}
    scanned_all_dependencies = true;
    return "";
    
}

#endif