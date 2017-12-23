#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))


struct edge{
    int to, cap, flow, rev;
    edge(int _to, int _cap, int _flow, int _rev){
        to = _to, cap = _cap, flow = _flow, rev = _rev;
    }
};

struct Dinic{
    vector <edge> adj[105];
    int level[105], start[105];
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

};


int main ()
{
    //freopen("input.txt","r",stdin);
    int n, m, s, t, a, b, c;
    int idx = 1;
    while(scanf("%d", &n), n)
    {
        scanf("%d%d%d", &s, &t, &m);
        Dinic dinic(s, t);
        while(m--){
            scanf("%d%d%d", &a, &b, &c);
            dinic.addEdge(a, b, c, c);
        }
        int ans = dinic.maxFlow();

        printf("Network %d\n", idx);
        printf("The bandwidth is %d.\n\n", ans);

        idx++;
    }
    return 0;
}
