#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

const int N = 200005;

int cnt[N];
vector <int> nodes[N];

int main ()
{
    //freopen("input.txt","r",stdin);
    int h;
    scanf("%d", &h);
    bool perfect = 1;

    for(int i = 0; i <= h; i++){
        scanf("%d", cnt + i);
        if(i && cnt[i] > 1 && cnt[i - 1] > 1)
            perfect = 0;
    }

    if(perfect){
        puts("perfect");
        return 0;
    }
    puts("ambiguous");
    int idx = 1;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j < cnt[i]; j++)
            nodes[i].push_back(idx++);
    }
    printf("0 ");
    for(int i = 1; i <= h; i++){
        for(int j = 0; j < cnt[i]; j++)
            printf("%d ", nodes[i - 1][0]);
    }
    puts("");

    printf("0 ");
    for(int i = 1; i <= h; i++){
        if(cnt[i] > 1 && cnt[i - 1] > 1){
            printf("%d ", nodes[i - 1][0]);
            for(int j = 1; j < cnt[i]; j++)
                printf("%d ", nodes[i - 1][1]);
        }
        else{
            for(int j = 0; j < cnt[i]; j++)
                printf("%d ", nodes[i - 1][0]);
        }
    }
    puts("");
    return 0;
}
