#include <bits/stdc++.h>
using namespace std;

#define sz(v)               ((int)v.size())
#define ll                  long long
#define all(v)              (v.begin()) , (v.end())
#define rall(v)             (v.rbegin()) , (v.rend())

struct node{
    int val;
    string s;
    node(int v, string u){
        val = v, s = u;
    }
    bool operator < (const node &n)const{
        if(sz(s) != sz(n.s))
            return sz(s) < sz(n.s);
        return s < n.s;
    }
};

vector <node> V;

void Parse(string s)
{
    for(int i=0;i < sz(s); i++){
        if(s[i] == ','){
            s[i] = ' ';
            break;
        }
    }
    int val;
    string u;
    istringstream iss(s);

    iss >> val >> u;
    V.push_back(node(val, u));
}

void parseInput(string s)
{
    for(int i=0;i < sz(s); i++){
        if(s[i] == '(' && s[i + 1] == ')')
            break;

        int j;
        if(s[i] == '('){
            for(j = i + 1; s[j] != ')'; j++);
            string tmp = s.substr(i + 1, j - i - 1);
            Parse(tmp);
            i = j;
        }

    }
}

void solve()
{
    map <string, bool> vis;
    sort(all(V));

    if(V[0].s != ""){
        puts("not complete");
        return;
    }
    vis[""] = 1;
    bool ok = 1;

    for(int i = 1;i < sz(V) ; i++){
        if(V[i].val == V[i - 1].val)
            ok = 0;
        if(vis[V[i].s])
            ok = 0;

        string u = V[i].s.substr(0, sz(V[i].s) - 1);
        //cout << V[i].s << " " << u << endl;
        if(!vis[u])
            ok = 0;

        vis[V[i].s] = 1;
    }

    if(!ok){
        puts("not complete");
        return;
    }

    for(int i = 0;i < sz(V) ; i++){
        printf("%d", V[i].val);
        if(i != sz(V) - 1)
            printf(" ");
    }
    printf("\n");
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    string s;
    bool done = 0;
    while(getline(cin, s))
    {
        parseInput(s);
        if(s[sz(s) - 2] == '(' && s[sz(s) - 1] == ')'){
            solve();
            V.clear();
        }
    }


    return 0;
}
