/*
    Generate values for first row
    Each cell will require its adjacent cell
    in the next row to be 0 or 1 based on its current
    adjacent cells (left, right, up) values
*/

#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int masks[15], cur[15];
int n, ans = 0;

void solve(int i, int mask, int val)
{
    if(i == n){
        if(mask)
            return;
        ans = min(ans, val);
        return;
    }
    if((mask & masks[i]) != masks[i])
        return;
    cur[i] = mask;

    int add = __builtin_popcount(mask ^ masks[i]);
    // next mask
    int nxt = 0;
    bool a, b, c;
    for(int j = 0; j < n; j++){
        a = b = c = 0;
        if(j)
            a = cur[i] & (1 << (j - 1)); // bit before
        if(i)
            b = cur[i - 1] & (1 << j); // bit above

        c = cur[i] & (1 << (j + 1)); // bit after

        bool f = a ^ b ^ c;
        if(f)
            nxt = nxt | (1 << j);
    }
    solve(i + 1, nxt, val + add);
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, x, test = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        memset(masks, 0, sizeof masks);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &x);
                if(x)
                    masks[i] |= (1 << j);
            }
        }

        // generate masks for first row
        int lim = (1 << n);
        ans = 1e9;

        for(int mask = 0; mask < lim; mask++){
            solve(0, mask, 0);
        }

        if(ans == 1e9)
            ans = -1;

        printf("Case %d: %d\n", test++, ans);
    }
    return 0;
}
