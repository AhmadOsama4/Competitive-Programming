#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

const int N = 101;

int n;
int x[N], y[N], rowAssign[N], colAssign[N];
bool AdjMat[N][N];
bool type[N], vis[N];

bool canMatch(int i)
{
    for(int j = 0; j < n; j++){
        if(!AdjMat[i][j] || vis[j])
            continue;
        vis[j] = 1;
        if(colAssign[j] == -1 || canMatch(colAssign[j])){
            rowAssign[i] = j;
            colAssign[j] = i;
            return 1;
        }
    }
    return 0;
}
int maxMatching(int d)
{
    memset(AdjMat, 0, sizeof AdjMat);
    int ret = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(type[i] == type[j])
                continue;

            int dist = (x[i] - x[j]) * (x[i] - x[j]) +
                       (y[i] - y[j]) * (y[i] - y[j]);

            if(dist <= d * d)
                AdjMat[i][j] = AdjMat[j][i] = 1;
        }
    }
    memset(colAssign, -1, sizeof colAssign);
    memset(rowAssign, -1, sizeof rowAssign);

    for(int i = 0; i < n; i++){
        if(type[i])
            continue;
        memset(vis, 0, sizeof vis);
        if(canMatch(i))
            ret++;
    }

    return ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, k;
    cin >> tc;
    string s;

    while(tc--)
    {
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> s;
            if(s == "blue")
                type[i] = 0;
            else
                type[i] = 1;
        }
        int ans = -1, L = 1, R = 1e4;

        while(L <= R){
            int mid = (L + R) >> 1;
            if(maxMatching(mid) >= k){
                ans = mid;
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        if(ans != -1)
            cout << ans << endl;
        else
            cout << "Impossible\n";
    }
    return 0;
}
