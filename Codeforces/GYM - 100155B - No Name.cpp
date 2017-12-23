#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

struct node{
    int val, height, freq, sz, lazy;
    char c;
    node *Left, *Right;
    node(){
        val = height = freq = 0;
        Left = Right = NULL;
    }
    node(int v, char _c){
        c = _c;
        val = v, height = 1, freq = 1, lazy = 0;
        Left = Right = NULL;
        sz = 1;
    }
};

int getHeight(node *cur)
{
    if(cur == NULL)
        return 0;
    return cur->height;
}

int getBalance(node *cur)
{
    if (cur == NULL)
        return 0;
    return getHeight(cur->Left) - getHeight(cur->Right);
}

int get_size(node *cur)
{
    if(cur != NULL)
        return cur->sz;
    return 0;
}
node *rightRotate(node *Q)
{
    node *P = Q->Left;
    Q->Left = P->Right;
    P->Right = Q;

    Q->height = 1 + max(getHeight(Q->Left), getHeight(Q->Right));
    Q->sz = Q->freq + get_size(Q->Left) + get_size(Q->Right);
    P->height = 1 + max(getHeight(P->Left), getHeight(P->Right));
    P->sz = P->freq + get_size(P->Left) + get_size(P->Right);

    return P;
}

node *leftRotate(node *P)
{
    node *Q = P->Right;
    P->Right = Q->Left;
    Q->Left = P;

    P->height = 1 + max(getHeight(P->Left), getHeight(P->Right));
    P->sz = 1 + get_size(P->Left) + get_size(P->Right);
    Q->height = 1 + max(getHeight(Q->Left), getHeight(Q->Right));
    Q->sz = 1 + get_size(Q->Left) + get_size(Q->Right);

    return Q;

}

void propagate(node *cur)
{
    if(cur == NULL || cur->lazy == 0)
        return;
    cur->val += cur->lazy;

    if(cur->Left != NULL)
        cur->Left->lazy += cur->lazy;
    if(cur->Right != NULL)
        cur->Right->lazy += cur->lazy;

    cur->lazy = 0;
}
node* Insert(node *cur, int val, char c)
{
    propagate(cur);
    if(cur == NULL){
        node *tmp = new node(val, c);
        return tmp;
    }
    if(cur->val == val){
        cur->freq++;
        return cur;
    }

    if(val < cur->val)
        cur->Left = Insert(cur->Left, val, c);
    else
        cur->Right = Insert(cur->Right, val, c);

    cur->height = 1 + max(getHeight(cur->Left), getHeight(cur->Right));
    cur->sz = cur->freq + get_size(cur->Left) + get_size(cur->Right);

    int balance = getBalance(cur);

    if(balance > 1){ // Left
        if(getBalance(cur->Left) == -1) // Left Right
            cur->Left = leftRotate(cur->Left); // convert to left left

        cur = rightRotate(cur);
    }
    else if(balance < -1){ // Right
        if(getBalance(cur->Right) == 1) // Right left
            cur->Right = rightRotate(cur->Right); // convert to right right

        cur = leftRotate(cur);
    }
    return cur;
}

node *Kth(node *cur, int idx)
{
     propagate(cur);
     if(cur == NULL)
        return cur;

    if(idx <= get_size(cur->Left))
        return Kth(cur->Left, idx);
    else if(idx > get_size(cur->Left) + cur->freq)
        return Kth(cur->Right, idx - get_size(cur->Left)- cur->freq);

    return cur;
}

// increase nodes with values >= v
void update(node *cur, int v, int add)
{
    propagate(cur);
    if(cur == NULL)
        return;
    if(cur->val < v){
        update(cur->Right, v, add);
    }
    else{
        cur->val += add;
        if(cur->Right != NULL)
            cur->Right->lazy += add;

        update(cur->Left, v, add);
    }
}

int main ()
{
    //freopen("input.txt", "r", stdin);
    string str, tmp;
    getline(cin, str);
    int n = sz(str);

    node *root = NULL;

    for(int i = 0; i < n; i++){
        root = Insert(root, i, str[i]);
    }

    getline(cin, str);
    char c;
    int p, l, r;

    while(str.compare("END") != 0){
        istringstream iss(str);
        if(str[0] == 'I'){
            iss >> c >> tmp >> p;
            update(root, p, sz(tmp));
            for(int j = 0; j < sz(tmp); j++){
                root = Insert(root, p + j, tmp[j]);
            }
        }
        else{
            iss >> c >> l >> r;
            for(int i = l; i <= r; i++){
                node *ptr = Kth(root, i + 1);
                putchar(ptr->c);
            }
            puts("");
        }
        getline(cin, str);
    }
    return 0;
}
