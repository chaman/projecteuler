/*
A palindromic number reads the same both ways. The largest palindrome
made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <cmath>
#include<vector>

using namespace std;

int main(int argc,char** argv)
{

    int mult,max = 1,m,t,p;
    vector<int> s;
    int palin;
    for (int i = 100;i<=999;i++) {

        for(int j=100;j<=999;j++) {
            m = i*j;
            mult= m;
            palin = 1;
            s.clear();
            while(mult != 0) {
                s.push_back(mult%10);
                mult = mult/10;
            }
            //cout << s << endl;
            for(t=0,p=s.size()-1;t<=ceil(s.size()/2);t++,p--) {
                if(s[t] != s[p])
                    palin = 0;
            }
            if(palin && m > max)
                max = m;
        }
    }
    cout << max;


}
