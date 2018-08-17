#include <cstdio>
#include <iostream>
#define maxn 110
#define max(a,b) a>b?a:b
using namespace std;
int map[maxn][maxn],f[maxn][maxn],r,c,ans;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
inline int dfs(int x,int y){
    if(x<1||y<1||x>r||y>c)
        return 0;
    if(f[x][y]!=1)  return f[x][y];
    int b=0;
    for(int i=0;i<4;i++)
        if(map[x][y]>map[x+dx[i]][y+dy[i]])
            b=max(b,dfs(x+dx[i],y+dy[i])+1);
    f[x][y]=max(f[x][y],b);
    return f[x][y];
}
int main(){
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&map[i][j]),f[i][j]=1;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            ans=max(ans,dfs(i,j));
    printf("%d",ans);
    return 0;
}
