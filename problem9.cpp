/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^(2) + b^(2) = c^(2)

For example, 3^(2) + 4^(2) = 9 + 16 = 25 = 5^(2).

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

//Brute Force Method.
#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
    //int a,b,c;
    for(int i = 1;i<=500;i++)
    {
        for(int j = 1;j<=500;j++)
        {
                for(int k = 1;k<=500;k++)
                {
                        if((i+j+k)==1000 && (k*k==i*i+j*j))
                        {
                                cout << i << " " << j << " " << k << " Product : " << i*j*k << endl;
                                break;
                        }
                }

        }

    }
}
