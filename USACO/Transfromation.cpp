/*
ID: ao.fara1
LANG: C++
TASK: transform
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

char s1[10][10],s2[10][10];

void rot90(char grid[10][10],int num,int x,int y)
{
    if(num<=1)
        return;
    char cop[10][10];

    for(int j=y;j<num;j++)
        {
            cop[j][num-1] = grid[x][j];
            cop[j][y] = grid[num-1][j];
            //////////////////////////////////
            cop[num-1][num-1-j+x] = grid[j][num-1];
            cop[x][j] = grid[num-1-j+x][y];
        }
    rot90(grid,num-1,x+1,y+1);
        for(int i=x;i<num;i++)
        {
            grid[x][i] = cop[x][i];
            grid[num-1][i] = cop[num-1][i];
            grid[i][y] = cop[i][y];
            grid[i][num-1] = cop[i][num-1];
        }
}

bool same(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(s1[i][j] != s2[i][j])
                return false;
        }
    return true;
}

void reflect(char grid[10][10],int n)
{
    int lim = n/2;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<lim;j++)
            swap(grid[i][j],grid[i][n-1-j]);
    }
}


int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%s",&s1[i]);
    for(int i=0;i<n;i++)
        scanf("%s",&s2[i]);

    rot90(s1,n,0,0);
    if(same(n)) // same after 90 rot
        {
            printf("1\n");
            return 0;
        }

    rot90(s1,n,0,0);
    if(same(n)) // same after 180 rot
        {
            printf("2\n");
            return 0;
        }

    rot90(s1,n,0,0);
    if(same(n)) // same after 270 rot
        {
            printf("3\n");
            return 0;
        }

    rot90(s1,n,0,0);

    reflect(s1,n);
    if(same(n)) // same after 270 rot
        {
            printf("4\n");
            return 0;
        }

    rot90(s1,n,0,0);
    if(same(n)) // same after  reflection + 90 rot
        {
            printf("5\n");
            return 0;
        }

    rot90(s1,n,0,0);
    if(same(n)) // same after  reflection + 180 rot
        {
            printf("5\n");
            return 0;
        }

    rot90(s1,n,0,0);
    if(same(n)) // same after  reflection + 270 rot
        {
            printf("5\n");
            return 0;
        }

    rot90(s1,n,0,0);
    reflect(s1,n);
    if(same(n)) // both are the same
        {
            printf("6\n");
                return 0;
        }

    printf("7\n");
    return 0;
}



