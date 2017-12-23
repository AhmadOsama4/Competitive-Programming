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
    int tc, n, i;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d", &n, &i);
        puts(i?"Pagfloyd wins." : "Airborne wins.");
    }
    return 0;
}
