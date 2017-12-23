#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int n;
int arr[105];
bool solve(int a, int b)
{
    for(int i = 0; i < n; i++){
        if(arr[i] != a && arr[i] != b)
            return 0;
        if(arr[i] == a){
            for(int j = 0; j < 3; j++)
                if(j != a && j != b){
                        b = j;
                        break;
                }
        }
        else{
            for(int j = 0; j < 3; j++)
                if(j != a && j != b){
                    a = j;
                    break;
                }
        }
    }
    return 1;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }
    bool ok =  solve(0, 1);

    puts(ok ? "YES" : "NO");
    return 0;
}
