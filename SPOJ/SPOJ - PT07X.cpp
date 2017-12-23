#include <bits/stdc++.h>
    using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

vector <int> adj[100005];

int dp[2][100005];

int solve(int node, int par, int prv)
{
    if(sz(adj[node]) == 1 && par != -1)
        return (prv == 0);

    if(dp[prv][node] != -1)
        return dp[prv][node];

    int r1 = 1, r2 = (1<<30);

    for(int child : adj[node]){ // cur = 1
        if(child == par)
            continue;
        r1 += solve(child, node, 1);
    }
    if(prv == 1){
        r2 = 0;
        for(int child : adj[node]){ // cur = 0;
            if(child == par)
                continue;
            r2 += solve(child, node, 0);
        }
    }

    return dp[prv][node] = min(r1, r2);
}

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n == 1){
        puts("1");
        return 0;
    }
    SetTo(dp, -1);
    printf("%d\n", solve(1, -1, 1));

    return 0;
}
