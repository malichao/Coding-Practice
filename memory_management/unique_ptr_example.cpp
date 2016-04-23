/******************************************************************************
Author      : Lichao Ma
Date        : Apr 23,2016
Version     : v0.1
Built       : Sublime GCC, -std=c++11
Description :
   A example of how to use unique_ptr to simplify the memory management. class
   A and class B are identical.
*****************************************************************************/
#include <memory> //unique_ptr
#include <iostream>
class A {
public:
   int* i;

   A():i(new int(0)) { }

   ~A() { 
      if(i) {
         delete i; 
      }
   }

private:
    // we need to explicitly disable value-copying, as it's not safe!
    A(const A&);
    A& operator=(const A&);
};

class B {
public:
   std::unique_ptr<int> i;

   B():i(new int(0)) { }
};

int main(){
  A a;
  B b;
}