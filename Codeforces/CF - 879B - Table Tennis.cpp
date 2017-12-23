#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int arr[5005];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
    if(k >= n){
        printf("%d\n", n);
        return 0;
    }
    for(int i = 0; i < n; i++){
        int tmp = 0;
        if(i)
            tmp = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i])
                break;
            tmp++;
            if(j == n - 1){
                printf("%d\n", arr[i]);
                return 0;
            }
        }
        if(tmp >= k){
            printf("%d\n", arr[i]);
            return 0;
        }
    }
    printf("%d\n", n);
    return 0;
}
