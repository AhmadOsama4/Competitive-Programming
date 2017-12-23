/*
ID: ao.fara1
LANG: C++
TASK: friday
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

int ans[8];
int calend[32];

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int n,d=2;
    scanf("%d",&n);
    calend[9] = calend[4] = calend[6] = calend[11] = 30;
    calend[1] = calend[3] = calend[5] = calend[7] = calend[8] = calend[10] = calend[12] = 31;

    for(int i=1;i<=n;i++)
    {
        int year = 1900 + i -1;
        if( (year %4 ==0 && year%100 !=0) || (year%400 ==0) )
            calend[2] = 29;
        else
            calend[2] = 28;

        for(int j=1;j<=12;j++)
            {
                d = (d + 13)%7;
                ans[d]++;
                d = (d + calend[j]-13)%7;
            }
    }
    for(int i=1;i<7;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[0]);
    return 0;
}
