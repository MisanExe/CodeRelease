#pragma once 

#include <string>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

namespace CodeReleaseNS{

    namespace config
    {
        enum ConfigState{
            NONE,
            IS_CODE_DIR, //is current directory a code directory
            SET_SRC_DIR,
            SET_BIN_DIR
        };

        
        struct ConfigMeta{
            std::string src_dir;
            std::string bin_dir; 
        };

        bool RequestCodeDir(ConfigMeta &meta);
        bool EnterCodeDir(ConfigMeta &meta);
        bool Set_SrcDir(ConfigMeta &meta);
        bool Set_BinDir(ConfigMeta &meta);

    }
    

    class ConfigBot{

        public :
            //constructor 
            ConfigBot();

            //Run
            void Run_init();

            void printMeta(){
                std::cout<<"Meta Data contains : "<<std::endl;
                std::cout<<"Source file : "<<this->_meta.src_dir<<std::endl;
                std::cout<<"Binary/Executable file : "<<this->_meta.bin_dir<<std::endl;
            }

        private :

            config::ConfigMeta _meta;
            //SandBox
            bool _Sandbox(config::ConfigMeta &meta, std::function<bool(config::ConfigMeta&)> callback);
            std::string _currentDir;
            bool WriteConfig();     
            void _clearMeta();       

    };

  
    std::string GetCurrent_Dir();
    bool Dir_IsExist(std::string dir);
}

