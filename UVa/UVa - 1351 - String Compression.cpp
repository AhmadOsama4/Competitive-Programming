#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int dp[205][205], val[500];
string s;

int solve(int L, int R)
{
    if(L > R)
        return 0;
    if(L == R)
        return 1;
    if(dp[L][R] != -1)
        return dp[L][R];

    int len = (R - L + 1);
    int ret = len;

    for(int i = 1; i < len; i++){
        if(len % i)
            continue;
        string tmp = s.substr(L, i), cur = "";
        while(sz(cur) < len)
            cur += tmp;

        if(cur.compare(s.substr(L, len)) == 0)
            ret = min(ret, 2 + val[len / i] + solve(L, L + i - 1));
    }

    for(int i = L; i < R; i++)
        ret = min(ret, solve(L, i) + solve(i + 1, R));

    return dp[L][R] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int i = 0; i < 10; i++)
        val[i] = 1;
    for(int i = 10; i < 100; i++)
        val[i] = 2;
    for(int i = 100; i < 300; i++)
        val[i] = 3;
    while(tc--)
    {
        cin >> s;
        memset(dp, -1, sizeof dp);
        cout << solve(0, sz(s) - 1) << endl;
    }
    return 0;
}
