#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

vector <int> adj[2005];
int arr[1005], x[1005], y[1005];
int rowAssign[2005], colAssign[2005];
bool vis[2005];

bool canMatch(int node)
{
    for(int child : adj[node]){
        if(vis[child])
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
int main ()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", arr + i);
    for(int i=0;i<n;i++)
        scanf("%d%d", x + i, y + i);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i] <= y[j] && arr[i] >= x[j]){
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
            }
        }
    }
    memset(rowAssign, -1, sizeof rowAssign);
    memset(colAssign, -1, sizeof colAssign);

    int ans = 0;
    for(int i=0;i<n;i++){
        memset(vis, 0, sizeof vis);
        if(canMatch(i))
            ans++;
    }

    if(ans != n){
        puts("Let's search for another office.");
        return 0;
    }
    vector <int> res;

    for(int i=n;i<2*n;i++){
        res.push_back(colAssign[i] + 1);
    }
    bool ok = 1;
    int a, b, ii, jj;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            a = colAssign[n + i];
            b = colAssign[n + j];

            if(arr[a] >= x[j] && arr[a] <= y[j] && arr[b] >= x[i] && arr[b] <= y[i]){
                ok = 0;
                break;
            }
        }
    }

    if(!ok){
        puts("Ask Shiftman for help.");
    }
    else{
        puts("Perfect!");
        for(int i=0;i<sz(res);i++){
            printf("%d", res[i]);
            if(i != sz(res) - 1)
                printf(" ");
        }
        puts("");
    }

    return 0;
}
