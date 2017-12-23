#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const int N = 1005;
const int inf = 1e6;

vector <int> adj[N];
bool vis[N][4], marked[N], f[N];
pair <int,int> dp[N][4];

pair <int,int> solve(int node, int par, short prv)
{
    marked[node] = 1;
    if(sz(adj[node]) == 0)
        return make_pair(0, 0);
    if(par != -1 && sz(adj[node]) == 1){
        if(prv == 1)
            return make_pair(0, 0);
        return make_pair(1, 0);
    }
    if(vis[node][prv])
        return dp[node][prv];
    vis[node][prv] = 1;

    // take
    pair <int,int> ret, p(1, prv && par != -1), r;
    for(int child : adj[node]){
        if(child == par)
            continue;
        r = solve(child, node, 1);
        p.first += r.first;
        p.second += r.second;
    }
    ret = p;
    //leave;
    if(prv){
        p = {0, 0};
        for(int child : adj[node]){
            if(child == par)
                continue;
            r = solve(child, node, 0);
            p.first += r.first;
            p.second += r.second;
        }
    }
    if(p.first < ret.first)
        ret = p;
    if(p.first == ret.first && p.second > ret.second)
        ret = p;

    return dp[node][prv] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    int tc, n, m, a, b, x, y, z;
    scanf("%d", &tc);
    while(tc--)
    {
        memset(vis, 0, sizeof vis);
        memset(marked, 0, sizeof marked);
        memset(adj, 0, sizeof adj);
        memset(f, 0, sizeof f);
        x = 0, y = 0, z = 0;

        scanf("%d%d", &n, &m);
        for(int i=0;i<m;i++){
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            f[a] = f[b] = 1;
        }

        for(int i=0;i<n;i++){
             if(marked[i] || !f[i])
                continue;
             pair <int,int> p = solve(i, -1, 1);
             x += p.first, y += p.second;
        }

        printf("%d %d %d\n", x, y, m - y);
    }
    return 0;
}
