/*
Using names.txt (right click and 'Save Link/Target As...'),
a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order.
Then working out the alphabetical value for each name,
multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN,
which is worth 3 + 15 + 12 + 9 + 14 = 53,
is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc,char** argv)
{
	FILE *fp;
    vector<string> names;
    string s;
    char buffer[500];
    char b;
    char c;
    int sum = 0;
    unsigned long score = 0;
	fp = fopen("names.txt","r");
    if(!fp)
    {
        cout << "ERROR: ";
        return 0;
    }
    int i = 0;
    while(fscanf(fp,"\"%[A-Z]\",",buffer) != EOF)
    {
        names.push_back(buffer);
    }

    sort(names.begin(),names.end());
    for(int i = 0;i<names.size();i++)
    {
        sum = 0;
        for(int j = 0;j<names[i].size();j++)
        {
            sum = sum + (names[i][j] % 64);
        }

        score = score  + (sum * (i + 1));

    }
    cout << score;
	fclose(fp);

}
