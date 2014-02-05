/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n
which divide evenly into n).
If d(a) = b and d(b) = a, where a <> b, then a and b are an amicable pair
and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc,char** argv)
{
        int sum =0,cnt=0;
        int amic1 = 0;
        int amic2 = 0;

        int mapping[10000];
        int present = 0;
        int i = 2;
        for(int i = 0;i<10000;i++)
             mapping[i] = 0;
        while(i<10000)
        {
           if(mapping[i] == 0)
           {
               amic1 = 0;amic2=0;
               for(int j = 1;j<=i/2;j++)
               {
                  if(i%j==0) amic1 += j;
               }

               for(int p = 1;p<=amic1/2;p++)
               {
                   if(amic1%p==0)  amic2 += p;
               }
               if(i==amic2 && i != amic1)
               {
                    sum += amic1;
                    sum += amic2;
                    mapping[i] = 1;
                    mapping[amic1] = 1;
               }

           }
           i++;

       }

       cout << sum ;
       return 0;
}
