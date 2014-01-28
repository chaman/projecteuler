/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
*/


#include <iostream>

using namespace std;

int main(int argc,char** argv)
{
    int max = 1;
    unsigned long curval = 0;
    int count = 0;
    int out = 0;
    for(int i = 1;i<=1000000;i++) {
        curval = i;
        count = 1;
        while(curval != 1) {

            if(curval%2==0) {
                curval=curval/2;
            } else
                curval = 3*curval + 1;

            count++;
       }

       if(count>max) {
            max = count;
            out = i;
       }
    }

    cout << out << " " << max;
    return 0;
}



