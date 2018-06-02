#include <iostream>
#include <cstdio>
using namespace std;
int r[105][105];
int q[105];
int n,m,a,b;
int ans,maxn;
int bo[105];
inline void bfs(int x){
    int w=1;
    q[w]=x;
    bo[x]=1;
    for(int i=1;i<=w;i++){
        int k=q[i];
        for(int j=1;j<=n;j++){
            if(!bo[j]&&r[k][j]&&k!=j){
                q[++w]=j;
                bo[j]=1;
            }
        }
    }
    maxn=max(maxn,w);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        r[a][b]=r[b][a]=1;
    }
    for(int i=1;i<=n;i++)
        if(!bo[i])bfs(i),ans++;
    printf("%d %d\n",ans,maxn);
}
