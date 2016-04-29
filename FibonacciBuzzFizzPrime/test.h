/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 29,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	Test cases for FibonacciBuzzFizzPrime.
*****************************************************************************/

#include <vector>
#include <stdint.h>
#include "FibonacciBuzzFizzPrime.h"
#include "gtest/gtest.h"

using namespace fbfp;

//Testing isPrime function,prime numbers are chosen from The Prime Pages
// https://primes.utm.edu/lists/small/millions/
TEST(isPrime,TrueCases){
	EXPECT_TRUE(isPrime(2));
	EXPECT_TRUE(isPrime(3));
	EXPECT_TRUE(isPrime(5));
	EXPECT_TRUE(isPrime(7));
	EXPECT_TRUE(isPrime(373));
	EXPECT_TRUE(isPrime(997));
	EXPECT_TRUE(isPrime(98411));
	EXPECT_TRUE(isPrime(961751543));
}

//Testing isPrime function,prime numbers are chosen from The Prime Pages
// https://primes.utm.edu/lists/small/millions/
TEST(isPrime,FalseCases){
	EXPECT_FALSE(isPrime(0));
	EXPECT_FALSE(isPrime(1));
	EXPECT_FALSE(isPrime(4));
	EXPECT_FALSE(isPrime(6));
	EXPECT_FALSE(isPrime(8));
	EXPECT_FALSE(isPrime(98412));
	EXPECT_FALSE(isPrime(961751544));
}

//Testing if the number is divisible by 3
TEST(isBuzz,TrueCases){
	EXPECT_TRUE(isBuzz(3));
	EXPECT_TRUE(isBuzz(6));
	EXPECT_TRUE(isBuzz(59049));
	EXPECT_TRUE(isBuzz(205891132094649));
	EXPECT_TRUE(isBuzz(16677181699666569));
}

//Testing if the number is not divisible by 3
TEST(isBuzz,FalseCases){
	EXPECT_FALSE(isBuzz(0));
	EXPECT_FALSE(isBuzz(1));
	EXPECT_FALSE(isBuzz(2));
	EXPECT_FALSE(isBuzz(4));
	EXPECT_FALSE(isBuzz(4294967296));
}

//Testing if the number is divisible by 5
TEST(isFizz,TrueCases){
	EXPECT_TRUE(isFizz(5));
	EXPECT_TRUE(isFizz(10));
	EXPECT_TRUE(isFizz(1000));
	EXPECT_TRUE(isFizz(298023223876953125));
	EXPECT_TRUE(isFizz(UINT64_MAX));
}

//Testing if the number is not divisible by 5
TEST(isFizz,FalseCases){
	EXPECT_FALSE(isFizz(0));
	EXPECT_FALSE(isFizz(1));
	EXPECT_FALSE(isFizz(2));
	EXPECT_FALSE(isFizz(4));
	EXPECT_FALSE(isFizz(UINT32_MAX-1));
	EXPECT_FALSE(isFizz(UINT64_MAX-1));
}

//Testing n=0,1,2
TEST(FibonacciBuzzFizzPrime,StartCases){
	FBFP temp;
	std::vector<fbfp::fbfp_pair> result;

	temp.generate(0,result);
	fbfp::fbfp_pair p=result[0];
	EXPECT_EQ(1,result.size());
	EXPECT_EQ(0,p.first);
	EXPECT_EQ("0",p.second);

	result.clear();
	temp.generate(1,result);
	EXPECT_EQ(2,result.size());

	p=result[0];
	EXPECT_EQ(0,p.first);
	EXPECT_EQ("0",p.second);

	p=result[1];
	EXPECT_EQ(1,p.first);
	EXPECT_EQ("1",p.second);

	result.clear();
	temp.generate(2,result);
	EXPECT_EQ(3,result.size());

	p=result[0];
	EXPECT_EQ(0,p.first);
	EXPECT_EQ("0",p.second);

	p=result[1];
	EXPECT_EQ(1,p.first);
	EXPECT_EQ("1",p.second);

	p=result[2];
	EXPECT_EQ(1,p.first);
	EXPECT_EQ("1",p.second);
}

//Testing illegal cases n<0;
TEST(FibonacciBuzzFizzPrime,IllegalCases){
	FBFP temp;
	std::vector<fbfp::fbfp_pair> result;
	string error="Error, n must >=0!";

	EXPECT_ANY_THROW(temp.generate(-1,result));
	EXPECT_ANY_THROW(temp.generate(INT32_MIN,result));
}

//Testing overflow cases, fibonacci > UINT32_MAX
TEST(FibonacciBuzzFizzPrime,OverflowCases){
	FBFP temp;
	std::vector<fbfp::fbfp_pair> result;
	string error="Error, n must >=0!";

	//(9278 ms)
	EXPECT_NO_THROW(temp.generate(93,result));
	EXPECT_ANY_THROW(temp.generate(94,result));	//(2984 ms)
	EXPECT_ANY_THROW(temp.generate(100,result));
}

//Testing normal cases
TEST(FibonacciBuzzFizzPrime,NormalCases){
	FBFP temp;
	std::vector<fbfp::fbfp_pair> result;

	temp.generate(20,result);
	fbfp::fbfp_pair p=result[15];

	EXPECT_EQ(610,p.first);
	EXPECT_EQ("Fizz",p.second);

	p=result[16];
	EXPECT_EQ(987,p.first);
	EXPECT_EQ("Buzz",p.second);

	p=result[17];
	EXPECT_EQ(1597,p.first);
	EXPECT_EQ("FizzBuzz",p.second);

	p=result[20];
	EXPECT_EQ(6765,p.first);
	EXPECT_EQ("Fizz + Buzz",p.second);

}


