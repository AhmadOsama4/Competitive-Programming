/*
ID: ao.fara1
LANG: C++
TASK: wormhole
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

const int M = 13;
int n,x[M],y[M],right_after[M],cycles[M];
vector < pair <int,int> > prob[M];

bool cycle_exists(void)
{
    for(int s=1;s<=n;s++)
    {
        int u=0,pos=s;
        while(u<=n)
        {
            pos = right_after[cycles[pos]];
            if(pos==0)
                break;
            u++;
        }
        if(u > n)
            return true;
    }
    return false;
}

int solve(int indx)
{
    if(indx > n-1)
    {
        if(cycle_exists())
            return 1;
        return 0;
    }
    int ret=0,f=1;
    for(int i=0,lim=prob[indx].size();i<lim;i++)
    {
        int f2=1,a = prob[indx][i].first, b = prob[indx][i].second ;
        if(!cycles[a] && !cycles[b])
            {
                cycles[a] = b , cycles[b] = a;
                ret += solve(indx+1);
                f=0;
                f2=0;
            }
            if(!f2)
                cycles[a] = cycles[b] = 0;
    }
    if(f)
        ret += solve(indx+1);
    return ret;
}

int main()
{
    //freopen("input.txt","r",stdin);
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        x[i]=a;
        y[i]=b;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if( (y[i]==y[j]) && (x[i]<x[j]) && (x[j]<x[right_after[i]] || right_after[i]==0))
                right_after[i] = j;
        }
    }
  
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            prob[i].push_back(make_pair(i,j));

    
    cout<<solve(1)<<endl;
    return 0;
}



