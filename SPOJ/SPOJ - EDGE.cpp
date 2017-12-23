#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int x[] = { 0,-10,  0, 10};
int y[] = {10,  0,-10,  0};

int main ()
{
    //freopen("input.txt","r",stdin);
    string s;
    while(cin >> s){
        printf("300 420 moveto\n310 420 lineto\n");
        int cur  = 0;
        int cx = 310, cy = 420;

        for(int i = 0; i < sz(s); i++){
            if(s[i] == 'V'){
                cx += x[cur];
                cy += y[cur];
                printf("%d %d lineto\n", cx, cy);
                cur = (cur + 1) % 4;
            }
            else{
                cx -= x[cur];
                cy -= y[cur];
                printf("%d %d lineto\n", cx, cy);
                cur = (cur + 3) % 4;
            }
        }

        printf("stroke\nshowpage\n");
    }
    return 0;
}
