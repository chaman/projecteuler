/*
n! means n × (n − 1) × ... × 3 × 2 × 1

Find the sum of the digits in the number 100!
*/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int toint(char c)
{
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
        }

        return 0;
}

char tochar(int c)
{
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
        }

        return '0';
}

string mult(string a,string b)
{
        int m = a.size();
        int n = b.size();
        string w = "",ret="",u,v;
        int k=0,buff,t,f1,f2;
        w.clear();
        for(int c = 0;c<(m+n);c++)
          w += "0";

        for(int j = a.size()-1;j>=0;j--)
           u += a[j];
        for(int j = b.size()-1;j>=0;j--)
           v += b[j];

        for(int j = 0;j<n;j++)
        {
           k = 0;
           for(int i = 0;i<m;i++)
           {
            t = toint(u[i])*toint(v[j]) + toint(w[i+j]) + k;
            buff = t%10;
            k = t/10;
            w[i+j] = tochar(buff);
           }
           w[j+m] = tochar(k) ;


        }
        for(int j = w.size()-1;j>=0;j--)
           ret += w[j];
        f1 = ret.find_first_of("0");
        if(f1!= -1)
        {
            f2 = ret.find_first_not_of("0");
            ret.replace(f1,f2,"");
        }
        return ret;
}

int main(int argc,char** argv)
{
        string out = "1";
        int sum = 0;
        char buffer[4];
        for(int i = 1;i<=100;i++)
        {
          itoa(i,buffer,10);
          out = mult(out,buffer);
        }

        for(int i = 0;i<=out.size();i++)
            sum += toint(out[i]);

        cout << out << endl << endl << sum;
}
