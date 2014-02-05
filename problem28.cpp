/*
Starting with the number 1 and moving to the right in a clockwise direction a
5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/


#include<iostream>

using namespace std;

int main(int argc,char** argv)
{
    unsigned int sum = 1;
    int first = 1;
    int second = 1;
    int third = 1;
    int fourth = 1;
    int diff = 0;
    for(int i = 3;i<=1001;i+=2)
    {
        first = i*i;
        diff = i - 1;
        /*
        second = first - diff;
        third = second - diff;
        fourth = third - diff;
        sum += first + second + third + fourth;*/
        for(int j = 0;j<4;j++)
            sum += first - j*diff;
    }

    cout << sum;


    return 0;
}
