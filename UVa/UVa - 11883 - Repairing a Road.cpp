#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int n, m;
double g[105][105], decrease[105][105], adj[105][105];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int a, b;
    double cost, d;
    while(scanf("%d%d", &n, &m), n && m)
    {
        vector <pair<int,int>> V;

        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = (i == j)? 0 : 1e6;

        for(int i=0;i < m; i++){
            cin >> a >> b >> cost >> d;
            adj[a][b] = g[a][b] = cost;
            decrease[a][b] = d;
            adj[b][a] = g[b][a] = cost;
            decrease[b][a] = d;

            V.push_back(make_pair(a, b));
        }
        for(int k = 1; k <= n; k++)
            for(int i = 1;i <= n; i++)
                for(int j = 1;j <= n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        double cur, p, tmp, ans = g[1][n];

        for(int i = 0;i < m; i++){
            a = V[i].first, b = V[i].second;
            if(g[1][a] > g[1][b])
                swap(a, b);

            tmp = g[1][a] + g[b][n];
            p = g[1][a];

            double valg, valh, L = 0, R = adj[a][b];

            for(int i = 0;i < 100; i++){
                double g = L + (R - L) / 3, h = R - (R - L) / 3;

                valg = g + adj[a][b] / pow(decrease[a][b], p + g);
                valh = h + adj[a][b] / pow(decrease[a][b], p + h);

                if(valg > valh)
                   L = g;
                else
                   R = h;
            }

            valg = R + adj[a][b] / pow(decrease[a][b], R + p);
            ans = min(ans, valg + tmp);
        }

        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
