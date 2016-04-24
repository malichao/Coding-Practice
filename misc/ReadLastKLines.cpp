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
		int start=bufferHead-lineCount;

		for(int i=0;i<lineCount;i++){
			int pos=start+i<0 ?start+i+lineCount : start+i;
			std::cout<<buffer[pos%lineCount]<<'\n';
		}
		

	}catch(std::exception& e){
		std::cerr<<e.what()<<'\n';
	}
}

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