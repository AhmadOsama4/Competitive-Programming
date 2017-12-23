#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int n, c;
int heights[100005], colors[100005], sum[100005][31];
int Left[100005], Right[100005];

bool checkAllColors(int L, int R)
{
    int t;
    for(int i = 0;i < c; i++){
        t = sum[R][i] - sum[L-1][i];
        if(t == 0)
            return false;
    }
    return true;
}
int main ()
{
    //freopen("input.txt", "r", stdin);

    while(scanf("%d%d", &n, &c), n)
    {
        memset(sum, 0, sizeof sum);

        for(int i = 1;i <= n; i++)
            scanf("%d", heights + i);
        for(int i = 1;i <= n; i++)
            scanf("%d", colors + i);

        for(int i = 1;i <= n; i++){
            sum[i][colors[i]] = 1;
            for(int j = 0; j < c; j++)
                sum[i][j] += sum[i - 1][j];

            Right[i] = n + 1;
        }

        long long ans = 0;
        stack <pair<int,int>> S;
        memset(Left, 0, sizeof Left);

        for(int i = 1; i <= n; i++){
            while(!S.empty() && heights[i] <= S.top().first)
                S.pop();

            if(!S.empty())
                Left[i] = S.top().second;

            S.push(make_pair(heights[i], i));
        }

        while(!S.empty())
            S.pop();

        for(int i = n; i > 0; i--){
            while(!S.empty() && heights[i] <= S.top().first)
                S.pop();

            if(!S.empty())
                Right[i] = S.top().second;

            S.push(make_pair(heights[i], i));
        }


        for(int i = 1;i <= n; i++){
            if(checkAllColors(Left[i] + 1, Right[i] - 1)){
                ans = max(ans, heights[i] * 1LL * (Right[i] - Left[i] - 1));
            }
        }

        cout << ans << endl;

    }
    return 0;
}
