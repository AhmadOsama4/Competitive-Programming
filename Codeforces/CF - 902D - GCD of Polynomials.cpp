#include <bits/stdc++.h>
using namespace std;

#define sz(v)        ((int)v.size())
#define ll           long long
#define all(v)       (v.begin()) , (v.end())
#define rall(v)      (v.rbegin()) , (v.rend())

int mx;
bool f;
vector <int> add(const vector <int> &x, const vector <int> &y)
{
    vector <int> ret(152, 0);
    for(int i = 0; i <= mx + 1; i++){
        ret[i] = x[i] + y[i];
        if(abs(ret[i]) > 1)
            f = 1;
    }
    if(ret[mx + 1] == -1)
        f = 1;
    return ret;
}
vector <int> sub(const vector <int> &x, const vector <int> &y)
{
    vector <int> ret(152, 0);
    for(int i = 0; i <= mx + 1; i++){
        ret[i] = x[i] - y[i];
        if(abs(ret[i]) > 1)
            f = 1;
    }
    if(ret[mx + 1] == -1)
        f = 1;
    return ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    vector <int> A, B;
    A = vector <int> (152, 0);
    B = vector <int> (152, 0);

    A[0] = 1;
    mx = 0;
    vector <int> tmp;
    for(int i = 0; i < n; i++){
        tmp = A;
        for(int j = mx + 1; j > 0 ; j--){
            A[j] = A[j - 1];
        }
        A[0] = 0;
        f = 0;
        vector <int> V = add(A, B);
        if(f)
            A = sub(A, B);
        else
            A = V;

        B = tmp;
        mx++;
    }

    printf("%d\n", mx);
    for(int i = 0; i <= mx; i++)
        printf("%d ", A[i]);
    puts("");

    printf("%d\n", mx - 1);
    for(int i = 0; i < mx; i++)
        printf("%d ", B[i]);
    puts("");
    return 0;
}
