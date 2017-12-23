#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        while(a <= ans)
            a += b;
        ans = a;
    }
    printf("%d\n", ans);
    return 0;
}
