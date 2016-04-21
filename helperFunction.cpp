/******************************************************************************
Author		: Lichao Ma
Date  		: Mar 22,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	A demostration of how to use helper function to factor out repeated codes.
*****************************************************************************/

/*OUPTUT:
Original array:
-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,
Arrange odd values before even ones:
9,-9,7,-7,5,-5,3,-3,1,-1,0,-2,2,-4,4,-6,6,-8,8,-10,
Arrange positive values before negative ones:
9,8,7,6,5,4,3,2,1,-1,0,-2,-3,-4,-5,-6,-7,-8,-9,-10,
Arrange multiple of 3 first:
9,-9,-6,6,-3,0,3,2,1,-1,4,-2,5,-4,-5,7,-7,-8,8,-10,
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <array>
using namespace std;

bool isOdd(int a){
	if(a%2!=0)		//a%2==1 doesn't work with negative numbers
		return true;
	return false;
}

bool isPositive(int a){
	if(a>0) return true;
	return false;
}

bool isMultipleof3(int a){
	if(a%3!=0) return false;
	return true;
}

void reOrder(int array[],int length,bool (*func)(int)){
	int begin=0;
	int end=length-1;
	while(begin<end){
		while(begin<end&&func(array[begin]))	//skip the odd values
			begin++;
		while(begin<end&&!func(array[end]))
			end--;
		if(begin<end){
			std::swap(array[begin],array[end]);
		}
	}
}

int main()
{
	int test[20];
	vector<int> input;
	for(int i=0;i<20;i++)
		test[i]=i-10;
	cout<<"Original array:\n";
		for(int i=0;i<20;i++)
				cout<<test[i]<<",";

	reOrder(test,20,isOdd);
	cout<<"\nArrange odd values before even ones:\n";
	for(int i=0;i<20;i++)
		cout<<test[i]<<",";

	reOrder(test,20,isPositive);
	cout<<"\nArrange positive values before negative ones:\n";
	for(int i=0;i<20;i++)
		cout<<test[i]<<",";

	reOrder(test,20,isMultipleof3);
	cout<<"\nArrange multiple of 3 first:\n";
	for(int i=0;i<20;i++)
		cout<<test[i]<<",";
}



