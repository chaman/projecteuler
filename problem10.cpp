/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include<iostream>
#include "strmath.h"
#include<cmath>

using namespace std;

int isprime(int n)
{
	for(int i = 3;i<= sqrt(n);i+=2)
		if((n % i) == 0) return 0;
	return n;
}

int main(int argc,char** argv)
{
   unsigned long long sum = 2;
   int i = 3;
   while(i < 2000000) {
        sum += isprime(i);
        i+=2;
   }
   cout << sum << endl;
   return 0;
}
