#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

vector <int> adj[1005];
bool blocked[1005];
int dist[1005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, m, a, b;
    scanf("%d", &tc);
    while(tc--){
        memset(blocked, 0, sizeof blocked);
        memset(adj, 0, sizeof adj);
        memset(dist, -1, sizeof dist);

        scanf("%d%d", &n, &m);
        for(int i = 1; i < n; i++){
            scanf("%d", &a);
            blocked[i] = a;
        }
        while(m--){
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dist[0] = 0;
        queue <int> q;
        q.push(0);

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i = 0; i < sz(adj[cur]); i++){
                int child = adj[cur][i];
                if(blocked[child] || dist[child] != -1)
                    continue;
                q.push(child);
                dist[child] = dist[cur] + 1;
            }
        }
        for(int i = 1; i < n; i++){
            printf("%d", dist[i]);
            if(i != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
