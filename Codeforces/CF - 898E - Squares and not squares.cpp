#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

const int N = 200005;

pair <int, int> V[N];

int main ()
{
    //freopen("input.txt","r",stdin);
    vector <int> squares;

    for(int i = 0; ; i++){
        squares.push_back(i * i);
        if(i * i > 1e9)
            break;
    }
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(binary_search(all(squares), x)){
            V[i] = make_pair(0, x);
            continue;
        }
        auto it = upper_bound(all(squares), x);
        int idx = it - squares.begin();

        int add = min(squares[idx] - x, x - squares[idx - 1]);
        V[i] = make_pair(add, x);
    }

    sort(V, V + n);
    long long ans = 0;

    int lim = n / 2;
    for(int i = 0; i < lim; i++)
        ans += V[i].first;

    for(int i = lim; i < n; i++){
        if(V[i].second == 0)
            ans += 2;
        else if(V[i].first == 0)
            ans++;
    }

    printf("%lld\n", ans);
    return 0;
}
