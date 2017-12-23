#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

pair <int,pair<int,int>> arr[100005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, ta, tb, a, b, d, tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &n);
        long double ans = 0.0;
        int rem = 0;

        for(int i=0;i<n;i++){
            scanf("%d%d%d", &a, &b, &d);
            arr[i] = make_pair(d, make_pair(a, b));
        }
        sort(arr, arr + n);

        int tmp, prv = 0;
        priority_queue <pair<int,int>> pq;

        for(int i=0;i<n;i++){
            a = arr[i].second.first, b = arr[i].second.second, d = arr[i].first;
            pq.push(make_pair(a, b));

            if(prv + b <= d){
                prv = prv + b;
                continue;
            }
            rem = prv + b - d;

            while(rem){
                ta = pq.top().first, tb = pq.top().second;
                pq.pop();
                tmp = min(rem, tb);
                rem -= tmp;

                ans += 1.0 * tmp / ta;

                tb -= tmp;
                if(tb){
                    pq.push(make_pair(ta, tb));
                }
            }

            prv = d;
        }

        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
