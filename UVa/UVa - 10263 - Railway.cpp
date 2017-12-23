#include <bits/stdc++.h>
using namespace std;

typedef complex <long double> point;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))
#define x            real()
#define y            imag()
#define dot(a,b)     ((conj(a)*(b)).real())
#define cross(a,b)   ((conj(a)*(b)).imag())
#define eps          1e-10
#define length(a)    (hypot((a).y, (a).x))

vector <point> points;
point p;

pair <long double, point> solve(point p1, point p2)
{
    point v1 = p2 - p1, v2 = p - p1;
    double d1, d2;
    d1 = dot(v1, v2);
    if(d1 <= 0.0)
        return {length(p - p1), p1};
    d2 = dot(v1,v1);
    if(d2 <= d1)
        return {length(p - p2), p2};

    double r = d1/d2;
    v1 *= r;
    return {length(p1 + v1 - p) , p1 + v1};
}

int main ()
{
    //freopen("input.txt","r",stdin);
    //freopen("o.txt", "w", stdout);
    int n;
    double a, b;
    while(cin >> a >> b >> n){
        p = point(a, b);
        points.resize(n+1);
        double res = -5;
        point ans;
        for(int i=0;i<=n;i++){
            cin >> a >> b;
            points[i] = point(a, b);
            if(i == 0)
                continue;
            pair <long double, point> tmp = solve(points[i-1], points[i]);
            if(res < -1 || tmp.first < res){
                res = tmp.first;
                ans = tmp.second;
            }
        }
        cout << fixed << setprecision(4) << (ans).x << endl << (ans).y << endl;
    }
    return 0;
}

