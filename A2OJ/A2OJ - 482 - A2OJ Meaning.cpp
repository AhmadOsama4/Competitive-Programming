#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, n;
    cin >> tc;
    char res[105];
    string s;

    while(tc--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            res[i] = s[0];
        }
        vector < pair <int, char> > V;
        char c = res[0];
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(res[i] == res[i - 1]){
                cnt++;
            }
            else{
                V.push_back(make_pair(cnt, c));
                cnt = 1;
                c = res[i];
            }
        }
        V.push_back(make_pair(cnt, c));

        for(int i = 0; i < sz(V); i++){
            if(V[i].first == 1)
                cout << V[i].second;
            else
                cout << V[i].second << V[i].first;
        }
        cout << endl;
    }
    return 0;
}
