#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

int cnt[26], prv[205];
char C[205];
string ss[205];
int rowAssign[205], colAssign[205];
bool vis[205], forbid[205];
vector <int> adj[205];
string str;

bool canMatch(int node)
{
    for(int i=0;i < sz(adj[node]);i++){
        int child = adj[node][i];
        if(vis[child] || forbid[child])
            continue;
        vis[child] = 1;
        if(colAssign[child] == -1 || canMatch(colAssign[child])){
            colAssign[child] = node;
            rowAssign[node] = child;
            return 1;
        }
    }
    return 0;
}

int maxMatching()
{
     SetTo(rowAssign, -1);
     SetTo(colAssign, -1);

     int ret = 0;
     for(int i=0;i<sz(str);i++){
        SetTo(vis, 0);
        if(!forbid[i] && canMatch(i))
            ret++;
    }
    return ret;
}
int main ()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> str;
        SetTo(cnt, 0);
        SetTo(adj, 0);
        SetTo(forbid, 0);
        for(int i=0;i<sz(str);i++)
            cnt[str[i] - 'a']++;

        int idx = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<cnt[i];j++){
                C[idx++] = 'a' + i;
            }
        }

        for(int i=0;i<sz(str);i++){
            cin >> s;
            ss[idx++] = s;
        }

        for(int i=0;i<sz(str);i++){
            char c = C[i];
            for(int j=sz(str);j < idx;j++){
                int f = (int)ss[j].find(c);
                if(f != -1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if(maxMatching() != sz(str)){
            puts("NO SOLUTION");
            continue;
        }
        SetTo(forbid, 0);
        int cur = 0;

        for(int i=sz(str);i<idx;i++){
            cur++;
            for(int j=0;j<sz(adj[i]);j++){
                int child = adj[i][j];
                if(forbid[child])
                    continue;
                forbid[child] = forbid[i] = 1;
                int flow = maxMatching();
                if(flow + cur == sz(str)){
                    C[i] = C[child];
                    break;
                }
                forbid[child] = forbid[i] = 0;
            }
        }

        for(int i=sz(str);i<idx;i++)
            putchar(C[i]);
        puts("");
    }
    return 0;
}
