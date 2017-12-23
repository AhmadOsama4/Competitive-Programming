#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

char r[1005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    r['e'] = 'q';
    r['d'] = 'a';
    r['c'] = 'z';
    r['r'] = 'w';
    r['f'] = 's';
    r['v'] = 'x';
    r['t'] = 'e';
    r['g'] = 'd';
    r['b'] = 'c';
    r['y'] = 'r';
    r['h'] = 'f';
    r['n'] = 'v';
    r['u'] = 't';
    r['j'] = 'g';
    r['m'] = 'b';
    r['i'] = 'y';
    r['k'] = 'h';
    r[','] = 'n';
    r['o'] = 'u';
    r['l'] = 'j';
    r['.'] = 'm';
    r['p'] = 'i';
    r[';'] = 'k';
    r['?'] = ',';
    r['['] = 'o';
    r[']'] = 'p';
    r['\''] = 'l';

    string s;

    cin >> s;
    for(int i=0;i<sz(s);i++)
        cout << r[tolower(s[i])];

    while(cin >> s){
        cout << " ";
        for(int i=0;i<sz(s);i++)
            cout << r[tolower(s[i])];
    }
    cout << endl;
    return 0;
}
