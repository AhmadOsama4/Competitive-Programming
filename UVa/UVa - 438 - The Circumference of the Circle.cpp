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
#define lenght(a)    (hypot(a.y, a.x))
#define vec(a,b)     ((b) - (a))
#define eps           (1e-10)

const double Pi = acos(-1);

point intersection(point p1, point p2, point p3)
{
    long double a1, a2, b1, b2, c1, c2;
    point t1 = ((p2) + (p1))/(point(2,0));
    point t2 = ((p3) + (p2))/(point(2,0));

    point tmp = vec(p1,p2);
    point v1 = point(tmp.y, -tmp.x);
    tmp = vec(p3, p2);
    point v2 = point(tmp.y, -tmp.x);

    point t11 = vec(v1, t1);
    point t22 = vec(v2, t2);

    a1 = t1.y - t11.y, b1 = t11.x - t1.x, c1 = t1.x * t11.y - t11.x*t1.y;
    a2 = t2.y - t22.y, b2 = t22.x - t2.x, c2 = t2.x * t22.y - t22.x*t2.y;

    long double yy = (a1*c2 - a2*c1)/(a2*b1 - a1*b2);
    long double xx;

    if(fabs(a1) > eps)
        xx = -( (b1*yy + c1)/(a1) );
    else
        xx = -( (b2*yy + c2)/(a2));

    return point(xx, yy);
}
int main ()
{
    //freopen("input.txt","r",stdin);
    double a, b, c, d, e, f;

    while(cin>>a>>b>>c>>d>>e>>f)
    {
        point p1(a, b), p2(c, d), p3(e, f);

        point p = intersection(p1, p2, p3);

        long double r = lenght(vec(p, p1));

        cout << fixed << setprecision(2) << 2*Pi*r << endl;

    }
    return 0;
}
