
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

	

	CodeReleaseNS::ConfigBot bot = CodeReleaseNS::ConfigBot();
	bot.Run_init();

	std::cout<<"Done!"<<std::endl;

	return 0;
}