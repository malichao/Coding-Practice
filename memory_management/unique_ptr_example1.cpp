/******************************************************************************
Author      : Lichao Ma
Date        : Apr 23,2016
Version     : v0.1
Built       : Sublime GCC, -std=c++11
Description :
   A example of how to use unique_ptr to simplify the memory management.
*****************************************************************************/
#include <memory> //unique_ptr
#include <iostream>

int fillBuf(int* buf){}

//Unsafe code:
//- forgets to delete buf when return is called, and thus will leak memory.
//- if any exception is thrown by fillBuf(buf), it fails to delete buf and 
//	thus leak memory.
void methodA() {
   int* buf = new int[256];

   int result = fillBuf(buf);
   if(result == -1) {
      return; 
   }
   printf("Result: %d", result);

   delete[] buf;
}

//Safe code but verbose
void methodA1() {
   int* buf = new int[256];

   try {
      int result = fillBuf(buf);
      if(result == -1) {
         delete[] buf;
         return; 
      }
      printf("Result: %d", result);
   }
   catch(...) { 
      delete[] buf;
      throw;
   }
   delete[] buf;
}

//Safe and neat
void methodA2() {
   std::unique_ptr<int> buf(new int[256]);

   int result = fillBuf(buf.get());
   if(result == -1) {
      return;
   }
   printf("Result: %d", result);
}

int main(){

}