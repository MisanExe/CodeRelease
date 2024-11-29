//Configuration code
#include "../include/config.h"
#include <filesystem>
#include <fstream>

using namespace CodeReleaseNS;
using namespace CodeReleaseNS::config;

ConfigBot::ConfigBot(){
    this->_currentDir = GetCurrent_Dir();
}

/**
 * @brief :
 * @param :
 * @return :
 */
bool ConfigBot::_Sandbox(config::ConfigMeta &meta, std::function<bool(config::ConfigMeta&)> callback){

    int count = 0;
    bool ret = false;
    do{
        ret = callback(meta);
        if(ret){
            count = 3;
            return ret;
        }
        count++;
    }while(count < 3);
    
    return false;
}

/**
 * @brief :
 * @param :
 * @return :
 */
bool config::RequestCodeDir(config::ConfigMeta &meta){

    std::string response;
    std::filesystem::path cwd = std::filesystem::current_path(); 
    std::cout<<"\tIs \""<<cwd.string()<<"\" Your code directory ?  [yes-y] [no-n]\n";
    std::cout<<"\t>> ";
    std::cin>>response;
    //convert to lower 
    std::cout<<"res : "<<response<<std::endl;

    if(response == "yes" || response =="y")
    {
        return true;
    }else{
        return false;
    }

    return false;
}

/**
 * @brief :
 * @param :
 * @return :
 */
bool config::Set_SrcDir(config::ConfigMeta &meta){
    std::string response;
    std::cout<<"\n";
    std::cout<<"\tPlease Enter name of source directory in your current dirctory : "<<std::endl;
    std::cout<<"\t>> ";
    std::cin>>response;

    //store response 
    if(response != " " || response != "\n"){
        if(Dir_IsExist(response)){
            meta.src_dir = GetCurrent_Dir()+"/"+response;
            std::cout<<meta.src_dir<<std::endl;
            return true;
        }
        
    }

    return false;
}

/**
 * @brief :
 * @param :
 * @return :
 */
 bool config::Set_BinDir(config::ConfigMeta &meta){
    std::string response;
    std::cout<<"\n";
    std::cout<<"\tPlease Enter name of bin/executable directory in your current dirctory : "<<std::endl;
    std::cout<<"\t>> ";
    std::cin>>response;

    if(response != " " || response != "\n"){
        if(Dir_IsExist(response)){
            meta.bin_dir = GetCurrent_Dir()+"/"+response;
            std::cout<<meta.bin_dir<<std::endl;
            return true;
        }
        
    }

    return false;
 }


void ConfigBot::Run_init(){
   

    config::ConfigState config = NONE;

    switch(config){

        case 0:
            config = IS_CODE_DIR;
        case 1: //Request code directory
            if (this->_Sandbox(this->_meta, RequestCodeDir)){
                //proceed
                config = SET_SRC_DIR;
            }else{
                std::cout<<"Please call this program in your code directory"<<std::endl;
                break;
            }

        case 2: //Enter name of source directory
            if (this->_Sandbox(this->_meta, Set_SrcDir)){
                //proceed
                config = SET_BIN_DIR;
            }else{
                std::cout<<"Something sup"<<std::endl;
                this->_clearMeta();
                break;
            }
        case 3:
            if (this->_Sandbox(this->_meta, Set_BinDir)){

            }else{
                std::cout<<"Something sup"<<std::endl;
                this->_clearMeta();
                break;
            }
            
        default:
            break;
    }


}


bool CodeReleaseNS::Dir_IsExist(std::string dir){
    std::filesystem::path cwd = std::filesystem::current_path();
    for( const auto& entry : std::filesystem::directory_iterator(cwd)){
        if(entry.path() == (cwd.string()+"/"+dir)){
            return true;
        }
    }

    return false;
}

std::string CodeReleaseNS::GetCurrent_Dir(){
    std::filesystem::path cwd = std::filesystem::current_path();
    return cwd.string();
}

bool ConfigBot::WriteConfig(){
    
    //remember to add try
    //open file as binary
    std::ofstream configFile ("config.bin", std::ofstream::binary | std::ofstream::app);
    
    if(!configFile.is_open()){
        return false;
    }
    //write binary in 
    configFile.write(reinterpret_cast<char*>(&this->_meta), sizeof(this->_meta));
    if(!configFile.fail()){
        return true;
    }
    return false;

}

void ConfigBot::_clearMeta(){
    this->_meta.bin_dir.clear();
    this->_meta.src_dir.clear();
}