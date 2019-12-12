#include <fstream>

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

std::string get_o_file(const std::string file){

    int ext_len;
    if(get_type(file) == filetype::C || get_type(file) == filetype::H){
        ext_len = 1;
    }else{
        ext_len = 3;
    }

    auto tmp = file.substr(0,file.length()-ext_len-1);
    return tmp+".o";
}

std::string get_code_file(const std::string file){

    filetype type = get_type(file);
    std::string ret;
    if(type == filetype::C || type == filetype::CPP){
        return file;
    }
    if(type == filetype::H){
        ret = file;
        ret[ret.find_last_of('h')] = 'c';
        return ret;
    }
    if(type == filetype::HPP){
        ret = file;
        ret[ret.find_last_of('h')] = 'c';
        return ret;
    }
    throw std::string("Err");
}

std::string get_H_file(const std::string file){

    filetype type = get_type(file);
    std::string ret;
    if(type == filetype::H || type == filetype::HPP){
        return file;
    }
    if(type == filetype::C){
        ret = file;
        ret[ret.find_last_of('c')] = 'h';
        return ret;
    }
    if(type == filetype::CPP){
        ret = file;
        ret[ret.find_last_of('c')] = 'h';
        return ret;
    }
    throw std::string("Err");
}

std::string get_compiler(const std::string file,const mk_data data){

    filetype type = get_type(file);

    if(type == filetype::H || type == filetype::C){
        return data.c_comp;
    }
    if(type == filetype::HPP || type == filetype::CPP){
        return data.cpp_comp;
    }
    throw std::string("Err");
}

std::string get_dep_str(const std::string file,const std::set<std::string> list){

    std::string str = "";
    std::string h_tmp = get_H_file(file);
    std::ifstream tmp(h_tmp);

    if(tmp.good()){
        str += h_tmp+" ";
    }
    tmp.close();

    
    for (auto &file : list){
        str += file+" ";
    }
    return str;

}

