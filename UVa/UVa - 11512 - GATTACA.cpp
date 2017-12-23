#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

const int MAX = 1005;

char str[MAX];
int SA[MAX], group[MAX], sorGroup[MAX];

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

// Suffix Array O(n(log(n))^2)

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

int Rank[MAX];
int lcp[MAX];
void build_LCP()
{
    int n = strlen(str) + 1;
    for(int i=0;i<n;i++)
        Rank[SA[i]] = i;

    int c = 0;
    for(int i=0;i<n;i++){
        if(Rank[i]){
            int j = SA[Rank[i] - 1];
            while(str[i+c] == str[j+c])
                c++;
        }
        lcp[Rank[i]] = c;
        if(c)
            c--;
    }
}

void reset(){
    SetTo(SA, 0);
    SetTo(group, 0);
    SetTo(sorGroup, 0);
    SetTo(lcp, 0);
    SetTo(Rank, 0);
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int tc;
    scanf("%d\n", &tc);
    while(tc--)
    {
        scanf("%s", str);

        buildSuffixArray();
        build_LCP();

        int n = 1 + strlen(str);
        int mx = 0;
        for(int i=0;i<n;i++)
            mx = max(mx, lcp[i]);

        if(!mx){
            puts("No repetitions found!");
            reset();
            continue;
        }
        int idx = -1;
        for(int i=0;i<n;i++){
            if(lcp[i] == mx){
                idx = SA[i];
                break;
            }
        }

        int ans = 0;
        for(int i=0;i<(n-1);i++){
            int t = strncmp(str + idx, str + i, mx);
            ans += (t == 0);
        }
        for(int i=0;i<mx;i++)
            putchar(str[idx+i]);
        printf(" %d\n", ans);
        reset();
    }
    return 0;
}
