/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
*/

#include<iostream>
using namespace std;

const int N = 15;
int num[15][50]={ {75},
                    {95, 64},
                    {17, 47, 82},
                    {18, 35, 87, 10},
                    {20, 4, 82, 47, 65},
                    {19, 1, 23, 75, 3, 34},
                    {88, 2, 77, 73, 7, 63, 67},
                    {99, 65, 4, 28, 6, 16, 70, 92},
                    {41, 41, 26, 56, 83, 40, 80, 70, 33},
                    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
                    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
                    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
                    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
                    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
                    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
                  };
int sum[15][50] = {0};
int recurSum(int n)
{
    int s = 0;
    if( n == 1)
        return 0;
    for(int i = 0;i<=n-1;i++)
    {
        if(n == N-1)
        {
            if(num[n][i] > num[n][i+1])
                s = num[n][i];
            else
                s = num[n][i+1];

            sum[n-1][i] += num[n-1][i] + s;
        }
        else
        {
             if(sum[n][i] > sum[n][i+1])
                s = sum[n][i];
            else
                s = sum[n][i+1];

            sum[n-1][i] += num[n-1][i] + s;
        }
    }
    return recurSum(n-1);
}
int main(int argc,char** argv)
{

    recurSum(N-1);
    int maxpath = num[0][0];
    int n = 0;
    int rowpos = 0;

    while(n <=N-2)
    {
        if(sum[n+1][rowpos] > sum[n+1][rowpos+1])
        {
            //cout << num[n+1][rowpos];
            maxpath += num[n+1][rowpos];

        }
        else
        {
           //cout << num[n+1][rowpos + 1];
           maxpath += num[n + 1][rowpos + 1];
           rowpos = rowpos + 1;
        }
        //cout << endl;
        n++;
    }

    cout << maxpath << endl << endl;


    return 0;
}

