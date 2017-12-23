#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

bool vis[105];

int main ()
{
    //freopen("input.txt","r",stdin);
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    int cur = 0;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        if(b < cur || a > cur)
            continue;
        cur = b;
    }
    puts(cur >= m ? "YES" : "NO");
    return 0;
}
