/******************************************************************************
Author      : Lichao Ma
Date        : Apr 23,2016
Version     : v0.1
Built       : Sublime GCC, -std=c++11
Description :
   A example of how to write move constructor and move assignment operator.
   Howerver,such implementation could be simply replace with unique_ptr.The 
   following class MyClass and MyClass1 are equivalent.
*****************************************************************************/
#include <memory> //unique_ptr
#include <iostream>

class MyClass {
   int* buffer;

private:

   // disable copying
   MyClass(const MyClass&);
   MyClass& operator=(const MyClass&);

public:
   MyClass() : buffer(nullptr){}
   MyClass(int *b) : buffer(b){}
   // move constructor
   MyClass(MyClass&& other) {
      buffer = other.buffer;
      other.buffer = nullptr;
   }

   // move assignment operator
   MyClass& operator=(MyClass&& other) {
      if(this != &other) {
         if(buffer) {
            delete buffer;
         }
         buffer = other.buffer;
         other.buffer = nullptr;
      }
   }

   ~MyClass() {
      if(buffer) {
          delete buffer;
       }
   }

   int getBuffer() const { 
      return *buffer;
   }
};

class MyClass1 {
   std::unique_ptr<int> buffer;
};


int main(){
   int *test=new int(1);
   MyClass m(test);

   std::cout<<"m= "<<m.getBuffer()<<'\n';

   MyClass m1=std::move(m);
   std::cout<<"m1= "<<m1.getBuffer()<<'\n';
   std::cout<<"now m= "<<m.getBuffer()<<'\n';   //Error : Segmentation fault
}