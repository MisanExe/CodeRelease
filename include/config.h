#pragma once 

#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

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
    }
    

    class ConfigBot{

        public :
            //constructor 
            ConfigBot();

            //Run
            void Run_init();

        private :
            //SandBox
            bool Sandbox(std::function<bool(void)> callback);
            
            std::string currentDir;
            

    };

  
    std::string GetCurrent_Dir();
    bool Dir_IsExist(std::string dir);
}

