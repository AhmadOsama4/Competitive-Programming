#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const int N = 50005;

vector <int> adj[N], adjList[N];
int comp[N], cost[N], lowlink[N], dfsnum[N], value[N];
int idx, dfsn, dp[N];
bool inStack[N];
vector < pair <int,int> > V;
stack <int> S;

void tarjan(int node)
{
    dfsnum[node] = lowlink[node] = dfsn++;
    inStack[node] = 1;
    S.push(node);

    for(int i = 0; i < sz(adj[node]); i++){
        int child = adj[node][i];
        if(dfsnum[child] == -1){
            tarjan(child);
            lowlink[node] = min(lowlink[node], lowlink[child]);
        }
        else if(inStack[child])
            lowlink[node] = min(lowlink[node], dfsnum[child]);
    }
    if(lowlink[node] == dfsnum[node]){
        int x = -1;
        while(!S.empty() && x != node){
            x = S.top();
            S.pop();
            value[idx] += cost[x];
            comp[x] = idx;
            inStack[x] = 0;
        }
        idx++;
    }
}

int solve(int node)
{
    if(dp[node] != -1)
        return dp[node];
    int ret = 0;
    for(int i = 0; i < sz(adjList[node]); i++){
        int child = adjList[node][i];
        ret = max(ret, solve(child));
    }
    return dp[node] = ret + value[node];
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, m, a, b, test = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", cost + i, &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &a);
                adj[i].push_back(a);
                V.push_back(make_pair(i, a));
            }
        }
        memset(value, 0, sizeof value);
        memset(dfsnum, -1, sizeof dfsnum);
        memset(lowlink, -1, sizeof lowlink);
        dfsn = idx = 0;

        for(int i = 0; i < n; i++)
            if(lowlink[i] == -1)
                tarjan(i);

        for(int i = 0; i < sz(V); i++){
            a = V[i].first, b = V[i].second;
            if(comp[a] == comp[b])
                continue;
            adjList[comp[a]].push_back(comp[b]);
        }

        int ans = 0;

        memset(dp, -1, sizeof dp);
        for(int i = 0; i < idx; i++)
            ans = max(ans, solve(i));

        printf("Case %d: %d\n",test++, ans);

        V.clear();
        memset(adj, 0, sizeof adj);
        memset(adjList, 0, sizeof adjList);
    }
    return 0;
}
