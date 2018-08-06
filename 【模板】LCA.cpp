//垃圾倍增，回头重写Tarjan
#include <cstdio>
#include <cmath>
using namespace std;
struct Edge{
    int to,nxt;
}e[2*500001];
int depth[500001],lg[500001],dad[500001][22],head[500001];//depth--L dad--f(用了倍增所以不留Fa)
int tot;
void add(int x,int y) //邻接表存树
{
    e[++tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot;
}
void dfs(int to,int now)//建树
{
    depth[to]=depth[now]+1;
    dad[to][0]=now;
    for(int i=1;(1<<i)<=depth[to];i++)
      dad[to][i]=dad[dad[to][i-1]][i-1];//2^(i-1)*2^(i-1)=2^i 所以这样转移
    for(int i=head[to];i;i=e[i].nxt)
      if(e[i].to!=now)
        dfs(e[i].to,to);
}
int lca(int x,int y)
{
    if(depth[x]<depth[y])
        swap(x,y);
    while(depth[x]>depth[y])
        x=dad[x][lg[depth[x]-depth[y]]-1];
    if(x==y)
        return x;
    for(int k=lg[depth[x]];k>=0;k--)
        if(dad[x][k]!=dad[y][k])
            x=dad[x][k],y=dad[y][k];
    return dad[x][0];
}
int n,m,s;
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    dfs(s,0);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));//离线算法
    }
    return 0;
}
