/*
ID: ao.fara1
LANG: C++
TASK: milk
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

pair <int,int> x[5001];

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        x[i].first = a;
        x[i].second = b;
    }

    sort(x,x+m);

    int i=0;
    int ans = 0;
    while(n)
    {
        int q = min(n,x[i].second);
        n -= q;
        ans += q*x[i].first;
        i++;
    }
    printf("%d\n",ans);
    return 0;
}



