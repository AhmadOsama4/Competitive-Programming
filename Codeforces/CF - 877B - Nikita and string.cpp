#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int sum[5005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    str = "*" + str;
    int len = sz(str) - 1, ans = 0, tmp;
    for(int i = 1; i < sz(str); i++)
        sum[i] = (str[i] == 'b') + sum[i - 1];

    if(sum[sz(str) - 1] == len){
        cout << len << endl;
        return 0;
    }
    for(int i = 1; i < sz(str); i++){
        if(str[i] != 'b')
            continue;
        for(int j = i; j < sz(str); j++){
            if(str[j] != 'b')
                continue;
            tmp = sum[j] - sum[i - 1];
            tmp += (i - 1 - sum[i - 1]);
            tmp += (len - j - (sum[len] - sum[j]));

            ans = max(ans, tmp);
        }
    }
    ans = max(ans, sum[len]);
    ans = max(ans, len - sum[len]);

    cout << ans << endl;

    return 0;
}
