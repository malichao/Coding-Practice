# FibonacciBuzzFizzPrime
A program to solve the following problem.  
  
	Generating the first n Fibonacci numbers F(n), printing ...  
	- ... "Buzz" when F(n) is divisible by 3.  
	- ... "Fizz" when F(n) is divisible by 5.  
	- ... "BuzzFizz" when F(n) is prime.  
	- ... the value F(n) otherwise.  
	  
##Solution

The first step will be generating the Fibonacci series,and then check if the number is divisible by 3 or 5,and check if the number is a prime number.Since Fibonacci series grows expoentially, 64bit int data type is used to store the values.To make the program more clear and for easy testing,the results are stored in std::pair:  
  
	typedef std::pair<uint64_t, string> fbfp_pair;  
  
Since the problem didn't specify how to print a number that is divisible by 3 and 5 both,e.g.,f(20)=6765,so I print such a number as "Fizz + Buzz" to avoid confusing with prime numbers.  
  
The following cases are consider as error and exceptions will be thrown:  
  
	-when n<0  
	-when n is large that causes overflow  
  
##Build

The program is built in Eclipse with Cygwin and GCC 5.3.0, and with flag -std=c++0x.If you try to compile the code on Windos with eclipse please configure accordingly.

##Run

There are two ways to run the program,either calling it without and argument and the program will run with defult number 94,which is the number that causes overflow.Or Calling it with a number as arugument and the program generates the corresponding series.  
Here is the defult output:  
  
	Generating Fibonacci for n= 94  
	f(0)	0		0  
	f(1)	1		1  
	f(2)	1		1  
	f(3)	2		FizzBuzz  
	f(4)	3		FizzBuzz  
	f(5)	5		FizzBuzz  
	f(6)	8		8  
	f(7)	13		FizzBuzz  
	f(8)	21		Buzz  
	f(9)	34		34  
	f(10)	55		Fizz  
	f(11)	89		FizzBuzz  
	f(12)	144		Buzz  
	f(13)	233		FizzBuzz  
	f(14)	377		377  
	f(15)	610		Fizz  
	f(16)	987		Buzz  
	f(17)	1597		FizzBuzz  
	f(18)	2584		2584  
	f(19)	4181		4181  
	f(20)	6765		Fizz + Buzz  
	f(21)	10946		10946  
	f(22)	17711		17711  
	f(23)	28657		FizzBuzz  
	f(24)	46368		Buzz  
	f(25)	75025		Fizz  
	f(26)	121393		121393  
	f(27)	196418		196418  
	f(28)	317811		Buzz  
	f(29)	514229		FizzBuzz  
	f(30)	832040		Fizz  
	f(31)	1346269		1346269  
	f(32)	2178309		Buzz  
	f(33)	3524578		3524578  
	f(34)	5702887		5702887  
	f(35)	9227465		Fizz  
	f(36)	14930352		Buzz  
	f(37)	24157817		24157817  
	f(38)	39088169		39088169  
	f(39)	63245986		63245986  
	f(40)	102334155		Fizz + Buzz  
	f(41)	165580141		165580141  
	f(42)	267914296		267914296  
	f(43)	433494437		FizzBuzz  
	f(44)	701408733		Buzz  
	f(45)	1134903170		Fizz  
	f(46)	1836311903		1836311903  
	f(47)	2971215073		FizzBuzz  
	f(48)	4807526976		Buzz  
	f(49)	7778742049		7778742049  
	f(50)	12586269025		Fizz  
	f(51)	20365011074		20365011074  
	f(52)	32951280099		Buzz  
	f(53)	53316291173		53316291173  
	f(54)	86267571272		86267571272  
	f(55)	139583862445		Fizz  
	f(56)	225851433717		Buzz  
	f(57)	365435296162		365435296162  
	f(58)	591286729879		591286729879  
	f(59)	956722026041		956722026041  
	f(60)	1548008755920		Fizz + Buzz  
	f(61)	2504730781961		2504730781961  
	f(62)	4052739537881		4052739537881  
	f(63)	6557470319842		6557470319842  
	f(64)	10610209857723		Buzz  
	f(65)	17167680177565		Fizz  
	f(66)	27777890035288		27777890035288  
	f(67)	44945570212853		44945570212853  
	f(68)	72723460248141		Buzz  
	f(69)	117669030460994		117669030460994  
	f(70)	190392490709135		Fizz  
	f(71)	308061521170129		308061521170129  
	f(72)	498454011879264		Buzz  
	f(73)	806515533049393		806515533049393  
	f(74)	1304969544928657		1304969544928657  
	f(75)	2111485077978050		Fizz  
	f(76)	3416454622906707		Buzz  
	f(77)	5527939700884757		5527939700884757  
	f(78)	8944394323791464		8944394323791464  
	f(79)	14472334024676221		14472334024676221  
	f(80)	23416728348467685		Fizz + Buzz  
	f(81)	37889062373143906		37889062373143906  
	f(82)	61305790721611591		61305790721611591  
	f(83)	99194853094755497		FizzBuzz  
	f(84)	160500643816367088		Buzz  
	f(85)	259695496911122585		Fizz  
	f(86)	420196140727489673		420196140727489673  
	f(87)	679891637638612258		679891637638612258  
	f(88)	1100087778366101931		Buzz  
	f(89)	1779979416004714189		1779979416004714189  
	f(90)	2880067194370816120		Fizz  
	f(91)	4660046610375530309		4660046610375530309  
	f(92)	7540113804746346429		Buzz  
	f(93)	12200160415121876738		12200160415121876738  
	Error, f(94) caused overflow!  

##Test

The grogram is tested with GoogleTest framework and GCov.At the time I built it passed all the 10 tests and had 100% code coverage.Here is the test result.  
  
	                                              Code coverage						  
	FibonacciBuzzFizzPrime.h	40	40	100.0%  
	fbfp::FBFP::generate()		27	27	100.0%  
	fbfp::isBuzz(unsigned long)	3	3	100.0%  
	fbfp::isFizz(unsigned long)	3	3	100.0%  
	fbfp::isPrime(unsigned long)	7	7	100.0%  
  
	[==========] Running 10 tests from 4 test cases.  
	[----------] Global test environment set-up.  
	[----------] 2 tests from isPrime  
	[ RUN      ] isPrime.TrueCases  
	[       OK ] isPrime.TrueCases (0 ms)  
	[ RUN      ] isPrime.FalseCases  
	[       OK ] isPrime.FalseCases (0 ms)  
	[----------] 2 tests from isPrime (0 ms total)  
  
	[----------] 2 tests from isBuzz  
	[ RUN      ] isBuzz.TrueCases  
	[       OK ] isBuzz.TrueCases (0 ms)  
	[ RUN      ] isBuzz.FalseCases  
	[       OK ] isBuzz.FalseCases (0 ms)  
	[----------] 2 tests from isBuzz (0 ms total)  
  
	[----------] 2 tests from isFizz  
	[ RUN      ] isFizz.TrueCases  
	[       OK ] isFizz.TrueCases (0 ms)  
	[ RUN      ] isFizz.FalseCases  
	[       OK ] isFizz.FalseCases (0 ms)  
	[----------] 2 tests from isFizz (0 ms total)  
  
	[----------] 4 tests from FibonacciBuzzFizzPrime  
	[ RUN      ] FibonacciBuzzFizzPrime.StartCases  
	[       OK ] FibonacciBuzzFizzPrime.StartCases (0 ms)  
	[ RUN      ] FibonacciBuzzFizzPrime.IllegalCases  
	[       OK ] FibonacciBuzzFizzPrime.IllegalCases (1 ms)  
	[ RUN      ] FibonacciBuzzFizzPrime.OverflowCases  
	[       OK ] FibonacciBuzzFizzPrime.OverflowCases (10636 ms)  
	[ RUN      ] FibonacciBuzzFizzPrime.NormalCases  
	[       OK ] FibonacciBuzzFizzPrime.NormalCases (0 ms)  
	[----------] 4 tests from FibonacciBuzzFizzPrime (10637 ms total)  
  
	[----------] Global test environment tear-down  
	[==========] 10 tests from 4 test cases ran. (10637 ms total)  
	[  PASSED  ] 10 tests.  

##Future Work

Currently the primality test code is a naive method,it works well with numbers smaller than 2^32 but very inefficient with large numbers.To improve the efficiency with large numbers, [BPSW](http://www.trnicely.net/misc/bpsw.html) could be used.It's been proven that it could verify the primality of a number within 2^64(of course it works beyond this range) in a polynomial time.The main steps of this algorithm is as follows.  
	-Process all N < 3 and all even N.  
	-Check N for any small prime divisors p < 1000.  
	-Perform a Miller-Rabin (strong probable prime) test, base 2, on N.  
	-Perform a (standard or strong) Lucas-Selfridge test on N, using Lucas sequences with the parameters suggested by Selfridge.  
	
