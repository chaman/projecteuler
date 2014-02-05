/*
The Fibonacci sequence is defined by the recurrence relation:

    F_(n) = F_(n−1) + F_(n−2), where F_(1) = 1 and F_(2) = 1.

Hence the first 12 terms will be:

    F_(1) = 1
    F_(2) = 1
    F_(3) = 2
    F_(4) = 3
    F_(5) = 5
    F_(6) = 8
    F_(7) = 13
    F_(8) = 21
    F_(9) = 34
    F_(10) = 55
    F_(11) = 89
    F_(12) = 144

The 12th term, F_(12), is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>

using namespace std;

int toint(char c)
{
        /*
        switch(c)
        {
            case  '0': return 0;
            case  '1': return 1;
            case  '2': return 2;
            case  '3': return 3;
            case  '4': return 4;
            case  '5': return 5;
            case  '6': return 6;
            case  '7': return 7;
            case  '8': return 8;
            case  '9': return 9;
            default: return 0;
        }*/

        return c - '0';;
}

char tochar(int c)
{
        /*
        switch(c)
        {
            case  0: return '0';
            case  1: return '1';
            case  2: return '2';
            case  3: return '3';
            case  4: return '4';
            case  5: return '5';
            case  6: return '6';
            case  7: return '7';
            case  8: return '8';
            case  9: return '9';
            default: return '0';
        }*/

        return '0' + c%10;
}

string add(string a,string b)
{
        int a_len = a.size();
        int b_len = b.size();
        int len,k=0,u,v,w;
        string s = "";
        string out = "",ret="";
        if(a_len < b_len)
        {
            len = b_len;

            for(int i = 0;i<b_len-a_len;i++)
                s+="0";
            a.insert(0,s);
        }
        else
        {
            len = a_len;
            for(int i = 0;i<a_len-b_len;i++)
                s+="0";
            b.insert(0,s);
        }
        for(int j = len-1;j>=0;j--)
        {
            u = toint(a[j]);
            v = toint(b[j]);
            w = ( u + v + k ) % 10;
            out += tochar(w) ;
            k = ( u + v + k ) / 10;
        }
        if(k > 0)
            out += tochar(k);

        for(int j = out.size()-1;j>=0;j--)
           ret += out[j];


        return ret;
}


int main(int argc,char** argv)
{
        string i = "1";
        string j = "0";
        int cnt = 0;
        while(1)
        {
            i = add(i,j);
            cnt++;
            if(i.size()==1000)
            {
               cout << "i" << endl << i;
                break;
            }
            j = add(j,i);
            cnt++;
            if(j.size()==1000)
            {
               cout << "j" << endl << cnt << endl << j;
               break;
            }
        }

        return 0;
}



