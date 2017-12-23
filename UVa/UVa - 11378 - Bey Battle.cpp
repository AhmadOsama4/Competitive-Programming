#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

struct point{
    int x, y;
    point(int _x, int _y){
        x = _x, y = _y;
    }
    point(){}
};

bool cmpX(const point &a, const point &b){
    return a.x < b.x;
}
struct cmpY{
    bool operator() (const point &a, const point &b){
        return a.y < b.y;
    }
};

const int inf = 1e9;
int n;
point points[100005];

int lineSweep()
{
    int tmp, d = inf;
    set <point, cmpY> activeWindow;

    int left = 0;
    for(int i = 0; i < n; i++){
        while(left < i && (points[i].x - points[left].x > d))
            activeWindow.erase( activeWindow.find(points[left++]) );

        auto lower = activeWindow.lower_bound(point(-inf, points[i].y - d));
        auto upper = activeWindow.upper_bound(point(-inf, points[i].y + d));

        while(lower != upper){
            tmp = max(points[i].x - (*lower).x, abs(points[i].y - (*lower).y));
            d = min(d, tmp);
            lower++;
        }

        activeWindow.insert(points[i]);
    }

    return d;
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int x, y, ans;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++){
            scanf("%d%d", &x, &y);
            points[i] = point(x, y);
        }
        sort(points, points + n, cmpX);

        ans = lineSweep();
        printf("%d\n", ans);
    }
    return 0;
}
