#include <cstdio>
#include <iostream>
using namespace std;
struct node{
    int x,y,father,son;
}tree[250010];
int n,m,k,sx,sy,tot;
char temp;
int map[550][550];
void dfs(int x,int y,int father){
    if(k<=0)return;
    int id=tot++;
    tree[id].x=x;
    tree[id].y=y;
    tree[id].father=father;
    tree[id].son=0;
    map[x][y]=-1;
    if(map[x+1][y]==1&&k>0)
        tree[id].son++,dfs(x+1,y,id);
    if(map[x-1][y]==1&&k>0)
        tree[id].son++,dfs(x-1,y,id);
    if(map[x][y+1]==1&&k>0)
        tree[id].son++,dfs(x,y+1,id);
    if(map[x][y-1]==1&&k>0)
        tree[id].son++,dfs(x,y-1,id);
    if(tree[id].son==0&&k>0)
        map[x][y]=2,tree[father].son--,k--;
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>temp;
            if(temp=='#')map[i][j]=0;
            if(temp=='.')map[i][j]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(map[i][j]==1){sx=i;sy=j;break;}
    dfs(sx,sy,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(map[i][j]==0)cout<<'#';
            else if(map[i][j]==-1)cout<<'.';
            else if(map[i][j]==2)cout<<'X';
            else if(map[i][j]==1)cout<<'.';
        cout<<endl;
    }
    return 0;
}
