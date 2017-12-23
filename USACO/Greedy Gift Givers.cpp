/*
ID: ao.fara1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <stdlib.h>
using namespace std;

string all[10];
map <string ,int> x;

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        x[s] = 0;
        all[i] = s;
    }

    for(int i=0;i<n;i++)
    {
        string s;
        int val,num,dis;
        cin>>s;
        scanf("%d%d",&val,&num);
        if(num==0)
            continue;
        dis = val/num;

        for(int j=0;j<num;j++)
        {
            string u;
            cin>>u;
            x[u] += dis;
        }
        x[s] -= dis*num;
    }

    for(int i=0;i<n;i++)
    {
        cout<<all[i]<<" "<<x[ all[i] ]<<endl;
    }

    return 0;
}
