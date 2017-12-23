#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

string s[] = {"Danil", "Olya", "Slava", "Ann","Nikita"};

int main ()
{
    //freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    int cnt = 0;
    bool ok = 1;

    for(int i = 0; i < 5; i++){
        int idx = str.find(s[i]);
        if(idx != -1){
            cnt++;
            idx = str.find(s[i], idx + 1);
            if(idx != -1)
                ok = 0;
        }
    }
    if(cnt > 1 || !cnt)
        ok = 0;

    puts(ok? "YES" : "NO");
    return 0;
}
