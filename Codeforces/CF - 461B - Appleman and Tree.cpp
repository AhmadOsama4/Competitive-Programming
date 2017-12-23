#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

const int mod = 1e9 + 7;
const int N = 100001;

vector <int> adj[N];
int dp[N][2], col[N];

int power(int b, int p)
{
    if(!p)
        return 1;
    if(p == 1)
        return b;

    int r = power(b, p >> 1);
    r = (1LL * r * r) % mod;

    if(p & 1)
        r = (1LL * r * b) %mod;

    return r;
}
int solve(int node, bool f, int par)
{
    if(dp[node][f] != -1)
        return dp[node][f];

    int ret = 0;
    if(col[node] == 1){
        ret = 1;
        for(int child : adj[node]){
            if(child == par)
                continue;
            ret = (1LL * ret * solve(child, 0, node)) % mod;
        }
    }
    else{
        vector <int> V(sz(adj[node]), 1);
        int tmp = 1;
        for(int i = 0; i < sz(adj[node]); i++){
            int child = adj[node][i];
            if(child == par)
                continue;
            int x = solve(child, 0, node);
            V[i] = x;
            tmp = (1LL * tmp * x) % mod;
        }
        ret = 0;

        for(int i = 0; i < sz(adj[node]); i++){
            int child = adj[node][i];
            if(child == par)
                continue;
            int mul = (1LL * tmp * power(V[i], mod - 2)) % mod;

            int cur = (1LL * mul * solve(child, 1, node)) % mod;
            ret = (ret + cur) % mod;
        }
        if(!f)
            ret += tmp;
        ret %= mod;
    }
    return dp[node][f] = ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int n, x;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d", &x);
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", col + i);

    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 1, -1));
    return 0;
}
