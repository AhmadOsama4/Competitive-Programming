#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <map>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

const int M = 100005;
const long long MOD = 1e9 + 7;

vector <bool> isprime(M+5,1);

long long primes[M] ;
int primes_cnt=0;

void sieve()
{
    isprime[0] = isprime[1] = 0;
    for(int i=2;i<M;i++){
        if( isprime[i] ){
            primes[primes_cnt] = 1LL*i;
            for(int j=i*2; j<M ; j+=i){
                isprime[j] = 0;
            }
            primes_cnt++;
        }
    }
}

map <long long , long long> power , res;

int main ()
{
    //freopen("input.txt","r", stdin);
    sieve();
    int T;
    scanf("%d",&T);
    for(int ts=1;ts<=T;ts++)
    {
        int n;
        scanf("%d",&n);
        long long a , ans=1;
        for(int i=0;i<n;i++){
            cin>>a;
            for(int j=0; ( (primes[j]*primes[j]) <= a) && (j<=primes_cnt);j++){
                long long p = primes[j];
                while(a%p == 0){
                    if(power.find(p) == power.end()){
                        power[p] = 1 ;
                        res[p] = 1;
                    }

                    power[p] = (power[p]*p) % MOD;
                    res[p] =  ( res[p] + power[p]) % MOD;

                    a /= p;
                }
            }
            if(a>1){
                if(power.find(a) == power.end()){
                    power[a] = 1 , res[a] = 1;
                }
                power[a] = ( a* power[a]) % MOD;
                res[a] = ( res[a] + power[a]) % MOD;
            }

        }

        for( map<long long,long long>::iterator it = res.begin() ; it != res.end() ;it++){
            ans = ( ans * (it->second) ) % MOD;
        }
        printf("Case %d: ",ts);
        cout << ans << endl;
        power.clear();
        res.clear();
    }

    return 0;
}
