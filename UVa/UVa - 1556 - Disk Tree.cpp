#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

int main ()
{
    //freopen("input.txt","r",stdin);
    int n;
    while(cin >> n)
    {
        vector <vector<string>> V;
        string s, t;
        for(int i=0;i<n;i++){
            V.push_back(vector<string> ());
            cin >> s;
            for(int i=0;i<sz(s);i++)
                if(s[i] == '\\')
                    s[i] = ' ';

            istringstream iss(s);
            while(iss >> t)
                V.back().push_back(t);
        }
        sort(all(V));

        for(int i=0;i<n;i++){
            bool f = 1;
            for(int j=0;j<sz(V[i]);j++){
                if(i == 0 || j >= sz(V[i-1]) || V[i][j] != V[i-1][j])
                    f = 0;
                if(f)
                    continue;
                for(int ss=0;ss<j;ss++)
                    putchar(' ');
                cout << V[i][j] << endl;
            }
        }

        puts("");
    }
    return 0;
}
