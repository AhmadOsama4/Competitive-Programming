#include <bits/stdc++.h>
    using namespace std;

#define sz(v)       ((int)v.size())
#define all(v)      (v.begin()),(v.end())
#define rall(v)     (v.rbegin()),(v.rend())
#define ll          long long

bool adj[110][110];
int ndfn, n, a, b, m;
int lowLink[110], dfn[110];
set<pair<int,int>> res;

void tarjan(int node, int par)
{
    dfn[node] = lowLink[node] = ndfn++;
    for(int i=0;i<n;i++){
        int child = i;
        if(!adj[node][child])
            continue;

        if(dfn[child] == -1){
            tarjan(child, node);
            lowLink[node] = min(lowLink[node], lowLink[child]);
        }else if(child != par){
            lowLink[node] = min(lowLink[node], dfn[child]);
        }
    }
    if( (lowLink[node] == dfn[node]) && par != -1){
            res.insert( make_pair(min(node,par) , max(node, par)) );
    }

}

int main ()
{
    //freopen("input.txt","r",stdin);
    while(cin >> n){
        if(!n){
            puts("0 critical links");
            puts("");
            continue;
        }
        memset(adj, 0, sizeof(adj));
        memset(dfn, -1 , sizeof(dfn));
        ndfn = 0;

        for(int i=0;i<n;i++){
            scanf("%d (%d)",&a,&m);
            while(m--){
                scanf("%d",&b);
                adj[a][b] = adj[b][a] = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(dfn[i] == -1){
                tarjan(i, -1);
            }
        }
        printf("%d critical links\n",sz(res));

        for(set<pair<int,int>>::iterator it = res.begin(); it != res.end(); it++){
            printf("%d - %d\n",it->first, it->second);
        }
        puts("");
        res.clear();
    }
    return 0;
}
