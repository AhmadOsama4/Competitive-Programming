#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, k, ans;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        ans = k * (n / (k + 1));
        if(n % (k + 1)){
            ans += n % (k + 1);
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
