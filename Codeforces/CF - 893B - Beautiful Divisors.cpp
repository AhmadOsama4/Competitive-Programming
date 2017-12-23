#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

bool check(int n)
{
    int len;
    for(int i = 0; i < 20; i++)
        if(n & (1 << i))
            len = i + 1;
    if(len % 2 == 0)
        return 0;
    for(int i = 0; i < len / 2; i++)
        if(n & (1 << i))
            return 0;
    for(int i = len / 2; i < len; i++){
        if(n & (1 << i))
            continue;
        return 0;
    }

    return 1;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int n, ans;
    cin >> n;
    for(int i = 1;i <= n; i++){
        if(n % i)
            continue;
        if(check(i))
            ans = i;
    }
    cout << ans << endl;

    return 0;
}
