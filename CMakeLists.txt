
cmake_minimum_required(VERSION 3.25.1)

project (CodeRelease
         VERSION 1.0.0
         LANGUAGES C CXX
        )


add_executable(CodeRelease src/main.cpp src/config.cpp)

target_include_directories(CodeRelease PRIVATE ${PROJECT_SOURCE_DIR}/include)