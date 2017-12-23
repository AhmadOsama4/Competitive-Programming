#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

long long dp[1 << 18];
int n;
vector <int> adj[18];

long long solve(int mask)
{
    if(__builtin_popcount(mask) == n + 1)
        return 1;
    if(dp[mask] != -1)
        return dp[mask];

    long long ret = 0;

    set <int> children;

    for(int i = 0;i <= n; i++){
        if((mask & (1 << i)) == 0)
            continue;

        for(int child : adj[i]){
            if(mask & (1 << child))
                continue;
            children.insert(child);
        }
    }

    for(int child : children)
        ret += solve(mask | (1 << child));

    return dp[mask] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    int tc;
    string s;
    cin >> tc;
    for(int test = 1; test <= tc; test++)
    {
        cin >> n;
        for(int i = 0;i <= n;i++){
            cin >> s;
            for(int j = 0;j < n; j++)
                if(s[j] == '1')
                    adj[i].push_back(j + 1);
        }
        memset(dp, -1, sizeof dp);
        long long ans = solve(1);

        cout << "Case " << test << ": " << ans << endl;

        for(int i = 0;i <= n; i++)
            adj[i].clear();
    }
    return 0;
}
