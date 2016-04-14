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

int main(int argc,char** argv){
	using namespace std;
	string inputName,outputName;
	switch(argc){
		case 1:	input(inputName,outputName);	//If no argument,manually type in
				break;
		case 2:	inputName=argv[1];	//If only input name,extend it with "-result"
				outputName=inputName+"-result";
				break;
		case 3:	inputName=argv[1];	//Two arguments,good
				outputName=argv[2];
				break;
		default:break;
	}

	try{
		ifstream inputFile(inputName,std::ifstream::in);
		ofstream outputFile(outputName,ofstream::out);

		//Must set these bits to enable exception
		inputFile.exceptions(ifstream::failbit);
		outputFile.exceptions(ifstream::failbit);

		if(outputFile.is_open()){
			while(inputFile.good()){
				string temp;
				std::getline(inputFile,temp);
				outputFile<<temp<<endl;
				cout<<temp<<endl;
			}
		}

		cout<<"Moved content from \'"<<inputName<<"\' to \'"<<outputName<<"\'\n";

	}catch(exception& e){
		std::cerr<<"Error Occured when reading/writing files!\n\t"<<e.what()<<endl;
	}
}