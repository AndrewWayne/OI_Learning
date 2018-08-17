#include <cstdio>
#include <iostream>
using namespace std;
int c[20],n,sum;
int pre[20];
bool visited[20];
void dfs(int x,int tot,int id){
  if(visited[x])return;
  if(id==n){
    if(tot==n)
      for(int i=1;i<=n;i++)
        printf("%d ",pre[i]);
    else
      return;
  }
  tot+=c[id]*x;
  for(int i=1;i<=n&&i*c[id+1]+tot<=sum;i++)
    dfs(i,tot,id+1);
  visited[x]=false;
}
int main(){
  cin>>n;
  c[1]=1;
  for(int i=1;i<=n;i++)
    for(int j=i;j>=1;j--)
      c[j]=c[j]+c[j-1];
  cin>>sum;
  for(int i=1;i<=n&&i<=sum;i++){
    visited[i]=true;
    dfs(i,0,1);
    visited[i]=false;
  }
  return 0;
}
