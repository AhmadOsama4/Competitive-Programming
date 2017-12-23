/*
ID: ao.fara1
LANG: C++
TASK: combo
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

int vis[2][3][101],pos[101];
int n,t=1;

int comb1(int x[])
{
    int ret = 1,cnt = 0,subt = 1;
    t^=1;
    for(int i=0;i<3;i++)
    {
        int a = x[i],cnt=0,tmp=0;
        if(!vis[t][i][a])
            cnt++;
        vis[t][i][a]=1;
        if(vis[t^1][i][a] && vis[t^1][i][a]<2)
            tmp++,vis[t^1][i][a]++;
        for(int j=1;j<3;j++)
        {
            int u = pos[ (a+j)%n], v = pos[ (a-j+n)%n ];
            if(!vis[t][i][u])
            {
                vis[t][i][u]=1;
                cnt++;
                //cout<<cnt<<endl;
            }
            if(vis[t^1][i][u] && vis[t^1][i][u]<2)
                tmp++ , vis[t^1][i][u]++;
            if(!vis[t][i][v])
            {
                vis[t][i][v] =1;
                cnt++;
            }
            if(vis[t^1][i][v] && vis[t^1][i][v]<2)
                tmp++ , vis[t^1][i][v]++;
        }
        ret *= cnt,subt *= tmp;
    }
    return ret-subt;
}
int main()
{
    //freopen("input.txt","r",stdin);
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=100;i++)
        pos[i] = i;
    pos[0] = n;
    int flock[3],mlock[3];
    scanf("%d%d%d%d%d%d",&flock[0],&flock[1],&flock[2],&mlock[0],&mlock[1],&mlock[2]);

    printf("%d\n",comb1(flock)+comb1(mlock));
    return 0;
}



