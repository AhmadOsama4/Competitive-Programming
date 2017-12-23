#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())
#define f                   first
#define s                   second

int score[105][15];

pair < pair <int,int> , pair <int, int> > submissions[1005], res[105];
bool done[105][15];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--){
        memset(score, 0, sizeof score);
        memset(done, 0, sizeof done);

        int N, P, S, t, c, p, r;
        scanf("%d%d%d", &N, &P, &S);
        for(int i = 0; i < S; i++){
            scanf("%d%d%d%d", &t, &c, &p, &r);
            submissions[i] = make_pair( make_pair(t, c) ,  make_pair(p, r) );
        }
        sort(submissions, submissions + S);

        for(int i = 0; i < S; i++){
            t = submissions[i].f.f, c = submissions[i].f.s;
            p = submissions[i].s.f, r = submissions[i].s.s;
            if(done[c][p])
                continue;
            if(r == 1){
                done[c][p] = 1;
                score[c][p] += t;
                continue;
            }
            score[c][p] += 20;
        }
        int prob, pen;
        for(int i = 1; i <= N; i++){
            prob = pen = 0;
            for(int j = 1; j <= P; j++){
                if(done[i][j]){
                    prob++;
                    pen += score[i][j];
                }
            }
            res[i] = make_pair( make_pair(-prob, pen) ,  make_pair(i, 0) );
        }
        sort(res + 1, res + N + 1);

        for(int i = 1; i <= N; i++)
            printf("%d %d %d\n", res[i].s.f, -res[i].f.f, res[i].f.s);
    }
    return 0;
}
