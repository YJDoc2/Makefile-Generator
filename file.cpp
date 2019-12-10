#include "./file.hpp"

filetype get_type(const std::string& in){
    auto dot_pos = in.find_last_of('.');
    if(dot_pos == std::string::npos){
        throw std::string("No file Extention found");
    }
    auto ext = in.substr(dot_pos+1,3);

    if(ext.compare("c")==0 ){
        return filetype::C;
    }else if(ext.compare("h") == 0){
        return filetype::H;
    }else if(ext.compare("cpp")==0){
        return filetype::CPP;
    }else if( ext.compare("hpp") == 0){
        return filetype::HPP;
    }else{
        throw std::string("Invalid File type...Only c and c++ file are supported");
    }
}