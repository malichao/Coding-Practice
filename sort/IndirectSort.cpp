/******************************************************************************
Author		: Lichao Ma
Date  		: May 1,2016
Version		: v0.1
Built		: GCC 5.3.0, -std=c++11
Description :
	A practice of using pointers to reduce the overhead of swapping in sort.
	For a large file with million lines of varying length record,swapping is
	expensive and complicated,we could instead swap the pointers and then
	iterate through the pointers and dereference them.
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <utility>
#include <algorithm>
#include <time.h>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template<typename T>
void indirectSort(std::stringstream &file){
	//First read the file into a buffer
	vector<T> buffer;
	T temp;
	while(file>>temp)
		buffer.emplace_back(temp);

	//Initialize sort file
	vector<T*> bufferPointers;
	for(T &b:buffer){
		bufferPointers.emplace_back(&b);
	}

	//Indirect sort file
	sort(bufferPointers.begin(),bufferPointers.end(),[](const T*a,const T*b)->bool{return *a<*b;});

	file.clear();	//Clear any fail or eof bit of the file
	file.str("");	//Clear the content
	for(auto p:bufferPointers){
		file<<*p<<endl;
	}
}

// Generate a file of a given length with varying length of rows
void generateTestCase(  std::stringstream &file,
						const size_t fileLength,
						const size_t rowLength){
	if(rowLength==0)	//Watch out for divide by 0
		return;

	srand(time(NULL));
	for(size_t i=0;i<fileLength;i++){
		size_t length=rand()%rowLength+1;
		for(size_t j=0;j<length;j++){
			file<<static_cast<char>(rand()%26+'a');
		}
		file<<endl;
	}
}


int main () {
	std::stringstream test;
	generateTestCase(test,5,20);
	cout<<"Test case:\n"<<test.str();
	indirectSort<string>(test);
	cout<<"\nResult :\n"<<test.str();
}









