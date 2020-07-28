/*
7) Factor an input integer into it's prime numbers.  Create a 
structure to hold the array of prime numbers.  Any number between
[2,10000] will be a valid number to check for prime factors.

struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

Output the number and it's primes -> 120 = 2^3 * 3^1 * 5^1
So create a function 

Primes *factor(int);-> Input an integer, return all prime factors
void prntPrm(Primes *); -> Output all prime factors
*/

#include <iostream>
#include <math.h>

struct Prime
{
	unsigned short prime;
	unsigned char power;
};
struct Primes
{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int);	//-> Input an integer, return all prime factors
void prntPrm(Primes *); // -> Output all prime factors

int main()
{
	int toFact = 0;
	std::cout << "Enter Number: " <<std::endl;
	std::cin >> toFact;
	prntPrm(factor(toFact));
	return 0;
}

Primes *factor(int num)
{
	Primes* allPrime = new Primes;
	allPrime->prime = new Prime[3];
	allPrime->nPrimes = 3;

	Prime power2;
	power2.prime = 2;
	while (num % 2 == 0)
	{
		power2.power += 1;
		//std::cout << "2\t";
		num = num / 2;
	}
	allPrime->prime[0] = power2;

	int count=1;
	for (int i = 3; i <= std::sqrt(num); i = i + 2)
	{
		
		while (num % i == 0)
		{
			Prime p;
			p.prime = i;
			p.power = 1;
			//std::cout << i << "\t";
			num = num / i;
			allPrime->prime[count] = p;
			count++;
		}
	}
	if (num > 2){
		Prime p;
		p.prime = num;
		p.power = 1;
		allPrime->prime[count] = p;
	}
	return allPrime;
	//std::cout << num << " ****\t";
}

void prntPrm(Primes *toPrint)
{
	for(int i=0;i<toPrint->nPrimes;i++){
		std::cout << toPrint->prime[i].prime << "^" <<( toPrint->prime[i].power + 0) << " * ";
	}
	
}