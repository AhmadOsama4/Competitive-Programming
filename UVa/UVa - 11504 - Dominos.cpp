#include <bits/stdc++.h>
using namespace std;

#define sz(v)       ((int)v.size())
#define all(v)      (v.begin()),(v.end())
#define rall(v)     (v.rbegin()),(v.rend())
#define ll          long long

const int MAXN = 100001;

vector <int> adj[MAXN];
bool instack[MAXN], vis[MAXN], counted[MAXN];
int dfsn, cnt;
stack <int> stck;
int lowLink[MAXN], dfsnum[MAXN], par[MAXN];

void tarjan(int node)
{
    dfsnum[node] = lowLink[node] = dfsn++;
    instack[node] = 1;
    stck.push(node);
    for(int i=0;i<sz(adj[node]);i++){
        int child = adj[node][i];
        if(dfsnum[child] == -1){
            tarjan(child);
            lowLink[node] = min(lowLink[node], lowLink[child]);
        }
        else if(instack[child])
            lowLink[node] = min(lowLink[node], dfsnum[child]);
    }
    if(lowLink[node] == dfsnum[node]){
        int x = -1;
        cnt++;
        while(!stck.empty() && x != node){
            x = stck.top(); stck.pop();
            par[x] = node;
            instack[x] = 0;
        }
    }
}

void dfs(int node)
{
    vis[node] = 1;
    for(int i=0;i<sz(adj[node]);i++){
        int child = adj[node][i];
        
        if(!counted[par[child]] && (par[node] != par[child])){
            cnt--;
            counted[par[child]] = 1;
        }
        if(!vis[child])
            dfs(child);
    }
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, n , m, a, b;
    cin >> tc;
    while(tc--){
        memset(adj,0,sizeof(adj));
        memset(lowLink, 0, sizeof(lowLink));
        memset(dfsnum, -1, sizeof(dfsnum));
        memset(par, 0, sizeof(par));
        memset(vis, 0, sizeof(vis));
        memset(counted, 0, sizeof(counted));

        scanf("%d %d",&n,&m);
        dfsn = 1;
        cnt = 0;
        while(m--){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(dfsnum[i] == -1){
                tarjan(i);
            }
        }
        
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(i);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
