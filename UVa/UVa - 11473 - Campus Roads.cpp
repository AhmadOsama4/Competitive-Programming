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
#define normalize(a) ((a)/(length(a)))

double dist[105];
point points[105];

int main ()
{
    //freopen("input.txt","r",stdin);    
    int tc, n, k, t;
    double a, b;
    cin >> tc;
    for(int test=1;test<=tc;test++)
    {
        printf("Road #%d:\n", test);
        scanf("%d%d", &n, &t);

        long double total = 0.0;
        queue <point> q;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            points[i] = point(a, b);
            if(i > 0){
                dist[i] = length((points[i] - points[i-1]));
                total += dist[i];
            }
            q.push(points[i]);
        }
        double req = total/(t-1);
        cout << fixed << setprecision(2) << points[0].x << " " << points[0].y << endl;
        double cur = req;
       
        point CurPoint = points[0];
        q.pop();

        while(!q.empty()){
            point nxt = q.front();
            double d = length(nxt - CurPoint);
            if(fabs(cur - d) > eps && d < cur){
                q.pop();
                cur -= d;
                CurPoint = nxt;
                continue;
            }
            long double r = cur/d;
            point p = CurPoint + r*(nxt - CurPoint);
            cout << fixed << setprecision(2) << p.x << " " << p.y << endl;
            CurPoint = p;
            cur = req;
        }

        puts("");
    }
    return 0;
}

