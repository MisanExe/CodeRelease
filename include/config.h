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

        bool RequestCodeDir();
        bool EnterCodeDir();
        bool Set_SrcDir();
        bool Set_BinDir();

        struct ConfigMeta{
            std::string src_dir;
            std::string bin_dir; 
        };
    }
    

    class ConfigBot{

        public :
            //constructor 
            ConfigBot();

            //Run
            void Run_init();

        private :

            std::vector<config::ConfigMeta> _Metas;
            //SandBox
            bool _Sandbox(std::function<bool(void)> callback);
            std::string _currentDir;

            bool WriteConfig(std::vector<config::ConfigMeta> metas);
            

    };

  
    std::string GetCurrent_Dir();
    bool Dir_IsExist(std::string dir);
}

