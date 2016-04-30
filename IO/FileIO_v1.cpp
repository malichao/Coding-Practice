/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 30,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	File IO with arguments from command line and exceptions handling.
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <queue>
#include <array>

#include <utility>
#include <algorithm>
#include <time.h>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::string;

// Manually input the file names
void input(std::string &in,std::string &out){
	using namespace std;
	cout<<"Type the input file name\n";
	cin>>in;
	cout<<"Type the output file name\n";
	cin>>out;
}

void processLineByLine(std::stringstream &sin){
	string line;
	while (std::getline(sin, line)) {
		//First parse the line,assuming there are four data per line,e.g.,
		//  ID      X       Y       Z
		// val1 \t val2 \t val3 \t val4 \n
		std::stringstream line_stream(line);
		string buf;
		std::getline(line_stream, buf, '\t');
		int ID = stoi(buf);
		std::array<double, 3> data;	//stores x,y,z
		for (int i = 0; i < 3; i++) {
			std::getline(line_stream, buf, '\t');
			data[i] = stod(buf);
		}
	}
}

void openFile(std::string &fileName,std::stringstream &content){
	//Reading the input
	try{
		//Use binary mode for highest efficiency
		std::ifstream inputFile(fileName,std::ios::binary);

		//Must set these bits to enable exception
		inputFile.exceptions(std::ifstream::failbit);

		content<<inputFile.rdbuf();

	}catch(std::exception& e){
		std::cerr<<"Error Occured when reading/writing files!\n\t"<<e.what()<<endl;
	}
}

int main(int argc,char** argv){
	using namespace std;
	string inputName,outputName;
	switch(argc){
		case 1:	input(inputName,outputName);	//If no argument,manually type in
				break;
		case 2:	inputName=argv[1];	//If only input name,extend it with "-result"
				break;
		case 3:	inputName=argv[1];	//Two arguments,good
				outputName=argv[2];
				break;
		default:break;
	}

	std::stringstream s;
	openFile(inputName,s);
	processLineByLine(s);
}
