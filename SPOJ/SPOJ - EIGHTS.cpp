#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt","r",stdin);
    int ans[] = {192, 442, 692, 942};
    int tc;
    long long k;
    scanf("%d", &tc);

    while(tc--){
        scanf("%lld", &k);
        k--;
        long long r = k / 4;
        if(r)
            printf("%lld", r);
        printf("%d\n", ans[k % 4]);
    }

    return 0;
}
