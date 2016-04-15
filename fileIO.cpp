/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 14,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	File IO with arguments from command line and exceptions handling.
*****************************************************************************/

#include <stdio.h>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

// Manually input the file names
void input(std::string &in,std::string &out){
	using namespace std;
	cout<<"Type the input file name\n";
	cin>>in;
	cout<<"Type the output file name\n";
	cin>>out;
}

void processLineByLine(std::string &inputName,std::string &outputName){
	using namespace std;
	//Reading the input
	try{
		ifstream inputFile(inputName,std::ifstream::in);

		//Must set these bits to enable exception
		inputFile.exceptions(ifstream::failbit);

		while(inputFile.good()){
			string temp;
			std::getline(inputFile,temp);
			cout<<temp<<endl;
		}

		if(!outputName.empty()){
			ofstream outputFile(outputName,ofstream::out);
			outputFile.exceptions(ifstream::failbit);

			//Clear states and reset the pointer to the beginning
			inputFile.clear();
			inputFile.seekg(0);
			while(inputFile.good()){
				string temp;
				std::getline(inputFile,temp);
				outputFile<<temp<<endl;
			}
			cout<<"Moved content from \'"<<inputName<<"\' to \'"<<outputName<<"\'\n";
		}
	}catch(exception& e){
		std::cerr<<"Error Occured when reading/writing files!\n\t"<<e.what()<<endl;
	}
}

void processByBlock(std::string &inputName,std::string &outputName){
	using namespace std;
	//Reading the input
	try{
		ifstream inputFile(inputName,std::ifstream::in);

		//Must set these bits to enable exception
		inputFile.exceptions(ifstream::failbit);

		//Set the pointer to the end and read the length
		inputFile.seekg(0,inputFile.end);
		size_t length=inputFile.tellg();
		inputFile.seekg(0);

		// Read the data into a buffer and use it for cout and writing
		char *buffer=new char[length];
		inputFile.read(buffer,length);

		copy(buffer,buffer+length,ostream_iterator<char>(cout));

		if(!outputName.empty()){
			ofstream outputFile(outputName,ofstream::out);
			outputFile.exceptions(ifstream::failbit);

			outputFile.write(buffer,length);

			cout<<"Moved content from \'"<<inputName<<"\' to \'"<<outputName<<"\'\n";
		}
	}catch(exception& e){
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

	//processLineByLine(inputName,outputName);
	processByBlock(inputName,outputName);
}