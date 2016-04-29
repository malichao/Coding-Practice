/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 28,2016
Version		: v0.1
Built		: Cygwin, GCC 5.3.0, -std=c++11
Description :
	A program to solve the following problem.

	Generating the first n Fibonacci numbers F(n), printing ...
	- ... "Buzz" when F(n) is divisible by 3.
	- ... "Fizz" when F(n) is divisible by 5.
	- ... "BuzzFizz" when F(n) is prime.
	- ... the value F(n) otherwise.
*****************************************************************************/
#include <utility>
#include <string>
#include <vector>
#include <stdexcept>
#include <assert.h>     /* assert */

namespace fbfp{

using std::string;
using std::vector;

//Result is stored in pair -- fibonacci number & its regarding string
typedef std::pair<uint64_t, string> fbfp_pair;

//Check if it's divisible by 5
inline bool isFizz(uint64_t n){
	if(n<5) return false;
	return n%5==0;
}

//Check if it's divisible by 3
inline bool isBuzz(uint64_t n){
	if(n<3) return false;
	return n%3==0;
}

//Check if it's a prime number
inline bool isPrime(uint64_t n){
	if(n<=1)
		return false;
	for(uint64_t i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

class FBFP {
public:
	//generate fibonacci series and its regarding string for n
	//===Test Cases===
	//-null cases	 : n=0,result.size()=0
	//-illegal cases : n<0
	//-range cases	 : fibonacci >=uint64_t
	//-normal cases	 : n=1,2,3,4,5,...
	void generate(const int n, vector<fbfp_pair> &result) {
		if(n<0){
			throw std::range_error("Error, n must >=0!");
			return;
		}
		assert(n>=0);

		result.emplace_back(0, "0");	//n=0
		result.emplace_back(1, "1");	//n=1
		result.emplace_back(1, "1");	//n=2
		result.emplace_back(2, "FizzBuzz");	//n=3
		result.emplace_back(3, "FizzBuzz");	//n=4
		result.emplace_back(5, "FizzBuzz");	//n=5
		if(n<=5){
			result.resize(n+1);
			return;
		}
		assert(n>5);

		fbfp_pair f1, f2;
		for (int i = 6; i <= n; i++) {
			f1 = result[i - 1];
			f2 = result[i - 2];

			//Handle overflow first,since sum=f1+f2,so if f1 or f2 is larger than
			//UINT32_MAX,then there will be an overflow
			if(f1.first>=(UINT64_MAX/2)||f2.first>=(UINT64_MAX/2)){
				string s=string("Error, f(") + std::to_string(i) +string(") caused overflow!");
				throw std::overflow_error(s);
				return;
			}

			uint64_t sum = f1.first + f2.first;

			//Check if it's divisible by 3,
			string s = fbfp::isFizz(sum) ? "Fizz" : "";

			//Check if it's divisible by 5,if it's also divisible by 3 then we
			//mark it as "Fizz + Buzz"
			s = fbfp::isBuzz(sum) ? (!s.empty() ? s + " + Buzz" : "Buzz") : s;

			//Check if it's a prime,we only do this if it's not divisible by 3 or 5
			//because a number whose is multiple of 3 and 5 is not a prime(excluding 3,5)
			if(s.empty())
				s = fbfp::isPrime(sum) ? "FizzBuzz" : std::to_string(sum);
			result.emplace_back(sum,s);
		}
	}

};
}
