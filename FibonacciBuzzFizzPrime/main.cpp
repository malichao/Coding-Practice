/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 29,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	Main function for FibonacciBuzzFizzPrime.
	Toggling TEST_ENABLE macro for running or direct execution.
*****************************************************************************/

//#define TEST_ENABLE	/*Comment this out for running the code on console*/


#ifdef TEST_ENABLE

#include "test/test.h"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else

#include <iostream>
#include "src/FibonacciBuzzFizzPrime.h"
using namespace fbfp;


int main(int argc, char **argv) {
	FBFP temp;
	std::vector<fbfp::fbfp_pair> result;

	try{
		int n=0;
		if(argc==1)
			n=94;
		else if(argc==2)
			n=atoi(argv[1]);
		std::cout<<"Generating Fibonacci for n= "<<n<<std::endl;
		temp.generate(n,result);
		fbfp::fbfp_pair p;

		size_t i=0;
		for(const auto r:result){
			std::cout<<"f("<<i++<<")\t"<<r.first<<"\t\t"<<r.second<<std::endl;
		}
		return 1;
	}catch(std::exception& e){
		size_t i=0;
		for(const auto r:result){
			std::cout<<"f("<<i++<<")\t"<<r.first<<"\t\t"<<r.second<<std::endl;
		}
		std::cout<<e.what()<<std::endl;
		return 0;
}
}

#endif
