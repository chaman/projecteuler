/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6^(th) prime is 13.

What is the 10001^(st) prime number?

*/

#include<iostream>
#include "strmath.h"
#include<cmath>

using namespace std;

int isprime(int n)
{
	for(int i = 3;i <= sqrt(n);i+=2)
		if(n % i == 0 && n != i) return 0;
	return 1;
}

int main(int argc,char** argv)
{
   int count = 1;
   unsigned long i = 3;
   while(1) {

        if(isprime(i)) {
         	count++;
            if(count == 10001)
                break;
        }
        i += 2;
	}

	cout << i;

	return 0;
}
