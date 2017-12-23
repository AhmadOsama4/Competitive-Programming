#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

int bits[10];

int main ()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    char c;
    scanf("%d\n", &n);
    memset(bits, -1, sizeof bits);

    for(int i = 0; i < n; i++){
        scanf("%c %d\n", &c, &x);
        if(c == '&'){
            for(int j = 0; j < 10; j++){
                if(x & (1 << j))
                    continue;

                bits[j] = 0;
            }
        }
        else if(c == '|'){
            for(int j = 0; j < 10; j++){
                if(x & (1 << j)){
                    bits[j] = 1;
                }
            }
        }
        else{
            for(int j = 0; j < 10; j++){
                if(x & (1 << j)){
                    if(bits[j] == 0)
                        bits[j] = 1;
                    else if(bits[j] == 1)
                        bits[j] = 0;
                    else if(bits[j] == -1)
                        bits[j] = -2;
                    else
                        bits[j] = -1;
                }
            }
        }
    }

    int and_ans, or_ans, xor_ans;
    and_ans = (1 << 10) - 1;
    or_ans = 0;
    xor_ans = 0;

    for(int i = 0; i < 10; i++){
        if(bits[i] == 1)
            or_ans |= (1 << i);
        else if(bits[i] == 0)
            and_ans &= ~(1 << i);
        else if(bits[i] == -2)
            xor_ans |= (1 << i);
    }

    printf("3\n");
    printf("& %d\n", and_ans);
    printf("| %d\n", or_ans);
    printf("^ %d\n", xor_ans);

    return 0;
}
