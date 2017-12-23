#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

vector <int> adj[10005];
int col[10005];

int dfs(int node, int par, int c)
{
    int ret = (c != col[node]);
    for(int child : adj[node]){
        if(child == par)
            continue;
        ret += dfs(child, node, col[node]);
    }

    return ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int n, a, b;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        scanf("%d", &a);
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", col + i);

    printf("%d\n", dfs(1, 0, -1));
    return 0;
}
