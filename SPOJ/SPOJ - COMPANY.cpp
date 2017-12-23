#include <bits/stdc++.h>
using namespace std;

vector <int> AdjList[1005];
bool comb[1005][1005] , vis[1005];
int par=0,num;
pair <int,int> x[10005];

void dfs(int node ,int dep)
{
    if(vis[node])
        return;
    vis[node] = 1;
    if(dep > 1 && comb[par][node]){
        comb[par][node] = 0;
        num--;
    }

    for(int i=0;i<AdjList[node].size();i++){
        int child = AdjList[node][i];
        dfs(child,dep+1);
    }

}

int main ()
{
    //freopen("input.txt","r",stdin);
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    num = m;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        x[i] = make_pair(a,b);
        AdjList[a].push_back(b);
        comb[a][b] = 1;
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        par = i;
        dfs(i,0);
    }
    cout << num << endl;
    for(int i=0;i<m;i++){
        a = x[i].first , b = x[i].second;
        if(comb[a][b])
            printf("%d %d\n",a,b);
    }
    return 0;
}
