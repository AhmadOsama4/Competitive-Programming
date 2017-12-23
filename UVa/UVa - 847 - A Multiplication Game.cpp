#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

int main ()
{
    //freopen("input.txt","r",stdin);
    ll n;
    while(cin >> n){
        bool win = 1;
        while(n > 1){
            if(win)
                n = n/9 + (n%9 != 0);
            else
                n = n/2 + (n%2 != 0);
            win = !win;
        }
        if(!win)
            puts("Stan wins.");
        else
            puts("Ollie wins.");
    }
    return 0;
}

