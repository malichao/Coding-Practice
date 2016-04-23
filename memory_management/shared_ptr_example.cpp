/******************************************************************************
Author      : Lichao Ma
Date        : Apr 23,2016
Version     : v0.1
Built       : Sublime GCC, -std=c++11
Description :
   A example of how to use shared_ptr to simplify the memory management.
*****************************************************************************/
#include <memory> //shared_ptr
#include <iostream>

struct MyClass {
   MyClass(const char* s){};
   void methodA(){};
};

void someMethod(MyClass* m){}

int main(){
	auto ptr = std::make_shared<MyClass>("obj1");

	ptr->methodA();

	someMethod(ptr.get());

	std::shared_ptr<MyClass> anotherPtr = ptr; // now anotherPtr + ptr are both pointing to the "obj1" object

	ptr.reset(new MyClass("obj2")); // now ptr switches to pointing to "obj2", but the "obj1" 
	                           // object is not deleted as anotherPtr is still holding it

	anotherPtr.reset(); // now no shared_ptr object is referencing the "obj1" MyClass*, so it is deleted

	// "obj2" will be automically deleted when ptr goes out of scope
}