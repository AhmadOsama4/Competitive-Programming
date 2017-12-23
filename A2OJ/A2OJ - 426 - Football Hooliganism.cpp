#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

string grid[10005];
int n, dp[10005][3];

int solve(int i, int state)
{
    if(i == n - 1){
        if(state == 0)
            return 2 * (grid[i][0] != grid[i][1]);
        else{
            int r = (grid[i][0] != grid[i-1][0]) + (grid[i][1] != grid[i-1][1]);
            //if(state == 1)
                //r *= 2;
            return r;
        }
    }
    if(dp[i][state] != -1)
        return dp[i][state];

    int tmp ,ret;

    if(state){
        tmp = (grid[i][0] != grid[i-1][0]) + (grid[i][1] != grid[i-1][1]);
        //if(state == 1)
            //tmp *= 2;
        ret = tmp + solve(i + 1, 0);

        tmp = (grid[i][0] != grid[i-1][0] && grid[i][0] != grid[i+1][0]);
        tmp += (grid[i][1] != grid[i-1][1] && grid[i][1] != grid[i+1][1]);

        ret = min(ret, tmp + solve(i + 1, 1));
    }
    else if(!state){
        tmp = 2 * (grid[i][0] != grid[i][1]);
        ret = tmp + solve(i + 1, 0);

        tmp = (grid[i][0] != grid[i+1][0]) + (grid[i][1] != grid[i+1][1]);
        ret = min(ret, tmp + solve(i + 1, 1));
    }

    //printf("%d %d %d\n", i, state, ret);
    return dp[i][state] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(int i=0; i < n; i++)
            cin >> grid[i];

        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << endl;
    }
    return 0;
}
