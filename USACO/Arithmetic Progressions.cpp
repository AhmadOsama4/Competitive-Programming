/*
ID: ao.fara1
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

set <int> S;
vector <int> V;
bool vis[2 * 250 * 250 + 1];
vector < pair<int,int> > ans;

int main()
{
    //freopen("input.txt","r",stdin);
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
            S.insert(i * i + j * j);

    set <int>:: iterator it;
    for(it = S.begin(); it != S.end(); it++){
        V.push_back(*it);
        vis[*it] = 1;
    }

    int tmp, lim;
    bool ok;
    for(int i = 0; i < sz(V); i++){
        for(int b = 1; V[i] + b * (n - 1) <= V.back(); b++){
            tmp = V[i], lim = V[i] + b * (n - 1);
            ok = 1;
            while(tmp <= lim){
                if(!vis[tmp]){
                    ok = 0;
                    break;
                }
                tmp += b;
            }
            if(ok)
                ans.push_back(make_pair(b, V[i]));
        }
    }
    sort(all(ans));
    for(int i = 0; i < sz(ans); i++)
        printf("%d %d\n", ans[i].second, ans[i].first);

    if(!sz(ans))
        puts("NONE");

    return 0;
}





