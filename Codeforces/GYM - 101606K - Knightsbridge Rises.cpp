#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

struct edge{
    int to, cap, flow, rev;
    edge(int _to, int _cap, int _flow, int _rev){
        to = _to, cap = _cap, flow = _flow, rev = _rev;
    }
};

vector <int> res[105];
vector <int> tmp;
int n, m;

struct Dinic{
    vector <edge> adj[305];
    int level[305], start[305];
    int sink, src;

    Dinic(int s, int t){
        src = s;
        sink = t;
        memset(start, 0, sizeof(start));
    }

    void addEdge(int from, int to, int cap1, int cap2)
    {
        // from -> to has cap1
        // to -> from has cap2
        edge e1 = edge(to, cap1, 0, adj[to].size() );
        edge e2 = edge(from, cap2, 0, adj[from].size() );

        adj[from].push_back(e1);
        adj[to].push_back(e2);
    }
    bool bfs()
    {
        memset(level, -1, sizeof(level));
        level[src] = 0;
        queue <int> q;
        q.push(src);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(edge &e : adj[cur]){
                if(level[e.to] == -1 && e.flow < e.cap){
                    level[e.to] = level[cur] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }

    int sendFlow(int u, int flow)
    {
        if(u == sink)
            return flow;

        for( ;start[u] < sz(adj[u]);start[u]++){
            edge &e = adj[u][start[u]];

            if(level[e.to] == level[u] + 1 && e.flow < e.cap){
                int curflow = min(flow, e.cap - e.flow);

                curflow = sendFlow(e.to, curflow);

                if(curflow > 0){
                    e.flow += curflow;
                    adj[e.to][e.rev].flow -= curflow;
                    return curflow;
                }
            }
        }
        return 0;
    }

    int maxFlow()
    {
        if(src == sink)
            return 0;

        int totalflow = 0;

        while(bfs()){
            memset(start, 0, sizeof(start));
            int flow;
            while( (flow = sendFlow(src, INT_MAX)))
                totalflow += flow;
        }
        return totalflow;
    }
    bool vis[305], done[305];
    bool dfs(int node)
    {
        if(node >= n && node < n + m){
            res[node - n] = tmp;
            return true;
        }
        /*if(node < n)
            cout << node+1 << endl;*/
        vis[node] = 1;
        if(node < n)
            tmp.push_back(node + 1);
        for(edge &e : adj[node]){
            if(e.flow != 1 || vis[e.to] || done[e.to])
                continue;
            bool f = dfs(e.to);
            if(f){
                if(node < n)
                    done[node] = 1;
                return true;
            }
        }
        if(node < n)
            tmp.pop_back();
        return false;
    }
};

const int N = 105;

int W[N], L[N], T[N];

int main ()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d", W + i, L + i);

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
        scanf("%d", T + i);

    int source = n + m + 1, sink = source + 1;
    int idx = sink + 1;
    Dinic dinic(source, sink);

    for(int i = 0; i < n; i++) // vertex splitting for cranes
        dinic.addEdge(idx + i, i, 1, 0);
    for(int i = 0; i < m; i++) // vertex splitting for towers
        dinic.addEdge(idx + n + i, n + i, 1, 0);

    for(int i = 0; i < n; i++) // edge from source to crane
        if(W[i] == 0)
            dinic.addEdge(source, idx + i , 1, 0);

    for(int i = 0; i < m; i++) // edge from tower to sink
        dinic.addEdge(n + i, sink, 1, 0);

    for(int i = 0; i < n; i++){ // edges between cranes
        for(int j = 0; j < n; j++){
            if(i != j && L[i] >= W[j]){
                dinic.addEdge(i, idx + j , 1, 0);
            }
        }
    }
    for(int i = 0; i < n; i++){// edge between crane and tower
        for(int j = 0; j < m; j++){
            if(L[i] >= T[j]){
                dinic.addEdge(i, idx + n + j , 1, 0);
            }
        }
    }

    int ans = dinic.maxFlow();
    if(ans != m){
        puts("impossible");
        return 0;
    }

    memset(dinic.done, 0, sizeof (dinic.done));
    for(int i = 0; i < n; i++){
        memset(dinic.vis, 0, sizeof (dinic.vis));
        tmp.clear();
        dinic.dfs(source);
    }

    for(int i = 0; i < m; i++){
        for(int x : res[i])
            printf("%d ", x);
        puts("");
    }
    return 0;
}
