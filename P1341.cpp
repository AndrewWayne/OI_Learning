#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char a,b,ans[60];
const int maxe=3000,maxp=255;
struct Edge{
  int next;
  int to;
  bool gone;
} edge[maxe];
int l=0x7f,r=-1;
int n,head[maxp],num_edge,du[],jishu=0,jidian[2],top=0,visited[maxp];
void add(int,int);
void dfs(int);
void esort(int start){
  int p=head[start];
  int maxn=0;
  struct E{
    int index,to;
  } e[60];
  bool cmp(E x,E y)
  {
  return x.to<y.to;
  }
  for(int i=p;i!=0;i=edge[i].next){
    e[++maxn].index=i;
    e[maxn].to=edge[i].to;
  }
  sort(e[1],e[maxn],cmp);
  head[start]=e[1].index;
  for(int i=1;i<=maxn;i++)
    edge[e[i].index].next=e[i+1].index;
}
int main(){
  memset(du,0,sizeof(du));
  scanf("%d\n",&n);
  for(int i=1;i<=n;i++)
    scanf("%c%c\n",&a,&b),add(a-0,b-0),add(b-0,a-0);
  for(int i=l;i<=r;i++)
    esort(i);
  for(int i=l;i<=r;i++){
    if(du[i]&1)jidian[jishu]=i,jishu++;
  }
  if(jishu!=2&&jishu!=0)printf("No Solution"),return 0;
  if(jishu==2)dfs(min(jidian[0],jidian[1]);
  dfs(l);
}
void add(int from,int to){
  l=min(l,from);
  r=max(r,to);
  edge[++num_edge].next=head[from];
  edge[num_edge].to=to;
  head[from]=num_edge;
  du[from]++1;
}
void dfs(int start){
  if(top==n+1){
    for(int i=1;i<=top;i++)cout<<(char)ans[i];
    exit(0);
  }
  for(int i=head[start];i!=0;i=edge[i].next)
    if(!edge[i].gone)
      edge[i].gone=true,dfs(edge[i].to);
  ans[++top]=start;
}
