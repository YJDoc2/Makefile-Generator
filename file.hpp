#include <string>
#include <exception>

#ifndef _file_
#define _file_

enum filetype{
    C,
    CPP,
    EMPTY
};

filetype get_type(const std::string& in){
    auto dot_pos = in.find_last_of('.');
    if(dot_pos == std::string::npos){
        throw std::string("No file Extention found");
    }
    auto ext = in.substr(dot_pos+1,3);

    if(ext.compare("c")==0 || ext.compare("h") == 0){
        return filetype::C;
    }else if(ext.compare("cpp")==0 || ext.compare("hpp") == 0){
        return filetype::CPP;
    }else{
        throw std::string("Invalid File type...Only c and c++ file are supported");
    }
}

class file{

    private:
    std::string name;
    filetype f_type;
    public:

    file(std::string filename){
        if(filename.empty()){
            name  = filename;
            f_type = filetype::EMPTY;
            return;
        }
        name = filename;
        auto dot_pos = filename.find_last_of('.');
        if(dot_pos == std::string::npos){
            throw std::string("No file Extention found");
        }
        auto ext = filename.substr(dot_pos+1,3);

        if(ext.compare("c")==0 || ext.compare("h") == 0){
            f_type =  filetype::C;
        }else if(ext.compare("cpp")==0 || ext.compare("hpp") == 0){
            f_type = filetype::CPP;
        }else{
            throw std::string("Invalid File type...Only c and c++ file are supported");
        }
    }

    std::string get_file_name() const {
        return name;
    }

};


bool operator ==(const file& f1,const file& f2){
    std::string temp1 = f1.get_file_name();
    std::string temp2 = f2.get_file_name();
    return (temp1.compare(temp2)==0);
}

bool operator <(const file f1,const file f2){
    return !(f1 == f2);
}


#endif