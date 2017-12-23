#include <bits/stdc++.h>
using namespace std;

typedef complex <long double> point;
const double EPS = 1e-8;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))
#define X                           real()
#define Y                           imag()
#define vec(a,b)                    ((b)-(a))
#define dot(a,b)                    ( (conj(a)*(b)).real() )
#define cross(a,b)                  ( (conj(a)*(b)).imag() )


struct cmp {
    point about;
    cmp(point c){
        about = c;
    }
    bool operator()(const point& p, const point& q) const {
        double c = cross(vec(about,p),vec(about,q));
        if (fabs(c) < EPS)
            return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
        return c > 0;
    }
};

void sortAntiClockWise(vector<point> &pnts) {
    point about = pnts[0];
    for (int i = 0; i < sz(pnts); i++)
        if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(about.Y, about.X))
            about = pnts[i];

    sort(all(pnts),cmp(about)) ;
}

void convexHull(vector<point> pnts, vector<point> &convex) {
    sortAntiClockWise(pnts);
    convex.clear();
    convex.push_back(pnts[0]);
    if (sz(pnts) == 1)
        return;

    convex.push_back(pnts[1]);
    pnts.push_back(pnts[0]);

    for(int i = 2; i < sz(pnts); i++){
        point c = pnts[i];
        while (sz(convex) > 1) {
            point b = convex.back();
            point a = convex[sz(convex) - 2];
            if (cross(vec(b,a),vec(b,c)) < -EPS)
                break;
            convex.pop_back();
        }

        convex.push_back(pnts[i]);
    }
    pnts.pop_back();
}


int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, n, r, x, y;
    scanf("%d", &tc);
    printf("%d\n", tc);
    while(tc--)
    {
        scanf("%d", &n);
        vector <point> points, convex;

        points.resize(n);
        for(int i=0;i<n;i++){
            scanf("%d%d", &x, &y);
            points[i] = point(x, y);
        }
        convexHull(points, convex);

        printf("%d\n", sz(convex));
        for(int i=0;i<sz(convex);i++){
            printf("%d %d\n", int(convex[i].X), int(convex[i].Y));
        }
        if(tc){
            scanf("%*d");
            puts("-1");
        }
    }
    return 0;
}
