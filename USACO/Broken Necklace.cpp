/*
ID: ao.fara1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

string s;
int n;
int countL(int indx)
{
    int j;
    char cmp = s[indx];
    for(j=0;j<n;j++)
    {
        if(cmp == 'w')
            cmp = s[(indx-j+n)%n];
        if( (s[(indx-j+n)%n]==cmp) || (s[(indx-j+n)%n]=='w'))
            continue;
        else
            break;
    }
    return j;
}

int countR(int indx)
{
    int j;
    char cmp = s[indx%n];
    for(j=0;j<n;j++)
    {
        if(cmp == 'w')
            cmp = s[(indx+j)%n];
        if( (s[(indx+j)%n]==cmp) || (s[(indx+j)%n]=='w'))
            continue;
        else
            break;
    }
    return j;
}

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int ans=0,num=0;
    scanf("%d",&n);
    cin>>s;

    for(int i=0;i<n;i++)
    {
        num = countL(i) + countR(i+1);
       if(num > n)
           num=n;
        ans = max(ans,num);
    }

    printf("%d\n",ans);
    return 0;
}
