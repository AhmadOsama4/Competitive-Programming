#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, ans , p;
    while(scanf("%d", &n), n)
    {
        ans = 1;
        for(int i=2;i*i<=n;i++){
            if(n % i)
                continue;
            p = 1;
            while(n % i == 0){
                p *= i;
                n /= i;
            }
            ans *= (p - p/i);
        }
        if(n != 1)
            ans *= (n - 1);
        printf("%d\n", ans);
    }
    return 0;
}
