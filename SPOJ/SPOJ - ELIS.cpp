#include <bits/stdc++h>
using namespace std;

int dp[15] , x[15];

int main ()
{
    //freopen("input.txt","r",stdin);
    int n,ans=0,temp=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        dp[i]=1;
        temp = 0;
        for(int j=i-1;j>=0;j--){
            if(x[j] < x[i]){
                temp = max(temp,dp[j]);
            }
        }
        dp[i] += temp;
        ans = max(ans,dp[i]);
    }
    cout <<  ans << endl;
    return 0;
}
