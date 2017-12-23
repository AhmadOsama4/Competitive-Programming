#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const int N = 100005;
const int inf = 1e9;
vector <int> adj[N];
pair <int,int> tree_min[4 * N], tree_max[4 * N];
int arr[N];
bool vis[N];

void build(int node, int L, int R)
{
    if(L == R){
        tree_min[node] = make_pair(-arr[L], L);
        tree_max[node] = make_pair(arr[L], L);
        return;
    }
    int mid = (L + R) >> 1;

    build(2*node, L, mid);
    build(2*node + 1, mid + 1, R);

    tree_min[node] = min(tree_min[2*node], tree_min[2*node + 1]);
    tree_max[node] = max(tree_max[2*node], tree_max[2*node + 1]);
}

void update(int node, int L, int R, int i, int min_v, int max_v)
{
    if(L > i || R < i)
        return;
    if(L == R){
        tree_min[node].first = min_v;
        tree_max[node].first = max_v;
        return;
    }
    int mid = (L + R) >> 1;

    update(2*node, L, mid, i, min_v, max_v);
    update(2*node+1, mid + 1, R, i, min_v, max_v);

    tree_min[node] = min(tree_min[2*node], tree_min[2*node + 1]);
    tree_max[node] = max(tree_max[2*node], tree_max[2*node + 1]);
}

pair <int,int> query_max(int node, int L, int R, int a, int b)
{
    if(R < a || L > b)
        return make_pair(-inf, -inf);
    if(L >= a && R <= b)
        return tree_max[node];

    pair <int,int> p1, p2;
    int mid = (L + R) >> 1;

    p1 = query_max(2*node, L, mid, a, b);
    p2 = query_max(2*node + 1, mid + 1, R, a, b);

    return max(p1, p2);
}

pair <int,int> query_min(int node, int L, int R, int a, int b)
{
    if(R < a || L > b)
        return make_pair(inf, inf);
    if(L >= a && R <= b)
        return tree_min[node];

    pair <int,int> p1, p2;
    int mid = (L + R) >> 1;

    p1 = query_min(2*node, L, mid, a, b);
    p2 = query_min(2*node + 1, mid + 1, R, a, b);

    return min(p1, p2);
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, q, tc, x;
    long long total;
    scanf("%d", &tc);

    while(tc--)
    {
        total = 0;
        memset(vis, 0, sizeof vis);
        memset(adj, 0, sizeof adj);
        scanf("%d%d", &n, &q);
        map <int,int> mapper;

        for(int i = 1; i <= n; i++){
            scanf("%d", arr + i);
            mapper[arr[i]] = 1;
        }
        int idx = 1;
        map <int,int>::iterator it;
        for(it = mapper.begin() ; it != mapper.end(); it++)
            mapper[it->first] = idx++;

        // map to small values
        for(int i = 1; i <= n; i++){
            arr[i] = mapper[arr[i]];
            adj[arr[i]].push_back(i);
        }

        arr[0] = arr[n + 1] = inf;

        build(1, 0, n + 1);

        total = 1LL * n * (n + 1) / 2;
        long long res;

        int cur;
        for(int qq = 0; qq < q; qq++){
            scanf("%d", &x);
            x = mapper[x];
            if(x == 0 || vis[x]){
                printf("0 %lld\n", total);
                continue;
            }
            vis[x] = 1;
            res = 0;
            int L, R;
            for(int i = 0; i < sz(adj[x]); i++){
                cur = adj[x][i];
                L = query_max(1, 0, n + 1, 0, cur - 1).second;
                R = query_min(1, 0, n + 1, cur + 1, n + 1).second;

                if(i < (sz(adj[x]) - 1) && adj[x][i + 1] < R)
                    R = adj[x][i + 1];

                res += 1LL * (R - cur) * (cur - L);
            }
            // update values
            for(int i = 0; i < sz(adj[x]); i++){
                int idx = adj[x][i];
                update(1, 0, n + 1, idx, -inf, inf);
            }

            total -= res;
            printf("%lld %lld\n", res, total);
        }

    }
    return 0;
}
