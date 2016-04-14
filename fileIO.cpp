#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

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
		case 1:	input(inputName,outputName);
				break;
		case 2:	inputName=argv[1];
				outputName=inputName+"-result";
				break;
		case 3:	inputName=argv[1];
				outputName=argv[2];
				break;
		default:break;
	}

	try{
		ifstream inputFile(inputName,std::ifstream::in);
		ofstream outputFile(outputName,ofstream::out);

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
		std::cerr<<e.what()<<endl;
	}
}