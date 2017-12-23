/*
ID: ao.fara1
LANG: C++
TASK: skidesign
*/

#include <bits/stdc++.h>
using namespace std;

int arr[1005];

int main()
{
    //freopen("input.txt","r",stdin);
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int n, ans = 1e9;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);

    sort(arr, arr + n);

    for(int minval = 0; minval <= arr[n - 1]; minval++){
        int maxval = minval + 17;
        int cur = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] < minval)
                cur += (minval - arr[i]) * (minval - arr[i]);
            else if(arr[i] > maxval)
                cur += (arr[i] - maxval) * (arr[i] - maxval);
        }
        ans = min(ans, cur);
    }
    printf("%d\n", ans);

    return 0;
}



