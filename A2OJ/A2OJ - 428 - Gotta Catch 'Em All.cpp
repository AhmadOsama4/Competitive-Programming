#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

struct point{
    int x, y, type, idx;
    point(int _x, int _y, int _type, int _idx){
        x = _x, y = _y, type = _type, idx = _idx;
    }
    point(){}
};

bool cmpX(const point &a, const point &b){
    return a.x < b.x;
}
bool cmpY(const point &a, const point &b){
    return a.y < b.y;
}

int n, k, cnt[1005], cur;
point xpoints[1005], ypoints[1005];
bool isActive[1005];

void ADD(int type)
{
    cnt[type]++;
    if(cnt[type] == 1)
        cur++;
}

void Remove(int type)
{
    cnt[type]--;
    if(cnt[type] == 0)
        cur--;
}

bool valid(int d)
{
    int leftx = 0;
    memset(isActive, 0, sizeof isActive);

    for(int i = 0; i < n; i++){
        while(leftx < i && (xpoints[i].x - xpoints[leftx].x) > d){
            isActive[xpoints[leftx].idx] = 0;
            leftx++;
        }

        isActive[xpoints[i].idx] = 1;

        vector <point> V;

        for(int j = 0; j < n; j++)
            if(isActive[ypoints[j].idx]){
                V.push_back(ypoints[j]);
            }

        int lefty = 0;
        memset(cnt, 0, sizeof cnt);
        cur = 0;

        for(int j = 0; j < sz(V); j++){
            while(lefty < j && (V[j].y - V[lefty].y) > d){
                Remove(V[lefty].type);
                lefty++;
            }
            ADD(V[j].type);

            if(cur >= k)
                return true;
        }
    }

    return false;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc, x, y, z;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &x, &y, &z);
            xpoints[i] = point(x, y, z, i);
            ypoints[i] = point(x, y, z, i);
        }
        sort(xpoints, xpoints + n, cmpX);
        sort(ypoints, ypoints + n, cmpY);

        long long ans = 0, L = 1, R = 2e9;

        while(L <= R){
            int mid = (L + R) >> 1;
            if(valid(mid)){
                ans = mid;
                R = mid - 1;
            }
            else{
                L = mid + 1;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
