#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("2\n1 1\n");
        return 0;
    }
    if(n & 1){
        printf("%d\n", 2 * (n / 2) + (n / 2 + 1));
        for(int i = 2; i <= n; i+=2)
            printf("%d ", i);
        for(int i = 1; i <= n; i+=2)
            printf("%d ", i);
        for(int i = 2; i <= n; i+=2)
            printf("%d ", i);
    }
    else{
        printf("%d\n", n / 2 * 3);
        for(int i = 2; i <= n; i+=2)
            printf("%d ", i);
        for(int i = 1; i <= n; i+=2)
            printf("%d ", i);
        for(int i = 2; i <= n; i+=2)
            printf("%d ", i);
    }
    return 0;
}
