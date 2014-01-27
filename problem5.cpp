/* Problem 5
2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest number that is evenly divisible by all of the numbers
from 1 to 20?
*/

#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
    int y = 0;
    int num = 20;
    int remainder = 0;
    int isdiv = 1;

    while(y==0) {
        for(int i = 1;i<=20;i++) {
            remainder = num%i;
            if(remainder != 0) {
                isdiv = 0;
                break;
            }
        }
        if(isdiv == 1) {
            y = 1;
        }
        else {
          isdiv = 1;
          num = num + 20;
        }

    }
    cout << num;
    return 0;
}

