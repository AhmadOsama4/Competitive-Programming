/*
ID: ao.fara1
LANG: C++
TASK: crypt1
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

int vis[10];

bool valid(int n)
{
    while(n)
    {
        int a = n%10;
        if(!vis[a])
            return false;
        n = (n-a)/10;
    }
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        vis[a] = 1;
    }
    int ans = 0;
    for(int i=100;i<1000;i++)
    {
        for(int j=10;j<100;j++)
        {
            int a = i*(j%10) , b = i*( (j-(j%10))/10);
            if( a>= 1000 || a<=100 || b>=1000 || b<=100)
                continue;
            if( valid(i) && valid(j) && valid(a) && valid(b) && valid(i*j) )
                ans++;

            /*if( i == 222 && j == 22)
                cout<<a<<"    "<<b<<endl;*/
        }

    }
    printf("%d\n",ans);
    return 0;
}



