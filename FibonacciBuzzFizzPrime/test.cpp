/*
 * test.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Lichao
 */

#include <vector>
#include "FibonacciBuzzFizzPrime.h"
#include "gtest/gtest.h"

using namespace fbfp;

//Testing isPrime function,prime numbers are chosen from The Prime Pages
// https://primes.utm.edu/lists/small/millions/
TEST(isPrime,NormalCases){
	std::vector<uint64_t> primes={2,3,5,7,373,997,98411,961751543};
	for(uint64_t p:primes)
		EXPECT_TRUE(isPrime(p));
}

//Testing isPrime function,prime numbers are chosen from The Prime Pages
// https://primes.utm.edu/lists/small/millions/
TEST(isPrime,FalseCases){
	std::vector<uint64_t> numbers={0,1,4,6,8,98412,961751544};
	for(uint64_t n:numbers)
		EXPECT_FALSE(isPrime(n));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
