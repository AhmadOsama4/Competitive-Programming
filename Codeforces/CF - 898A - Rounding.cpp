#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    if(n % 10 == 0){
        cout << n << endl;
        return 0;
    }
    for(int i = 1; i < 6 ;i++){
        int x = (n + i);

        if(x % 10 == 0){
            cout << x << endl;
            return 0;
        }

        x = (n - i);
        if(x % 10 == 0){
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}
