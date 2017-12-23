#include <bits/stdc++.h>
using namespace std;

int main ()
{
    //freopen("input.txt","r", stdin);
    int n;
    while(scanf("%d",&n) , n)
    {
        stack <int> mystack;
        int c = 1 ,a;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a == c)
                c++;
            else
                mystack.push(a);

            while(!mystack.empty() && mystack.top()==c){
                    c++;
                    mystack.pop();
            }
        }
        bool ok = true;
        while(!mystack.empty()){
            if(mystack.top() != c++){
                ok = false;
                break;
            }
            mystack.pop();
        }
        puts(ok?"yes":"no");
    }
    return 0;
}
