#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())
#define SetTo(v, a)  memset(v,a,sizeof(v))

const int MAX = 100100;

char str[MAX], s[MAX];
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

int mp[MAX], mx[MAX], val[MAX], cnt[25];

void reset(){
    SetTo(SA, 0);
    SetTo(group, 0);
    SetTo(sorGroup, 0);
    SetTo(lcp, 0);
    SetTo(Rank, 0);
    SetTo(cnt, 0);
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int tc, n, idx;
    scanf("%d\n", &tc);
    while(tc--)
    {
        scanf("%d\n", &n);
        idx = 0;
        for(int i=0;i<n;i++){
            scanf("%s\n", s);
            for(int j=0, len = strlen(s);j < len;j++){
                str[idx] = s[j];
                mp[idx] = i;
                mx[idx] = len - j;
                idx++;
            }
            str[idx++] = '$';
        }
        if(n == 1){
            printf("%d\n", mx[0]);
            continue;
        }
        str[idx] = '\0';

        buildSuffixArray();
        build_LCP();

        idx++;

        SetTo(val, -1);
        multiset <int> ss;
        int g = 0, j, ans = 0;

        for(j=1;str[SA[j]] == '$';j++);

        for(int i=1;i<idx;i++){
            if(str[SA[i]] == '$')
                continue;
            int ii = SA[i];
            val[i] = min(lcp[i], mx[ii]);
            ss.insert(val[i]);

            cnt[mp[ii]]++;
            if(cnt[mp[ii]] == 1)
                g++;

            while(g == n){
                ii = SA[j];
                cnt[mp[ii]]--;
                ss.erase(ss.find(val[j]));
                if(!cnt[mp[ii]])
                    g--;
                j++;
            }
            ans = max(ans, *ss.begin());
        }
        printf("%d\n", ans);
        reset();
    }
    return 0;
}
