#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int AdjMat[255][255];
int to_dest[255];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, m, c, k, a, b, cost;

    while(cin >> n >> m >> c >> k, n)
    {
        memset(to_dest, 0, sizeof to_dest);

        for(int i = 0;i < n; i++)
            for(int j = 0; j < n; j++)
                AdjMat[i][j] = 1e5;

        for(int i = 0; i < m; i++){
            cin >> a >> b >> cost;
            AdjMat[a][b] = AdjMat[b][a] = cost;
        }
        for(int i = c - 2; i >= 0; i--)
            to_dest[i] = to_dest[i + 1] + AdjMat[i][i + 1];

        for(int i = 0; i < c; i++)
            for(int j = 0; j < c; j++)
                AdjMat[i][j] = 1e5;

        for(int kk = 0; kk < n; kk++){
            for(int  i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(kk < c)
                        continue;
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][kk] + AdjMat[kk][j]);

                }
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i < c; i++)
            ans = min(ans, AdjMat[k][i] + to_dest[i]);

        cout << ans << endl;
    }
    return 0;
}
