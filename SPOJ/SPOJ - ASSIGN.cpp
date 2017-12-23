#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int vis[20][1 << 20];
long long dp[20][1 << 20];
vector <int> pref[20];
int t, n;

long long solve(int i, int mask)
{
    if(i == n)
        return 1;
    if(vis[i][mask] == t)
        return dp[i][mask];
    vis[i][mask] = t;

    long long ret = 0;

    for(int x : pref[i]){
        if(mask & (1 << x))
            continue;
        ret += solve(i + 1, mask | (1 << x));
    }

    return dp[i][mask] = ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, x;
    scanf("%d", &tc);

    for(t = 1; t <= tc; t++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &x);
                if(x)
                    pref[i].push_back(j);
            }
        }
        printf("%lld\n", solve(0, 0));
        memset(pref, 0, sizeof pref);
    }

    return 0;
}
