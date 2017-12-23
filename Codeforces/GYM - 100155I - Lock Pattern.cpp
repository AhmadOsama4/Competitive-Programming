#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const double eps = 1e-8;

vector <int> adj[15][15];
int mp[6][6], x[15], y[15], dist[15][15];
bool vis[15];

int dp[12][101][5000];

int solve(int cur, int L, int mask)
{
    if(L == 0)
        return 1;
    if(L < 0)
        return 0;
    if(dp[cur][L][mask] != -1)
        return dp[cur][L][mask];

    int ret = 0;

    for(int i = 0; i < 12; i++){
        if(vis[i])
            continue;
        if(mask & (1 << i))
            continue;

        bool ok = true;
        for(int tmp : adj[cur][i]){
            bool f = mask & (1 << tmp);
            if(!f)
                ok = false;
        }
        if(ok)
            ret += solve(i, L - dist[cur][i], mask | (1 << i));
    }

    return dp[cur][L][mask] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int L, n, a, b, idx = 0;

    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 3; j++){
            mp[j][i] = idx;
            x[idx] = j;
            y[idx] = i;
            idx++;
        }
    }
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(i == j)
                continue;
            double d = sqrt( (x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]));
            for(int k = 0; k < 12; k++){
                if(k == i || k == j)
                    continue;
                double d1 = sqrt( (x[k] - x[i])*(x[k] - x[i]) + (y[k] - y[i])*(y[k] - y[i]));
                double d2 = sqrt( (x[k] - x[j])*(x[k] - x[j]) + (y[k] - y[j])*(y[k] - y[j]));
                if(fabs(d - (d1 + d2)) <= eps){
                    adj[i][j].push_back(k);
                }
            }
            dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }

    scanf("%d%d", &L, &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        vis[mp[a][b]] = 1;
    }

    if(L > 60){
        puts("BAD MEMORY");
        return 0;
    }

    int ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 12; i++)
        if(!vis[i])
            ans += solve(i, L, (1 << i));

    if(ans == 0)
        puts("BAD MEMORY");
    else
        printf("%d\n", ans);
    return 0;
}
