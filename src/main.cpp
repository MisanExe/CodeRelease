
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "../include/config.h"

#include <unistd.h>
#include <limits.h>
struct Data{
	int id;
	float value;
	char name[20];
};



int main(int args, char **argv){

	// //create data to write
	// std::vector<Data> userData= { {22, 80.9, "Ava"}, {2, 56.2, "Jacob"} , {1, 90.75, "Babara"}, {15, 75.0, "Eddie"} };
	// userData.push_back({32, 72.4, "Jasmine"});

	// std::vector<Data> readData;
	// readData.resize(userData.size());
	
	// //Wite data to the file
	// {
		
	// 	std::ofstream config;
	// 	config.open("../config.txt", std::ios::binary);

	// 	if(!config){
	// 		std::cerr<<"Error opening file for writing\n"<<std::endl;
	// 		return 1;
	// 	}
	// 	config.write(reinterpret_cast<char*>(userData.data()), userData.size() * sizeof(Data));
	// 	config.close();
	// }

	// //read data from file
	// {
	// 	std::ifstream r_config("../config.txt", std::ios::binary);
	// 	if(!r_config){
	// 		std::cerr <<"Error opening the config file"<<std::endl;
	// 		return 1;
	// 	}

	// 	//read
	// 	r_config.read(reinterpret_cast<char*>(readData.data()), userData.size() *sizeof(Data));
	// 	for(auto data : readData){
	// 		std::cout<< "ID : "<<data.id<<",\t Value : "<<data.value<<",\t Name : "<<data.name<<std::endl;
	// 	}
	// }
	
	//get current directory
	// {
	// 	char cwd[PATH_MAX];
	// 	if (getcwd(cwd, sizeof(cwd)) != nullptr){
	// 		std::cout<<"Current working directory : "<<cwd<<std::endl;
	// 	}else{
	// 		perror("getcwd");
	// 	}
	// }

	// //get files in curent directory
	// {
	// 	std::filesystem::path c_wd = std::filesystem::current_path();
	// 	std::cout<<"The directory contains : "<<c_wd<<std::endl;
		
	// 	for( const auto& entry : std::filesystem::directory_iterator(c_wd))
	// 	{
	// 		//std::cout<<entry.path()<<std::endl;
	// 		if (entry.path() == c_wd.string()+"/src"){
	// 			std::cout<<"Contains src directory"<<std::endl;
	// 		}else{
	// 			//create directory
	// 			std::filesystem::create_directory(c_wd.string()+"/src");
	// 		}
	// 	}
		
	// }

	//CodeReleaseNS::RunConfig();

	CodeReleaseNS::ConfigBot bot = CodeReleaseNS::ConfigBot();
	bot.Run_init();

	std::cout<<"Done!"<<std::endl;

	return 0;
}