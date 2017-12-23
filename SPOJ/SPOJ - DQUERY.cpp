#include <bits/stdc++.h>
using namespace std;

#define sz(v)       ((int)v.size())
#define all(v)      (v.begin()),(v.end())
#define rall(v)     (v.rbegin()),(v.rend())
#define ll          long long

int n,x[30005],prev[1000005];
vector <int> tree[120000];

void merge_sort(int node, int L, int R)
{
    int i = 0 , j = 0;
    while(i < sz(tree[L]) && j < sz(tree[R])){
        if(tree[L][i] < tree[R][j]){
            tree[node].push_back(tree[L][i]);
            i++;
        }else{
            tree[node].push_back(tree[R][j]);
            j++;
        }
    }

    while(i < sz(tree[L])){
        tree[node].push_back(tree[L][i]);
        i++;
    }
    while(j < sz(tree[R])){
        tree[node].push_back(tree[R][j]);
        j++;
    }

}

void build(int node,int L,int R)
{
    if(L == R){
        tree[node].push_back(x[L]);
        return ;
    }

    build(node<<1,  L, (L+R)>>1 );
    build((node<<1)+1,((L+R)>>1)+1,R);


    merge_sort(node, node<<1 , (node<<1)+1);
}

int query(int node,int L,int R,int st,int en)
{
    if(L>en || R<st)
        return 0;

    if(L >= st && R <= en){
        return upper_bound(all(tree[node]) , st-1) - tree[node].begin();
    }
    return query(node<<1 , L, (L+R)>>1 ,st ,en) + query( (node<<1)+1 , ((L+R)>>1)+1 , R , st , en);
}

int main ()
{
    //freopen("input.txt","r",stdin);
    int a,b,q;
    scanf("%d",&n);
    memset(prev, -1,sizeof(prev));
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        x[i] = prev[a];
        prev[a] = i;
    }
    build(1,0,n-1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",query(1,0,n-1,a-1,b-1) );
    }
    return 0;
}
