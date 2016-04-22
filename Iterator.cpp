/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 22,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	A demostration of how to write a iterator.
*****************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

// A base class to provide a common interface
template<typename T>
class Iterator{
public:
	virtual T* first()=0;
	virtual T* next()=0;
};

// A iterator for vector
template<typename T>
class Vector_Iterator:public Iterator<T>{
	vector<T>& v;
	size_t index;
public:
	Vector_Iterator(vector<T> &vv):v(vv),index(0){}
	T* first()	{return (v.size()) ? &v[index=0] : 0;}
	T* next()	{return (++index < v.size()) ? &v[index] : 0;}
};

int accumulate(Iterator<int>& ii,const int init){
	int sum=init;
	for(int *i=ii.first(); i; i=ii.next())
		sum+=*i;
	return sum;
}

int main(){
	vector<int> temp={1,2,3,4,5,6,7,8,9};
	Vector_Iterator<int> it(temp);
	cout<<"My iterator output: ";
	for(int* t=it.first();t;t=it.next())
		cout<<*t<<" ";

	cout<<"\nStandard iterator output: ";
	for(auto it=temp.begin();it!=temp.end();++it)
		cout<<*it<<" ";

	it.first();
	cout<<"\nMy iterator accumulate: "<<accumulate(it,0);
	cout<<"\nStandard iterator accumulate: "<<std::accumulate(temp.begin(),temp.end(),0);
}
