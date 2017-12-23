/*
ID: ao.fara1
LANG: C++
TASK: milk2
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
using namespace std;

pair <int ,int> x[5001];

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            x[i].first = u;
            x[i].second = v;
        }
    if(n==1)
    {
        printf("%d 0\n",x[0].second - x[0].first);
        return 0;
    }
    int milked =0,notmilk=0;
    sort(x,x+n);
    for(int i=1;i<n;i++)                  //  x[i].first   //x[i].second
    {
        if(x[i].first <=x[i-1].second)
        {
            if(x[i].second > x[i-1].second)
            {
                x[i].first = x[i-1].first;
            }
            else
            {
                x[i].first = x[i-1].first;
                x[i].second = x[i-1].second;
            }
        }
        else // not milked range
        {
            int a = x[i].first - x[i-1].second;
            notmilk = max(notmilk,a);
        }
        int b = x[i].second - x[i].first;
        milked = max(milked, b);
    }

    printf("%d %d\n",milked,notmilk);

    return 0;
}



