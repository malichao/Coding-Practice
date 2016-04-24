/******************************************************************************
Author      : Lichao Ma
Date        : Apr 23,2016
Version     : v0.1
Built       : Sublime GCC, -std=c++11
Description :
   A practice of writing my own shared_ptr.
   Rule of thumb when using SmartPointer/shared_ptr:
   Never construct several SmartPointers/shared_ptrs with the same object,
   instead,take control of the object immediately after allocated on the heap.
   i.e.,never use:
   int *test1=new int(1);
   SmartPointer<int> smptr(test1);
   SmartPointer<int> smptr1(test1);	//runtime error,multiple delete!
   use:
   SmartPointer<int> smptr(new int(1));
   SmartPointer<int> smptr1(smptr);	//correct!
*****************************************************************************/
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template<class T>
class SmartPointer{
public:
	SmartPointer(T *ptr){
		ref=ptr;
		ref_count=new int(1);
		cout<<"SmartPointer constructed\n";
	}

	//When copied, we increase the number of the owners of the pointed object
	SmartPointer(SmartPointer<T> &smptr){
		ref=smptr.ref;
		ref_count=smptr.ref_count;
		++(*ref_count);
		cout<<"SmartPointer owner incremented\n";
	}

	SmartPointer<T>& operator=(SmartPointer<T> &smptr){
		if(&smptr==this) return *this;

		if(*ref_count>0)
			remove();

		ref=smptr.ref;
		ref_count=smptr.ref_count;
		++(*ref_count);
		cout<<"SmartPointer owner incremented\n";
		return *this;
	}

	~SmartPointer(){
		remove();
	}
	T get(){
		return *ref;
	}

protected:
	void remove(){
		--(*ref_count);
		if(*ref_count<=0){
			if(ref){
				delete ref;
				cout<<"Deleted ref\n";
			} 
			if(ref_count){
				delete ref_count;
				cout<<"Deleted ref_count\n";
			} 
			ref_count=nullptr;
			ref=nullptr;
			cout<<"SmartPointer destructed\n";
		}
	}

private:
	T* ref;
	int *ref_count;
};

int main(){
	SmartPointer<int> smptr(new int(1));
	cout<<"smptr= "<<smptr.get()<<endl;
	SmartPointer<int> smptr1(smptr);
	cout<<"smptr1= "<<smptr.get()<<endl;
	SmartPointer<int> smptr2=smptr;
	cout<<"smptr2= "<<smptr.get()<<endl;
}