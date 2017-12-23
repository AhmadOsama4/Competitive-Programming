#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int arr[1005];
bool vis[1000005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, g;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
        vis[arr[i]] = 1;
    }
    g = arr[0];
    for(int i = 1; i < n; i++)
        g = __gcd(g, arr[i]);

    if(!vis[g]){
        puts("-1");
        return 0;
    }
    printf("%d\n", 2 * n);
    for(int i = 0; i < n; i++)
        printf("%d %d ", g, arr[i]);

    puts("");
    return 0;
}
