#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> point;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))
#define x            first
#define y            second


const int MAX = 105;

int xcord1[MAX], ycord1[MAX], xcord2[MAX], ycord2[MAX], nxt[MAX];
pair <int,int> output[MAX];

double ycord(point s, point e, point p){
    if(s.x == e.x)
        return max(s.y, e.y);

    return - double( (s.y - e.y)*p.x + (s.x*e.y - e.x*s.y) )/(e.x - s.x);
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, n, m, a, b;
    cin >> tc;
    while(tc--){
        SetTo(nxt, -1);
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d", &xcord1[i], &ycord1[i], &xcord2[i], &ycord2[i]);
            if(xcord2[i] < xcord1[i]){
                swap(xcord1[i], xcord2[i]);
                swap(ycord1[i], ycord2[i]);
            }
            if(ycord1[i] < ycord2[i])
                output[i] = make_pair(xcord1[i], ycord1[i]);
            else
                output[i] = make_pair(xcord2[i], ycord2[i]);
        }
        for(int i=0;i<n;i++){
            double yc = -1;
            for(int j=0;j<n;j++){
                if(output[i].x <= xcord2[j] && output[i].x >= xcord1[j]){
                    double tmp = ycord({xcord1[j], ycord1[j]}, {xcord2[j], ycord2[j]}, output[i]);
                    if(tmp < output[i].y && tmp > yc){
                        yc = tmp;
                        nxt[i] = j;
                    }
                }
            }
        }

        for(int c=0;c<n;c++)
            for(int i=0;i<n;i++)
                if(nxt[i] != -1)
                    output[i] = output[nxt[i]];
    
        scanf("%d", &m);
        int nx = -1;
        for(int i=0;i<m;i++){
            scanf("%d%d", &a, &b);
            nx = -1;
            double yc = -1;
            for(int j=0;j<n;j++){
                if(xcord1[j]<=a && xcord2[j]>=a){
                    double tmp = ycord({xcord1[j], ycord1[j]}, {xcord2[j], ycord2[j]}, {a, b});
                    if(tmp < b && tmp > yc){
                        nx = j;
                        yc = tmp;
                    }
                }
            }        
            if(nx == -1)
                printf("%d\n", a);
            else
                printf("%d\n", output[nx].x);
        }
        if(tc)
            puts("");
    }
    return 0;
}

