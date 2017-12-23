/*
ID: ao.fara1
LANG: C++
TASK: palsquare
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

string bases = "0123456789ABCDEFGHIJKLMN";

string tobase(int n,int b)
{
    string check="";

    while(n)
    {
        check += bases[n%b];
        n /= b;
    }

    reverse(check.begin(),check.end());

    return check;

}

bool ispal(string s)
{
    string u = s;
    reverse(u.begin(),u.end());
    return u == s;
}
int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int b;
    scanf("%d",&b);

    for(int i=1;i<=300;i++)
    {
        string num = tobase(i,b),numsq = tobase(i*i,b);
        if(ispal(numsq))
            cout<<num<<" "<<numsq<<endl;
    }
    return 0;
}



