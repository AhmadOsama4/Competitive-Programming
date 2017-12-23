#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const double inf = 1e9;
bool vis[1005][1005];
double dp[1005][1005];
int n, m, arr[1005][2], cur[1005];
int cap[1005];

double solve(int i, int rem)
{
    if(!rem)
        return 0;
    if(i == n)
        return inf;
    if(cur[i] < rem)
        return inf;
    if(vis[i][rem])
        return dp[i][rem];
    vis[i][rem] = 1;

    double ret = solve(i + 1, rem);

    double tmp = arr[i][0];
    double cost = tmp;
    ret = min(ret, cost + solve(i + 1, rem - 1));

    for(int j=1;j<cap[i];j++){
    		if(j + 1 > rem)
        	break;
        tmp += 1.0 * (arr[i][1] - arr[i][0])/(cap[i]-1);
        cost += tmp;
        ret = min(ret, cost + solve(i + 1, rem - j - 1));
    }

    return dp[i][rem] = ret;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int k, sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&cap[i], &arr[i][0], &arr[i][1]);
        sum += cap[i];
        cur[i] = cap[i];
    }
    if(sum <= m){
        double ans = 0.0;
        for(int i=0;i<n;i++){
            double tmp = arr[i][0];
            ans += tmp;
            for(int j=1;j<cap[i];j++){
                tmp += 1.0 * (arr[i][1] - arr[i][0])/(cap[i]-1);
                ans += tmp;
            }
        }
        if(sum != m)
            printf("Maximum possible amount: %d\n", sum);
        printf("Minimum possible cost: %.2f\n", ans);
        return 0;
    }
    for(int i=n-1;i>=0;i--)
        cur[i] += cur[i + 1];


    printf("Minimum possible cost: %.2f\n", solve(0, m));


    return 0;
}
