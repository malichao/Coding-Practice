/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 14,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	Read last K lines from a file. Basic solution is to read the files two
	times,first the number of lines and then locate the last K line and print.
	However,this can be improved by using a circular buffer of size K. When we
	reach the end of the file we have the answer in the buffer.
*****************************************************************************/

#define READ_LAST_K_LINES_MAIN	/*Comment out this line to disable the main function below*/
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using std::string;
using std::vector;
using std::cout;
using std::endl;

//====Test cases====
//- null cases 		: fileName="";K=0
//- illegal cases 	: input not found;K<0
//- range cases 	: K=length;K>length
//- normal cases 	: K=1,2,3...
void readLastKLines(const string &fileName,const int K){
	std::ifstream input(fileName);
	try{
		cout<<"Read "<<K<<" lines from the file\n";
		if(K<=0) throw std::range_error("Out of range!\n");

		vector<string> buffer(K);
		int bufferHead=0;
		int lineCount=0;
		while(input.good()){
			std::getline(input,buffer[bufferHead]);
			bufferHead=(bufferHead+1)%K;
			lineCount++;
		}
		
		//If the number of lines are more than the real line number then we
		//only read all the lines
		lineCount=K > lineCount ? lineCount : K;

		int start=bufferHead-lineCount;		//Go back to the start position
		//If start position is negative,then we offset it since it's a circular
		//buffer.
		start= start < 0 ? start+lineCount : start;
		for(int i=0;i<lineCount;i++){
			cout<<buffer[(start+i)%lineCount]<<'\n';
		}
		

	}catch(std::exception& e){
		std::cerr<<e.what()<<'\n';
	}
}

// Function to generate test cases
void generateTestCases(const string &fileName,const int length){
	try{
		std::ofstream testFile(fileName);
		for (int i = 0; i < length-1; ++i){
			testFile<<"line"<<length-i<<std::endl;
		}

		//Run this out of for loop,as for loop generate endl every time but we
		//want to end the file with no empty line.
		testFile<<"line1";	
	}catch(std::exception& e){
		std::cerr<<e.what()<<'\n';
	}
}


#ifdef READ_LAST_K_LINES_MAIN

int main(){
	int length=10;
	int K=10;
	string fileName("readLastKLines_test.txt");
	generateTestCases(fileName,length);

	//====Test cases====
	//- null cases 		: fileName="";K=0
	readLastKLines(fileName,0);
	readLastKLines("",1);

	//- illegal cases 	: input not found;K<0
	readLastKLines(fileName,-1);

	//- range cases 	: K=length;K>length
	readLastKLines(fileName,10);
	readLastKLines(fileName,12);

	//- normal cases 	: K=1,2,3...
	readLastKLines(fileName,1);
	readLastKLines(fileName,2);
	readLastKLines(fileName,3);
}

#endif