#include <bits/stdc++.h>
    using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

int color[55];
ll flow[51][51];
int path[55];
int pathlen, n;
bool vis[55], connected[51][51];

int get_path(int cur, int tr, int len, int mn)
{
    path[len] = cur;
    vis[cur] = 1;
    if(cur == tr){
        pathlen = len + 1;
        return mn;
    }
    int ret = 0;
    for(int i=0;i<n;i++){
        if(vis[i] || flow[cur][i] <=0)
            continue;
        ret = get_path(i, tr, len + 1, min(mn, (int)flow[cur][i]));
        if(ret > 0)
            return ret;
    }
    return ret;
}

ll maxFlow(int src, int sink)
{
    ll r, total = 0;
    while(true)
    {
        SetTo(vis,0);
        r = get_path(src, sink, 0, (1<<30) );
        if(!r)
            break;
        for(int i=1;i<pathlen;i++){
            int a = path[i-1], b = path[i];
            //printf("%d %d\n",a+1,b+1);
            flow[a][b] -= r;
            flow[b][a] += r;
        }
        total += r;
    }
    return total;
}

void dfs(int node)
{
    color[node] = 1;
    vis[node] = 1;

    for(int i=0;i<n;i++){
        if(vis[i] || flow[node][i] <= 0)
            continue;
        dfs(i);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, a, b, c;
    while(scanf("%d %d",&n,&m), n && m)
    {
        SetTo(connected, 0);
        SetTo(color, 0);
        SetTo(flow, 0);
        vector <pair<int,int>> arr;

        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            a--, b-- ;
            if(connected[a][b] || connected[b][a])
                continue;
            arr.push_back({a,b});
            flow[a][b] += c;
            flow[b][a] += c;
            connected[a][b] = connected[b][a] = 1;
        }
        maxFlow(0,1);
        SetTo(vis, 0);
        dfs(0);
        for(int i=0;i<sz(arr);i++){
            a = arr[i].first, b = arr[i].second;
            if(color[a] && !color[b])
                printf("%d %d\n",a + 1,b + 1);
            else if(color[b] && !color[a])
                printf("%d %d\n",b + 1,a + 1);
        }
        puts("");
    }
    return 0;
}
