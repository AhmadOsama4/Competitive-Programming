#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int arr[200005];

int main ()
{
    //freopen("input.txt","r",stdin);
    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    sort(arr, arr + n);

    deque <int> dq;

    for(int i = 0; i < n; i++){
        dq.push_back(arr[i]);
        while(dq.back() - dq.front() >= m)
            dq.pop_front();

        while(sz(dq) >= k){
            dq.pop_back();
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
