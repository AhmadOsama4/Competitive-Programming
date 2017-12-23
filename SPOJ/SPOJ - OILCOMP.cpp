#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int n, m;
int grid[21][21];

int main ()
{
    //freopen("input.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    int tc, test = 1, ans;
    scanf("%d", &tc);

    while(tc--){
        ans = 0;
        scanf("%d%d", &m, &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &grid[i][j]);

        vector <int> masks;
        for(int i = 0; i < (1 << m); i++){
            bool ok = 1;
            for(int j = 0; j < m; j++){
                bool f1 = i & (1 << j);
                bool f2 = i & (1 << (j + 1));
                if(f1 && f2){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                masks.push_back(i);
            }
        }
        vector < pair <int,int> > V[21];
        int tmp = 0;

        for(int i = 0; i < n; i++){
            for(int mask : masks){
                tmp = 0;
                for(int j = 0; j < m; j++){
                    if(mask & (1 << j))
                        tmp += grid[i][j];
                }
                ans = max(ans, tmp);
                if(!i){
                    V[i].push_back(make_pair(tmp, mask));
                    continue;
                }
                for(int j = 0; j < sz(V[i-1]); j++){
                    if((V[i-1][j].second & mask) == 0){
                        tmp += V[i-1][j].first;
                        break;
                    }
                }
                ans = max(ans, tmp);
                V[i].push_back(make_pair(tmp, mask));
            }
            sort(rall(V[i]));
        }

        printf("Case %d: %d\n", test++, ans);
    }
    return 0;
}
