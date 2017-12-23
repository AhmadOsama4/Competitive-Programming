#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

int n, m, num, rowAssign[205], colAssign[205];
bool vis[205], AdjMat[205][205];
double gopherX[405], gopherY[405], holeX[405], holeY[405];

bool canMatch(int node)
{
    for(int i=n;i<num;i++){
        if(AdjMat[node][i] && !vis[i]){
            vis[i] = 1;
            if(colAssign[i] < 0 || canMatch(colAssign[i])){
                colAssign[i] = node;
                rowAssign[node] = i;
                return 1;
            }
        }
    }
    return 0;
}

int BipartiteMatching()
{
    int maxFlow = 0;
    SetTo(colAssign, -1);
    SetTo(rowAssign, -1);

    for(int i=0;i<n;i++){
        SetTo(vis, 0);
        if(canMatch(i))
            maxFlow++;
    }
    return maxFlow;
}

double hypotenese(double x, double y){
    return sqrt(x * x + y * y );
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int s, v;
    while(cin >> n >> m >> s >> v)
    {
        SetTo(AdjMat, 0);
        for(int i=0;i<n;i++)
            cin >> gopherX[i] >> gopherY[i];
        for(int i=0;i<m;i++)
            cin >> holeX[i] >> holeY[i];


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                double dist = hypotenese(gopherY[i] - holeY[j], gopherX[i] - holeX[j]);
                if(dist <=  s * v){
                    AdjMat[i][n+j] = 1;
                }
            }
        }
        num = n + m;

        cout << (n - BipartiteMatching()) << endl;
    }
    return 0;
}
