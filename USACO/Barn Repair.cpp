/*
ID: ao.fara1
LANG: C++
TASK: barn1
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

int stalls[201];
int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int m,s,c;
    vector <int> ans;
    int a,b,minn,maxx;
    scanf("%d%d%d",&m,&s,&c);

    for(int i=0;i<c;i++)
    {
        scanf("%d",&stalls[i]);
    }
    sort(stalls,stalls+c);
    minn = stalls[0];
    maxx = stalls[c-1];
    for(int i=1;i<c;i++)
    {
        ans.push_back(stalls[i] - stalls[i-1] -1);
    }
    int res = maxx - minn +1 ,si;
    sort(ans.begin(),ans.end());
    si = ans.size();

    for(int i=si-1;i>si-m && i>=0;i--)
    {
        res -= ans[i];
    }
    printf("%d\n",res);
    return 0;
}



