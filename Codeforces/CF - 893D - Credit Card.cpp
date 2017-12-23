#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int arr[100005];
long long sum[100005];

int main ()
{
    //freopen("input.txt","r",stdin);
    int n, ans = 0;
    long long d;
    scanf("%d %lld", &n, &d);
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    sum[0] = arr[0];

    if(sum[0] > d){
        puts("-1");
        return 0;
    }

    long long cur = arr[0];

    for(int i = 1; i < n; i++){
        sum[i] = arr[i] + sum[i - 1];
        cur += arr[i];

        if(cur > d){
            puts("-1");
            return 0;
        }
        if(arr[i] == 0)
            cur = max(0LL, cur);
    }

    multiset <long long> S;

    for(int i = 0; i < n; i++){
        long long tmp = d - sum[i];
        S.insert(tmp);
    }
    cur = 0;

    for(int i = 0; i < n; i++){
        cur += arr[i];
        if(arr[i] == 0 && cur < 0){
            ans++;
            long long add = *S.begin();
            add = min(add, d - cur);
            cur += add;
        }
        long long tmp = d - sum[i];
        S.erase(S.find(tmp));
    }

    printf("%d\n", ans);
    return 0;
}
