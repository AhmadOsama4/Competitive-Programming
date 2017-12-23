#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n, score, mx;
    string s, ans;
    cin >> tc;
    while(tc--){
        mx = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s >> score;
            if(score > mx){
                mx = score;
                ans = s;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
