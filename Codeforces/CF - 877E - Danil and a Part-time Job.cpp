#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const int N = 200005;

vector <int> adj[N];
int tour[4 * N], S[N], E[N], V[N];
int tree[10 * N];
bool lazy[10 * N];
int idx;

void dfs(int node, int par)
{
    S[node] = idx;
    tour[idx] = node;
    idx++;

    for(int child : adj[node]){
        if(child == par)
            continue;
        dfs(child, node);
    }
    E[node] = idx;
    tour[idx] = node;
    idx++;
}

void build(int node, int L, int R)
{
    if(L == R){
        int cur = tour[L];
        tree[node] = V[cur];
        return;
    }
    int mid = (L + R) >> 1;

    build(2*node, L, mid);
    build(2*node+1, mid + 1, R);

    tree[node] = tree[2*node] + tree[2*node+1];
}

inline void propagate(int node, int L, int R)
{
    if(!lazy[node])
        return;
    tree[node] = R - L + 1 - tree[node];
    if(L != R){
        lazy[2*node] ^= 1;
        lazy[2*node+1] ^= 1;
    }
    lazy[node] = 0;
}

void update(int node, int L, int R, int a, int b)
{
    propagate(node, L, R);
    if(R < a || L > b)
        return;
    if(L >= a && R <= b){
        tree[node] = R - L + 1 - tree[node];
        if(L != R){
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        lazy[node] = 0;
        return;
    }
    int mid = (L + R) >> 1;

    update(2*node, L, mid, a, b);
    update(2*node+1, mid + 1, R, a, b);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int L, int R, int a, int b)
{
    propagate(node, L, R);
    if(R < a || L > b)
        return 0;
    if(L >= a && R <= b)
        return tree[node];

    int mid = (L + R) >> 1;
    int q1 = query(2*node, L, mid, a, b);
    int q2 = query(2*node + 1, mid + 1, R, a, b);

    return q1 + q2;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, p, q, c;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        scanf("%d", &p);
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        scanf("%d", V + i);

    dfs(1, -1);

    build(1, 0, idx - 1);

    char s[10];
    scanf("%d", &q);
    int ans;
    while(q--){
        scanf("%s %d\n", s, &c);
        if(s[0] == 'g'){
            ans = query(1, 0, idx - 1, S[c], E[c]);
            ans /= 2;
            printf("%d\n", ans);
        }
        else{
            update(1, 0, idx - 1, S[c], E[c]);
        }
    }

    return 0;
}
