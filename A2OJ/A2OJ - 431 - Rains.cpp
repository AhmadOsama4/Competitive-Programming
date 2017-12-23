#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const double Pi = acos(-1);
const double eps = 1e-8;

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    long double a, b, ans;
    long double n, s, r;
    cout << fixed << setprecision(4);
    while(tc--){
        cin >> n >> s >> r;

        a = 1.0 * s / 2;
        long double angle = 1.0 * (n - 2) * Pi / n;
        angle /= 2;
        b = a * tan(angle);
        long double largeArea = a * b;

        if(b - r < eps){
            ans = 1.0;
            cout << ans << endl;
            continue;
        }

        b -= r;
        a = b / tan(angle);
        long double smallArea = largeArea - a * b;

        ans = smallArea/largeArea;

        cout << ans << endl;
    }
    return 0;
}
