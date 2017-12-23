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
#define cross(a,b)   ( (conj(a)*(b)).imag() )
#define eps          1e-10

bool AreCollinear(point p1,point p2,point p3){
    return fabs(cross(p2-p1,p3-p1)) < eps;
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, a, b;
    long double a1, a2, b1, b2, c1, c2;
    cin >> tc;
    puts("INTERSECTING LINES OUTPUT");
    while(tc--){
        point p[4];
        for(int i=0;i<4;i++){
            scanf("%d%d",&a,&b);
            p[i] = point(a, b);
        }
        if(AreCollinear(p[0], p[1], p[2]) && AreCollinear(p[0], p[1], p[3])){
            puts("LINE");
            continue;
        }
        if(fabs(cross(p[1]-p[0],p[3]-p[2])) < eps){
            puts("NONE");
            continue;
        }
        a1 = p[0].y - p[1].y;
        b1 = p[1].x - p[0].x;
        c1 = p[0].x * p[1].y - p[1].x * p[0].y;

        a2 = p[2].y - p[3].y;
        b2 = p[3].x - p[2].x;
        c2 = p[2].x * p[3].y - p[3].x * p[2].y;

        long double ax, ay;

        ay = (a1*c2 - a2*c1)/(a2*b1 - a1*b2);
        ax = -(c1 + b1*ay)/(a1);

        cout << "POINT " << fixed << setprecision(2) << ax << " " << ay << endl;
    }
    puts("END OF OUTPUT");
    return 0;
}

