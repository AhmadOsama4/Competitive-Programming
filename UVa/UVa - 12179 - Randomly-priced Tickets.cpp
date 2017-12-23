#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int lim, r, d, c;
int adj[105][105];
bool vis[101][3001];
double dp[101][3001];

double solve(int i, int val)
{
    if(val > c)
        return 0;
    if(i == d)
        return val <= c;
    if(vis[i][val])
        return dp[i][val];
    vis[i][val] = 1;

    double ret = 0;

    for(int j = 1;j <= r; j++){
        ret += (1.0/r) * solve(i + 1, val + j);
    }

    return dp[i][val] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, q, a, b;
    cin >> tc;
    for(int test = 1; test <= tc; test++)
    {
        printf("Case %d\n", test);
        cin >> n >> r;
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = 1e6;

        string s;
        for(int i=0; i < n; i++){
            cin >> s;
            for(int j=0; j < n; j++){
                if(s[j] == 'Y'){
                    adj[i + 1][j + 1] = adj[j + 1][i + 1] = 1;
                }
            }
        }

        for(int k = 1;k <= n; k++)
            for(int i = 1;i <= n; i++)
                for(int j = 1; j <= n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        cin >> q;
        while(q--){
            cin >> a >> b >> c;
            d = adj[a][b];
            c = min(c, d * r);
            memset(vis, 0, sizeof vis);
            double ans = solve(0, 0);
            printf("%.6f\n", ans);
        }
        if(test != tc)
            printf("\n");
    }
    return 0;
}
