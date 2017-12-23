#include <bits/stdc++.h>
using namespace std;

#define sz(v)       ((int)v.size())
#define all(v)      (v.begin()),(v.end())
#define rall(v)     (v.rbegin()),(v.rend())
#define ll          long long

vector <int> adj[101];
int lowLink[101], dfsn[101];
int dfn;
set <int> art_points;

void tarjan(int node,int par){
    dfsn[node] = lowLink[node] = dfn++;
    bool ok = false;
    
    for(int i=0;i<sz(adj[node]);i++){
        int child = adj[node][i];
        
        if(dfsn[child] == -1){
            tarjan(child, node);
            lowLink[node] = min(lowLink[node], lowLink[child]);
            if(lowLink[child] >= dfsn[node]){
                if(dfsn[node] == 0 && !ok){
                    ok = true;                    
                }else{
                    art_points.insert(node);                    
                }
            }
        }
        else if(child != par){
            lowLink[node] = min(lowLink[node], dfsn[child]);
        }

    }
}

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b, st;
    string s;
    while(scanf("%d",&n), n){
        memset(adj,0,sizeof(adj));
        memset(lowLink, 0, sizeof(lowLink));
        memset(dfsn, -1, sizeof(dfsn));
        dfn = 0;
        while(scanf("%d",&a), a ){
            getline(cin,s);
            istringstream iss(s);
            while(iss >> b){
                st = b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }        
        tarjan(st,-1);
        cout << sz(art_points) << endl;
        art_points.clear();
    }
    return 0 ;
}
