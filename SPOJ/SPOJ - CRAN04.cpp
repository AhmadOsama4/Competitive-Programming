#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

long long First[1000005], prv[1000005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, k, cur, p;
    string s;
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k >> s;
        ll ans = 0, cnt = 0;

        if(k == 0){
            for(int i = 0; i < n; i++){
                if(s[i] == '0'){
                    cnt++;
                }
                else{
                    ans += cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }
            ans += cnt * (cnt + 1) / 2;
            cout << ans << endl;
            continue;
        }

        memset(First, -1, sizeof First);
        memset(prv, -1, sizeof prv);
        cur = 0;
        p = -1;

        for(int i = 0; i < n; i++){
            cur += (s[i] == '1');
            if(First[cur] == -1)
                First[cur] = i;

            prv[i] = p;

            if(cur >= k)
                ans += First[cur - k + 1] - prv[First[cur - k + 1]];

            if(s[i] == '1')
                p = i;
        }
        cout << ans << endl;
    }
    return 0;
}

