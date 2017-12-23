#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))
#define f             first
#define s             second

int gcdExtended(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int g = gcdExtended(b, a%b, y, x);
    y -= (a/b)*x;
    return g;
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int x, y, a, b;
    while(cin >> a >> b){
        int g = gcdExtended(a, b, x, y);
        printf("%d %d %d\n", x, y, g);
    }
    return 0;
}

