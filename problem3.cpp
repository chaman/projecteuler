/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>
#include <cmath>

using namespace std;
int isprime(unsigned long long n)
{
	for(int i = 3;i<= sqrt(n);i+=2)
		if((n % i) == 0) return 0;
	return 1;
}

int main(int argc, char** argv)
{
    unsigned long long input = 600851475143;
	unsigned long long max = 3;

    for(int i = 3;i<=sqrt(input);i+=2)
    {
		if(input%i==0)
		{
			if(i>max && isprime(i))
				max = i;
		}
	}

	cout << max;

    return 0;
}
