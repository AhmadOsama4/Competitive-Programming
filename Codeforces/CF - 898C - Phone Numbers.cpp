#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

map <string, set<string> > mp;

int main ()
{
    //freopen("input.txt","r",stdin);
    int n, m;
    string s, num;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> m;
        for(int j = 0; j < m; j++){
            cin >> num;
            mp[s].insert(num);
        }
    }
    cout << sz(mp) << endl;

    for(auto it : mp)
    {
        set <string> S = it.second;
        set <string> ans;

        for(auto it1 : S){
            string cur = it1;
            bool ok = 1;
            for(auto it2 : S){
                string mat = it2;
                if(cur == mat || sz(mat) <= sz(cur))
                    continue;
                int diff = sz(mat) - sz(cur);
                string tmp = mat.substr(diff);
                if(tmp == cur){
                    ok = 0;
                    break;
                }
            }
            if(ok)
                ans.insert(cur);
        }
        cout << it.first << " ";
        cout << sz(ans) << " ";
        for(string x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
