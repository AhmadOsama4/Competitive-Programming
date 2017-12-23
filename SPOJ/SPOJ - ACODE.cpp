#include <bits/stdc++.h>
using namespace std;

long long dp[5005];

int main ()
{
    //freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    while(s != "0"){
        memset(dp,0,sizeof(dp));
        int n = s.length();
        dp[n] = dp[n+1] = dp[n-1] =1;

        for(int i=n-2;i>=0;i--){
            dp[i] += dp[i+1];
            int a = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(a%10 && a>10 && a<27 && (i == n-2 || s[i+2] != '0')){
                dp[i] += dp[i+2];
            }
        }
        cout << dp[0] << endl;
        cin>>s;
    }
    return 0;
}
