/*
ID: ao.fara1
LANG: C++
TASK: milk3
*/

// Solution => Brute Force

#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

bool vis[21][21][21];
vector <int> res;

int A, B, C;

void dfs(int a, int b, int c)
{
    if(vis[a][b][c])
        return;
    vis[a][b][c] = 1;
    if(!a)
        res.push_back(c);

    dfs(a - min(a, B - b) , b + min(a, B - b) , c); // a into b
    dfs(a - min(a, C - c), b, c + min(a, C - c)); // a into c

    dfs(a + min(b, A - a), b - min(b, A - a), c); // b into a
    dfs(a, b - min(b, C - c), c + min(b, C - c)); // b into c

    dfs(a + min(c, A - a), b, c - min(c, A - a)); // c into a
    dfs(a, b + min(c, B - b), c - min(c, B - b)); // c into b
}
int main()
{
    //freopen("input.txt","r",stdin);
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    scanf("%d%d%d", &A, &B, &C);

    dfs(0, 0, C);

    sort(all(res));
    res.resize(unique(all(res)) - res.begin());

    for(int i = 0; i < sz(res); i++){
        printf("%d", res[i]);
        if(i != sz(res) - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
