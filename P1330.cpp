#include <bits/stdc++.h>
using namespace std;
vector<int> g[10010];
int n,m,c[10010],x,f[10010];
void dfs(int k,int t){
  if(c[k]!=-1&&c[k]!=t)
    printf("Impossible"),exit(0);
  if(c[k]==t)return;
  c[k]=t;
  f[k]=1;
  x++;
  for(int i=0;i<g[k].size();i++)dfs(g[k][i],t^1);
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans=0;
  memset(f,0,sizeof(f));
  for(int i=1;i<=n;i++)
    if(f[i]==0){
      x=0;
      memset(c,-1,sizeof(c));
      dfs(i,0);
      int t=0;
      for(int i=1;i<=n;i++)t+=c[i]==1;
      ans+=min(t,x-t);
    }
    printf("%d",ans);
    return 0;
}
