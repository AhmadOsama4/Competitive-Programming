
#include <bits/stdc++.h>
using namespace std;

string grid[105];
int dx[] = { -1 , -1 , 0 , 0 , 1 , 1 };
int dy[] = { 0  , 1  , 1, -1 , 0 ,-1 };
char f[] = { '(' , ')' };
int n,m;

void block(int r,int c)
{
    if(r>= n || r<0 || c>=m || c<0)
        return;
    if(grid[r][c]=='.' || grid[r][c] == 'B')
        return;
    grid[r][c] = 'B';
    for(int i=0;i<6;i++){
        block(r+dx[i],c+dy[i]);
    }
}

void filler(int r,int c,int ch){

    if(r>=n || r<0 || c>=m || c<0)
        return;
    if(grid[r][c]=='.')
        return;
    if(grid[r][c] == f[ch^1]){
        block(r,c);
        return;
    }
    if(grid[r][c] == '*'){
            grid[r][c] = f[ch];
            for(int i=0;i<6;i++){
                filler(r+dx[i],c+dy[i],ch^1);
            }
    }
}
int main ()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    while(n && m)
    {
        for(int i=0;i<n;i++)
            cin>>grid[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== 'I'){
                    grid[i][j]='*';
                    filler(i,j,0);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='*')
                    grid[i][j] = 'F';
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        cin>>n>>m;
    }

    return 0;
}
