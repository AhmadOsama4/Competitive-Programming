#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

const int MAX = 100005;

char str[MAX], s[MAX];
int SA[MAX], group[MAX], sorGroup[MAX];
int len;

struct cmp{
    int h;
    cmp(int _h){
        h = _h;
    }
    bool operator ()(int i, int j){
        if(group[i] != group[j])
            return group[i] < group[j];
        return group[i+h] < group[j+h];
    }
};

void buildSuffixArray()
{
    int n;
    n = strlen(str);
    for(int i=0;i<n;i++)
        SA[i] = i, group[i] = str[i];

    SA[n] = n;
    group[n] = 0;
    n++;
    sort(SA, SA + n, cmp(0));
    sorGroup[0] = sorGroup[n-1] = 0;

    for(int h=1;sorGroup[n-1] != n - 1; h <<= 1){
        sort(SA, SA + n, cmp(h));

        for(int i=1;i<n;i++)
            sorGroup[i] = sorGroup[i-1] + cmp(h)(SA[i-1], SA[i]);
        for(int i=0;i<n;i++)
            group[SA[i]] = sorGroup[i];
    }
}

inline bool check(int idx, int m)
{
    int k = min(m, len - idx);

    for(int i=0;i<k;i++){
        if(s[i] < str[idx + i])
            return -1;
        if(str[idx + i] < s[i])
            return 1;
    }
    if(k < m)
        return 1;
    return 0;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, q, n, L, R, a, m;
    scanf("%d\n", &tc);
    while(tc--)
    {
        scanf("%s", str);
        buildSuffixArray();
        scanf("%d\n", &q);
        n = strlen(str) + 1;
        len = n;
        while(q--){
            scanf("%s", s);
            m = strlen(s);
            L = 1, R = n;
            a = -1;
            while(L <= R){
                int mid = (L+R)>>1;
                int t = check(SA[mid], m);
                // OR we can use strncmp() instead of creating this check function
                // int t = strncmp(s, str + SA[mid], m);
                if(t == 0){
                    a = mid;
                    break;
                }
                if(t < 0){
                    R = mid - 1;
                }
                else{
                    L = mid + 1;
                }
            }
            puts((a == -1)? "n" : "y");

            SetTo(SA, 0);
            SetTo(group, 0);
            SetTo(sorGroup, 0);
        }
    }
    return 0;
}
