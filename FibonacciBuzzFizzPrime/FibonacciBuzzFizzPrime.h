/*
 * FibonacciBuzzFizzPrime.cpp
 *
 *  Created on: Apr 28, 2016
 *      Author: Lichao
 */
#include <utility>
#include <string>
#include <vector>

namespace fbfp{

using std::string;
using std::vector;

class FibonacciBuzzFizzPrime{
public:
	typedef std::pair<uint64_t,string> fbfp_pair;

	//generate fibonacci series and its regarding string for n
	//===Test Cases===
	//-null cases	 : n=0,result.size()=0
	//-illegal cases : n<0
	//-range cases	 : fibonacci >=uint64_t
	//-normal cases	 : n=1,2,3,4,5,...
	void generate(const int n,vector<fbfp_pair> &result){

	}

};

inline bool isFizz(uint64_t n){
	if(n<3) return false;
	return n%3==0;
}

inline bool isBuzz(uint64_t n){
	if(n<5) return false;
	return n%5==0;
}

inline bool isPrime(uint64_t n){
	if(n<=1)
		return false;
	for(uint64_t i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
}
