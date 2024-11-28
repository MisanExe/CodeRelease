//Configuration code
#include "../include/config.h"
#include <filesystem>

using namespace CodeReleaseNS;
using namespace CodeReleaseNS::config;

ConfigBot::ConfigBot(){
    this->currentDir = GetCurrent_Dir();
}

/**
 * @brief :
 * @param :
 * @return :
 */
bool ConfigBot::Sandbox(std::function<bool(void)> callback){

    int count = 0;
    bool ret = false;
    do{
        ret = callback();
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
bool config::RequestCodeDir(){

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
bool config::Set_SrcDir(){
    std::string response;
    std::cout<<"\n";
    std::cout<<"\tPlease Enter name of source directory in your current dirctory : "<<std::endl;
    std::cout<<"\t>> ";
    std::cin>>response;

    //store response 
    if(response != " " || response != "\n"){
        if(Dir_IsExist(response)){
            std::cout<<"src dir exist"<<std::endl;
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
 bool config::Set_BinDir(){
    std::string response;
    std::cout<<"\n";
    std::cout<<"\tPlease Enter name of bin/executable directory in your current dirctory : "<<std::endl;
    std::cout<<"\t>> ";
    std::cin>>response;

    if(response != " " || response != "\n"){
        if(Dir_IsExist(response)){
            std::cout<<"bin dir exist"<<std::endl;
            return true;
        }
        
    }

    return false;
 }


void ConfigBot::Run_init(){
   

    CodeReleaseNS::config::ConfigState config = CodeReleaseNS::config::ConfigState::NONE;

    switch(config){

        case 0:
            config = IS_CODE_DIR;
        case 1: //Request code directory
            if (this->Sandbox(config::RequestCodeDir)){
                //proceed
                config = SET_SRC_DIR;
            }else{
                std::cout<<"Please call this program in your code directory"<<std::endl;
                break;
            }

        case 2: //Enter name of source directory
            if (this->Sandbox(config::Set_SrcDir)){
                //proceed
                config = SET_BIN_DIR;
            }else{
                std::cout<<"Something sup"<<std::endl;
                break;
            }
        case 3:
            if (this->Sandbox(config::Set_BinDir)){

            }else{
                std::cout<<"Something sup"<<std::endl;
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