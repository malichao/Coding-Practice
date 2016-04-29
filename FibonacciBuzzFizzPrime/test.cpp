/*
 * test.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Lichao
 */

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

TEST(isFizz,TrueCases){
	EXPECT_TRUE(isFizz(3));
	EXPECT_TRUE(isFizz(6));
	EXPECT_TRUE(isFizz(59049));
	EXPECT_TRUE(isFizz(205891132094649));
	EXPECT_TRUE(isFizz(16677181699666569));
}

TEST(isFizz,FalseCases){
	EXPECT_FALSE(isFizz(0));
	EXPECT_FALSE(isFizz(1));
	EXPECT_FALSE(isFizz(2));
	EXPECT_FALSE(isFizz(4));
	EXPECT_FALSE(isFizz(4294967296));
}

TEST(isBuzz,TrueCases){
	EXPECT_TRUE(isBuzz(5));
	EXPECT_TRUE(isBuzz(10));
	EXPECT_TRUE(isBuzz(1000));
	EXPECT_TRUE(isBuzz(298023223876953125));
	EXPECT_TRUE(isBuzz(UINT64_MAX));
}

TEST(isBuzz,FalseCases){
	EXPECT_FALSE(isBuzz(0));
	EXPECT_FALSE(isBuzz(1));
	EXPECT_FALSE(isBuzz(2));
	EXPECT_FALSE(isBuzz(4));
	EXPECT_FALSE(isBuzz(UINT32_MAX-1));
	EXPECT_FALSE(isBuzz(UINT64_MAX-1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
