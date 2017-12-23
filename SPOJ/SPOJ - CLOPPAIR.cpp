#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

struct point{
    long long x, y;
    int idx;
    point(ll _x, ll _y, int _idx){
        x = _x, y = _y, idx = _idx;
    }
    point(){}
    bool operator ==(const point &b) const{
        return x == b.x && y == b.y && idx == b.idx;
    }
};

bool cmpX(const point &a, const point &b){
    return a.x < b.x;
}
struct cmpY{
    bool operator() (const point &a, const point &b){
        return a.y < b.y;
    }
};

const ll inf = 1e18;
int n, ans1, ans2;
long long mn;
point points[50005];

void lineSweep()
{
    long long tmp;
    long long d = 1e9;
    multiset <point, cmpY> activeWindow;

    int left = 0;

    for(int i = 0; i < n; i++){
        while(left < i && (points[i].x - points[left].x > d)){
            auto it = activeWindow.find(points[left]);
            activeWindow.erase(it);

            left++;
        }
        auto lower = activeWindow.lower_bound(point(-inf, points[i].y - d, -1));
        auto upper = activeWindow.upper_bound(point(-inf, points[i].y + d, -1));


        while(lower != upper){
            tmp = (points[i].x - (*lower).x) * (points[i].x - (*lower).x)
                + (points[i].y - (*lower).y) * (points[i].y - (*lower).y);

            if(tmp < mn){
                mn = tmp;
                ans1 = points[i].idx;
                ans2 = (*lower).idx;
                d = sqrt(tmp) + 1;
            }
            lower++;
        }

        activeWindow.insert(points[i]);
    }
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        points[i] = point(x, y, i);
    }
    sort(points, points + n, cmpX);

    mn = 1e18;
    lineSweep();
    if(ans1 > ans2)
        swap(ans1, ans2);

    printf("%d %d %.6f\n", ans1, ans2, sqrt((double)mn));

    return 0;
}

