//并查集是世界上最好的算法，不接受质疑
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=5e5+50;
struct Edge{
    int id,to,nxt;
}e[2*maxn],ask[2*maxn];
bool visited[maxn];
int query[maxn],dad[maxn],head[maxn],ans[maxn];
int tot;
void add(int x,int y) //邻接表存树
{
    e[++tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot;
}
void addquery(int x,int y,int i){//存询问
  ask[++tot].to=y;
  ask[tot].nxt=query[x];
  ask[tot].id=i;
  query[x]=tot;
}
int find(int x){
  return x==dad[x]?x:dad[x]=find(dad[x]);
}
void unionn(int u,int v){//u为父节点，v为子节点，为求祖先所以v的子树插到u的根节点上去。。。
//虽然可以按秩合并但是有点麻烦懒得写了╮(￣▽￣"")╭
  int fu=find(u);
  int fv=find(v);
  dad[fv]=fu;//fu是fv的爸爸
}
void dfs(int at)//Tarjan太强了
{
  visited[at]=true;
  for(int i=head[at];i;i=e[i].nxt)
      if(!visited[e[i].to]){
        dfs(e[i].to);
        unionn(at,e[i].to);
      }
  for(int i=query[at];i;i=ask[i].nxt){
    if(visited[ask[i].to])
      ans[ask[i].id]=find(ask[i].to);
  }
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
        add(y,x);//存树
    }
    tot=0;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addquery(x,y,i);
        addquery(y,x,i);
    }
    for(int i=1;i<=n;i++)
      dad[i]=i;
    dfs(s);//s为根结点开始遍历
    for(int i=1;i<=m;i++)
      printf("%d\n",ans[i]);
    return 0;
}
