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
    int a, b;
    while(scanf("%d%d",&a, &b), a || b)
    {
        if(a < b)
            swap(a, b);
        bool sTurn = 1;
        while(true){
            if(a/b > 1 || a%b == 0){
                puts(sTurn? "Stan wins" : "Ollie wins");
                break;
            }
            a = a%b;
            swap(a, b);
            sTurn = !sTurn;
        }

    }
    return 0;
}

