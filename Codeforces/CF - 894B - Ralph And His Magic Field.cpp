#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

const int mod = 1e9 + 7;

long long power(int b, int p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return b;

    long long r = power(b, p >> 1);
    r = (r * r) % mod;
    if(p & 1)
        r = (r * b) % mod;

    return r;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    long long n, m, k;
    cin >> n >> m >> k;

    if(n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    if(k == -1 && (n + m) % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 1 || m == 1){
        if(k == -1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }

    n = (n - 1) % (mod - 1);
    m = (m - 1) % (mod - 1);

    int p = (n * m) % (mod - 1);
    cout << power(2, p) << endl;
    return 0;
}
