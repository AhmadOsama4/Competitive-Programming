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
    int tc, x, y, z, n, a, b, c, mnx, mny, mnz, mxx, mxy, mxz;
    cin >> tc;
    while(tc--)
    {
        scanf("%d%d%d%d", &x, &y, &z, &n);
        mnx = mny = mnz = (1<<30);
        mxx = mxy = mxz = -1;
        for(int i=0;i<n;i++){
            scanf("%d%d%d", &a, &b, &c);
            mnx = min(mnx, a);
            mxx = max(mxx, a);
            mny = min(mny, b);
            mxy = max(mxy, b);
            mnz = min(mnz, c);
            mxz = max(mxz, c);
        }
        int Xor;
        if(!n){
            Xor = (x-1) ^ (y-1) ^ (z-1);
        }
        else{
            Xor = (x - mxx) ^ (mnx - 1) ^ (y - mxy) ^ (mny - 1) ^ (z - mxz) ^ (mnz - 1);
        }

        puts((Xor)? "Alice" : "Bob");
    }
    return 0;
}
