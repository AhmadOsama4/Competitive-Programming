#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, g, cur, req;
    cin >> tc;
    int group[] = {0, 1, 3, 5};
    while(tc--){
        cin >> g >> cur >> req;
        if(cur >= req){
            puts("0");
            continue;
        }
        cout << (req - cur) * group[g] << endl;
    }
    return 0;
}
