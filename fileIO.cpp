#include <stdio.h>
#include <iostream>

int main(int argc,char** argv){
	using namespace std;
	cout<<"Input argc="<<argc<<endl;
	for(size_t i=0;i<argc;i++)
		cout<<argv[i]<<endl;
}