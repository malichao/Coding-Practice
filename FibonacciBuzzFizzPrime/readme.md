# FibonacciBuzzFizzPrime
A program to solve the following problem.  
  
	Generating the first n Fibonacci numbers F(n), printing ...  
	- ... "Buzz" when F(n) is divisible by 3.  
	- ... "Fizz" when F(n) is divisible by 5.  
	- ... "BuzzFizz" when F(n) is prime.  
	- ... the value F(n) otherwise.  
	  
=====  
##Solution  
The first step will be generating the Fibonacci series,and then check if the number is divisible by 3 or 5,and check if the number is a prime number.Since Fibonacci series grows expoentially, 64bit int data type is used to store the values.To make the program more clear and for easy testing,the results are stored in std::pair:  
	typedef std::pair<uint64_t, string> fbfp_pair;  
  
Since the problem didn't specify how to print a number that is divisible by 3 and 5 both,e.g.,f(20)=6765,so I print such a number as "Fizz + Buzz" to avoid confusing with prime numbers.  
  
The following cases are consider as error and exceptions will be thrown:  
	-when n<0  
	-when n is large that causes overflow  
  
