/*
Euler published the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
However, when n = 40, 40^(2) + 40 + 41 = 40(40 + 1) + 41 is divisible by 41,
and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

Using computers, the incredible formula  n² − 79n + 1601 was discovered,
which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients,
 −79 and 1601, is −126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the
maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include<iostream>
#include<complex>
#include<cstdio>

#define N 1000000
using namespace std;


int primes[N];
void seive()
{
    for(int i = 0;i<N;i++)
        primes[i] = 1;


    for(int j = 2;j<sqrt(N);j++)
    {
        if(primes[j] == 1)
        {
            for(int s = 2; s < N/j;s++)
            {
                primes[s*j] = 0;
            }
        }

    }
}

int main(int argc,char** argv)
{
    int n = 0;
    int quad = 0;
    int maxpcount = 0;
    int fproduct = 0;
    int pcount = 0;
    int c_a = 0;
    int c_b = 0;
    seive();
    for(int a = -1000;a<=1000;a++)
    {
        for(int b = -1000;b<=1000;b++)
        {
            n = 0;
            pcount = 0;
            quad = n*n + a*n + b;
            if(quad > 0)
            {
                while(primes[quad])
                {
                    pcount++;
                    n++;
                    quad = n*n + a*n + b;

                }

            }

            if(pcount > maxpcount)
            {
                maxpcount = pcount;
                fproduct = a*b;
                c_a = a;
                c_b = b;
            }

        }

    }
    cout << "maximum primes : " << maxpcount << endl;
    cout << "coefficient a : " << c_a << "   coefficient b : " << c_b << endl;
    cout << "coefficient product : "  << fproduct;
    return 0;
}
