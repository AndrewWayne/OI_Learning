#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int n,m,x,u,d,y,numans,S;
char ans[233334];
int anss[233334];
struct node{
    int x,u,d
}wall[100010];
int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    cin>>x>>d>>u;
    wall[i].x=x;
    wall[i].u=u;
    wall[x].d=d;
  }
  wall[m+1].x=n;
  wall[m+1].d=0;
  wall[m+1].u=n-1;
  if(m==0){
    printf("%d\n",2*(n-1));
    printf("2\n");
    printf("U %d\n",n-1);
    printf("R %d",n-1);
    return 0;
  }
  if(m==1){
    printf("%d\n",2*(n-1));
    printf("2\n");
    if(u==n){
      printf("R %d\n",n-1);
      printf("U %d\n",n-1);
    }else{
      printf("U %d\n",n-1);
      printf("R %d\n",n-1);
    }
    return 0;
  }
  x=1,y=1;
  for(int i=1;i<=m+1;i++){
    if(wall[i].x>x){
      ans[++numans]='R';
      anss[numans]=wall[i].x-x;
      S+=wall[i].x-x
      x=wall[i].x;
    }
    if(wall[i].d=0){
      if(y>wall[i].u){
        anss[numans]+=wall[i+1].x-x,x=wall[i+1].x;
        S+=wall[i+1].x-x;
        continue;
      }
      else{
        ans[++numans]='U';
        anss[numans]=wall[i].u-y+1;
        y=wall[i].u+1;
        S+=wall[i].u-y+1;
        continue;
      }
    }else{
      if(y<wall[i].d){
          anss[numans]+=wall[i+1].x-x;
          x=wall[i+1].x;
          S+=wall[i+1].x-x;
          continue;
      }
      else{
        ans[++numans]='D';
        ans[numans]=y-wall[i].d+1;
        y=wall[i].d+1;
        S+=y-wall[i].d+1;
        continue;
      }
    }
    printf("%d\n%d\n",S,numans);
    for(int i=1;i<=numans;i++){
      printf("%c %d\n",ans[i],anss[i]);
    }
  }
  return 0;
}
