#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int mod[2] = {1000000007, 1000000009};
int Hash[1000001][2], p10[1000001][2];

string s;
pair <int,int> get(int L, int R)
{
    int r[2];

    int len = R - L + 1;
    for(int i = 0; i < 2; i++){
        r[i] = Hash[R][i];
        if(L)
            r[i] = (r[i] - (Hash[L - 1][i] * 1LL * p10[len][i]) % mod[i] + mod[i]) % mod[i];
    }

    return make_pair(r[0], r[1]);
}

bool checkLeadingZeros(int i1, int i2)
{
    if(i1 && s[0] == '0')
        return 0;
    if(i2 - i1 > 1 && s[i1 + 1] == '0')
        return 0;
    if(sz(s) - 1 - i2 > 1 && s[i2 + 1] == '0')
        return 0;
    return 1;
}
bool check(int i1, int i2)
{
    if(!checkLeadingZeros(i1, i2))
        return 0;
    pair <int, int> a, b, c;

    a = get(0, i1);
    b = get(i1 + 1, i2);
    c = get(i2 + 1, sz(s) - 1);

    a.first = (a.first + b.first) % mod[0];
    a.second = (a.second + b.second) % mod[1];

    return a == c;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    cin >> s;

    Hash[0][0] = Hash[0][1] = s[0] - '0';
    p10[0][0] = p10[0][1] = 1;

    int a, b, c;
    for(int i = 1; i < sz(s); i++){
        c = s[i] - '0';

        for(int j = 0; j < 2; j++)
            Hash[i][j] = ((Hash[i - 1][j] * 10LL) % mod[j] + c) % mod[j];

        p10[i][0] = (10LL * p10[i - 1][0]) % mod[0];
        p10[i][1] = (10LL * p10[i - 1][1]) % mod[1];
    }

    for(int i = (sz(s) + 2)/3 , lim = sz(s) / 2; i <= lim; i++){
        int last = sz(s) - 1 - i;
        if(check(last - i, last)){ // b length = i
            a = last - i + 1;
            b = last + 1;
            break;
        }
        if(check(i - 1, last)){ // a length = i
            a = i;
            b = last + 1;
            break;
        }
        if(check(last - i + 1 , last)){ // b length = i - 1
            a = last - i + 2;
            b = last + 1;
            break;
        }
        if(check(i - 2, last)){ // a length  = i - 1
            a = i - 1;
            b = last + 1;
            break;
        }
    }
    for(int i = 0; i < sz(s); i++){
        if(i == a)
            putchar('+');
        else if(i == b)
            putchar('=');
        putchar(s[i]);
    }
    puts("");
    return 0;
}
