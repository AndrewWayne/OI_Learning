#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n;
double dis[20][20];
double x[20],y[20];
double ans=987654321.0;
bool visited[20];
void dfs(int sum,int at,double len){
  if(visited[at])return;
  if(len>ans)return;
  if(sum==n){ans=len;return;}
  visited[at]=true;
  for(int i=1;i<=n;i++)
    dfs(sum+1,i,len+dis[at][i]);
  visited[at]=false;
}
int main(){
  cin>>n;
  if(n==0){cout<<"0.00";return 0;}
  for(int i=1;i<=n;i++){
    cin>>x[i]>>y[i];
    for(int j=1;j<=i;j++)
      dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])),dis[j][i]=dis[i][j];
  }
  dfs(0,0,0);
  printf("%.2f",ans);
  return 0;
}
