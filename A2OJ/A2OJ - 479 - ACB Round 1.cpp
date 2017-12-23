#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, m, scores[105];
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> scores[i];

        sort(scores, scores + n);
        reverse(scores, scores + n);

        int ans = 0;
        for(int i = 0; i < m; i++)
            if(scores[i] > 0)
                ans++;
        for(int i = m; i < n; i++)
            if(scores[i] > 0 && scores[i] == scores[m - 1])
                ans++;

        cout << ans << endl;
    }
    return 0;
}
