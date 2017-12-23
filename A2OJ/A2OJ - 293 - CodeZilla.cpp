#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <string.h>
    using namespace std;

bool yes(string s,char c)
{
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        s[i] = tolower(s[i]);
        if(s[i] == c)
            return true;
    }
    return false;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        int n,f=0;
        string s1,s2;
        scanf("%d",&n);
        cin>>s1>>s2;
        s1[0] = tolower(s1[0]),s2[0] = tolower(s2[0]);
        if(s1[0] != s2[0])
            f=1;
        printf("Case %d:\n",k+1);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            if(f==1 || yes(s,s1[0]))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
