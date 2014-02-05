/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means
that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is
called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that
can be written as the sum of two abundant numbers is 24. By mathematical analysis,
it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 However, this upper limit cannot be reduced any further by analysis even though it is known that
 the greatest number that cannot be expressed as the sum of two abundant numbers is less than this
 limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include<iostream>
#include<cstdio>
#include<complex>

#define N 28123
using namespace std;

int abd[N];

void abundant()
{
    int sum;
    abd[0] = 0;
    int div;
    for(int i = 1;i<N;i++)
    {
        sum = 0;
        for(int j = 1;j<=sqrt(i);j++)
        {
            if(i%j == 0)
            {
                sum += j;
                div = i/j;
                if(div < i && div != j)
                   sum += div;
            }

        }

        if(sum > i)
        {
            abd[i] = i;
        }
        else
            abd[i] = 0;

    }

}


int main(int argc,char** argv)
{
    abundant();
    int cnt = 0;
    unsigned long long finalsum = 0;
    unsigned long long interiorsum = 0;
    bool isabundant = false;
    int p = 0;
    for(int i = 1;i<N;i++)
    {
        interiorsum = 0;
        isabundant = false;
        for(int j = 1;j<=i/2;j++)
        {
            p = i - j;
            if(abd[j] > 0 && abd[p] > 0)
            {
                interiorsum = j + p;
                if(interiorsum == i)
                {
                    isabundant = true;
                    break;
                }
                //getchar();

            }
         }
         if(isabundant == false)
         {
           //cout << "not abundant: " << i << endl;
           finalsum += i;
         }
    }

    cout << finalsum;
}
