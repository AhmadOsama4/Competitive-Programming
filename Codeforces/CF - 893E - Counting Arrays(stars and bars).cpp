#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

const int mod = 1e9 + 7;
const int N = 1000001;

int fact[2 * N], p2[N];

int power(int b, int p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return b;

    int r = power(b, p >> 1);
    r = (1LL * r * r) % mod;

    if(p & 1)
        r = (1LL * r * b) % mod;

    return r;
}
int nCr(int n, int r)
{
    int ret = fact[n];
    ret = (1LL * ret * power(fact[r], mod - 2)) % mod;
    ret = (1LL * ret * power(fact[n - r], mod - 2)) % mod;

    return ret;
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

    fact[0] = p2[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (1LL * i * fact[i - 1]) % mod;
        p2[i] = (2 * p2[i - 1]) % mod;
    }
    for(int i = N; i < N + N; i++)
        fact[i] = (1LL * i * fact[i - 1]) % mod;

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
            if(p)
                ans = (1LL * ans * nCr(y + p - 1, p)) % mod;
        }
        if(x != 1)
            ans = (1LL * ans * y) % mod;

        ans = (1LL * ans * p2[y - 1]) % mod;

        printf("%d\n", ans);
    }
    return 0;
}
