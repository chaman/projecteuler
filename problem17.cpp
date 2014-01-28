/*
If the numbers 1 to 5 are written out in words:
one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive
were written out in words, how many letters would be used?
*/

#include<iostream>

using namespace std;

int main(int argc,char** argv)
{
    string a[]= { "",
                  "one",
                  "two",
                  "three",
                  "four",
                  "five",
                  "six",
                  "seven",
                  "eight",
                  "nine",
                  "ten",
                  "eleven",
                  "twelve",
                  "thirteen",
                  "fourteen",
                  "fifteen",
                  "sixteen",
                  "seventeen",
                  "eighteen",
                  "nineteen",
                  "twenty",
                  "thirty",
                  "forty",
                  "fifty",
                  "sixty",
                  "seventy",
                  "eighty",
                  "ninety",
                  "hundred",
                  "thousand"
                };
    int index[101];
    for(int i = 0;i<=100;i++) index[i] = 0;
    index[100] = 28;
    index[20] = 20;
    index[30] = 21;
    index[40] = 22;
    index[50] = 23;
    index[60] = 24;
    index[70] = 25;
    index[80] = 26;
    index[90] = 27;
    int hundred,unit,ten,t;
    int output = 0;
    string out = "";
    for(int i = 1;i<=999;i++) {
        hundred = i/100;
        out = "";
        if(hundred > 0)
        {
            output += a[hundred].size();
            output += a[index[100]].size();

            out += a[hundred] + " " + a[index[100]];

        }
        ten = i%100;
        if(ten > 0 && hundred > 0)
        {
            output += 3;
            out += " and";
        }
        if(ten > 20)
        {
            t = ten/10;
            t = t*10;
            output += a[index[t]].size();
            out += " " + a[index[t]];
        }
        else if(ten >= 10)
        {
            output += a[ten].size();
            out += a[ten];
        }
        unit = i%10;
        if(ten <=10 || ten >= 20)
        {
            output += a[unit].size();
            out += " " + a[unit];
        }

        //output words
        //cout << i << " : " << output << " " << out << endl;
        //getchar();
    }
    //11 for "one thousand"
    cout << output + 11 << endl;

}
