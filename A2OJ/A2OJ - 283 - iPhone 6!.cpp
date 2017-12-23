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


int main ()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        int me ,f,m,r;
        scanf("%d%d%d",&me,&f,&m);
        r = 6666 - me;

        if((m >=r) && (m<f || f<r))
            printf("Case %d: mom\n",k+1);
        else
            printf("Case %d: dad\n",k+1);
    }
    return 0;
}
