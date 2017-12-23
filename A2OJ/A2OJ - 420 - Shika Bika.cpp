#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, L, R, n, q, x, y;
    scanf("%d", &tc);

    while(tc--){
        R = INT_MIN;
        L = INT_MAX;
        scanf("%d%d", &n, &q);
        for(int i=0;i<n;i++){
            scanf("%d%d", &x, &y);
            R = max(R, min(x, y));
            L = min(L, max(x, y));
        }
        while(q--){
            scanf("%d", &x);
            if(x >= L && x <= R)
                puts("YES");
            else
                puts("NOT SURE");
        }
    }
    return 0;
}
