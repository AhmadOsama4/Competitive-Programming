#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

const int mod = 1e9 + 7;
const int N = 1000001;

int dp[N][20];
int p2[N];

int solve(int n, int k)
{
    if(n == 1 || !k)
        return 1;
    if(dp[n][k] != -1)
        return dp[n][k];

    int ret = solve(n, k - 1);
    ret = (ret + solve(n - 1, k)) % mod;

    return dp[n][k] = ret;
}

vector <int> primes;

void sieve(int limit)
{
    vector <bool> isPrime(limit, 1);

    for(int i = 2; i * i <= limit; i++)
        if(isPrime[i])
            for(int j = i + i; j < limit; j += i)
                isPrime[j] = 0;

    for(int i = 2; i < limit; i++)
        if(isPrime[i])
            primes.push_back(i);
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int q, x, y;
    scanf("%d", &q);
    sieve(1005);
    memset(dp, -1, sizeof dp);

    p2[0] = 1;
    for(int i = 1; i < N; i++)
        p2[i] = (2 * p2[i - 1]) % mod;

    int ans, p;

    while(q--){
        scanf("%d %d", &x, &y);
        ans = 1;
        if(x == 1){
            printf("%d\n", p2[y - 1]);
            continue;
        }

        for(int prime : primes){
            if(prime * prime > x)
                break;
            p = 0;
            while(x % prime == 0){
                p++;
                x /= prime;
            }
            ans = (1LL * ans * solve(y, p)) % mod;
        }
        if(x != 1)
            ans = (1LL * ans * solve(y, 1)) % mod;

        ans = (1LL * ans * p2[y - 1]) % mod;

        printf("%d\n", ans);
    }
    return 0;
}
