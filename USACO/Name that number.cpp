/*
ID: ao.fara1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;

map < string,int > valid,valid2;

int f=0,len;
string into;

string pos[10];

void set_str(string s)
{
    int len1 = s.length();
    string v= "";
    for(int i=0;i<len1;i++)
    {
        v += s[i];
        valid2[v] = 1;
    }
}

void get_str(string s,int n)
{
    if(n >= len)
    {
        if(valid[s])
            {
                cout<<s<<endl;
                f=1;
            }
        return;
    }

    if(!valid2[s])
        return;

    int ind = into[n] - '0';

    for(int i=0;i<3;i++)
    {
        get_str(s+pos[ind][i],n+1);
    }
}

int main()
{
    string s;
    fstream file;
    file.open("dict.txt");

    while(getline(file,s))
    {
        valid[s] = 1;
    }
    file.close();

    map < string,int > :: iterator it;

    valid2[""] = 1;

    for(it=valid.begin();it!=valid.end();it++)
    {
        set_str(it->first);
    }
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    pos[2] = "ABC";
    pos[3] = "DEF";
    pos[4] = "GHI";
    pos[5] = "JKL";
    pos[6] = "MNO";
    pos[7] = "PRS";
    pos[8] = "TUV";
    pos[9] = "WXY";

    cin>>into;
    len = into.length();
    get_str("",0);

    if(!f)
        cout<<"NONE\n";
    return 0;
}



