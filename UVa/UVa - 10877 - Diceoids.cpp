#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int nxt[6][6] = {
                    {4, 1, 0 ,2, 3, 5},
                    {2, 1, 3, 4, 0, 5},
                    {1, 3, 2, 5, 4, 0},
                    {5, 0, 2, 1, 4, 3},
                    {0, 4, 1, 3, 5, 2},
                    {0, 2, 5, 3, 1, 4},
                };

map < vector <int> , bool> used;

bool bfs(vector <int> V)
{
    map < vector <int> , bool> vis;
    vis[V] = 1;
    queue < vector <int> > q;
    q.push(V);

    while(!q.empty()){
        vector <int> cur = q.front();
        q.pop();
        if(used[cur])
            return 1;

        for(int i = 0; i < 6; i++){
            vector <int> tmp;
            for(int j = 0; j < 6; j++){
                tmp.push_back(cur[nxt[i][j]]);
            }
            if(!vis[tmp]){
                vis[tmp] = 1;
                q.push(tmp);
            }
        }
    }
    return 0;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, arr[6], ans = 0;
    while(scanf("%d", &n), n)
    {
        used.clear();
        ans = 0;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < 6; i++)
                scanf("%d", arr + i);
            vector <int> V(arr, arr + 6);
            if(!bfs(V)){
                ans++;
                used[V] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
