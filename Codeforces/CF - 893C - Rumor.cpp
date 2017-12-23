#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

vector <int> adj[100005];
int cost[100005];
bool vis[100005];

int dfs(int node)
{
    int ret = cost[node];
    vis[node] = 1;

    for(int child : adj[node]){
        if(vis[child])
            continue;
        ret = min(ret, dfs(child));
    }
    return ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int n, m, a, b;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", cost + i);

    long long ans = 0;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(vis[i])
            continue;
        ans += dfs(i);
    }

    printf("%lld\n", ans);
    return 0;
}
