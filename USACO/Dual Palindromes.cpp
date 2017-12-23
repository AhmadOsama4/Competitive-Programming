/*
ID: ao.fara1
LANG: C++
TASK: dualpal
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
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,s;
    scanf("%d%d",&n,&s);

    int lim = 0;
    for(int i=1;lim <n;i++)
    {
        int counter = 0;
        for(int b=2;b<=10;b++)
        {
            if( ispal( tobase(s+i,b) ) )
                counter++;
            if(counter == 2)
            {
                printf("%d\n",s+i);
                lim++;
                break;
            }
        }
    }
    return 0;
}



