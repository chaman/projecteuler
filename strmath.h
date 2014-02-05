
#ifndef	STRMATH_H
#define STRMATH_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
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
        }
        */

        return c - '0';
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
        }
        */
        return '0' + c%10;
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

        int a_size = m - 1;
        for(int j = a_size;j>=0;j--)
           u += a[j];

        int b_size = n - 1;
        for(int j = b_size;j>=0;j--)
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
        int w_size = w.size()-1;
        for(int j = w_size;j>=0;j--)
           ret += w[j];

        f1 = ret.find_first_of("0");
        if(f1 == 0)
        {
            f2 = ret.find_first_not_of("0");
            ret.replace(f1,f2,"");
        }
        return ret;
}

string power(string base,string pow)
{
    string p = "1";
    int raise = atoi(pow.c_str());
    for(int i = 1;i<=raise;i++)
    {
       //cout << i << endl;
       p = mult(p,base);
    }
    return p;
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

int add_rev(string a,string b)
{
        //int a_len = a.size();
        //int b_len = b.size();
        int len = a.size(),k=0,u,v,w;
        string s = "";
        string out = "",ret="";
        /*
        if(a_len < b_len)
        {
            len = b_len;

           // for(int i = 0;i<b_len-a_len;i++)
           //     s+="0";
           // a.insert(0,s);
        }
        else
        {
            len = a_len;
            //for(int i = 0;i<a_len-b_len;i++)
            //    s+="0";
            //b.insert(0,s);
        }*/
        for(int j = len-1;j>=0;j--)
        {
            u = toint(a[j]);
            v = toint(b[j]);
            w = ( u + v + k ) % 10;
            if(w%2==0)
                return 0;
            out += tochar(w) ;
            k = ( u + v + k ) / 10;
        }
        if(k > 0 && k%2==0)
            return 0;

        //for(int j = out.size()-1;j>=0;j--)
        //   ret += out[j];


        return 1;
}


#endif
