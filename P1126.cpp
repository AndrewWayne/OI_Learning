#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int n,m,h,t,xr,yr,d,ans,x1,y1,x2,y2;
bool bo[51][51],ma[51][51];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct node{
  int x,y,di,f;
} robots[2501];
//direction:0-North 1-East 2-South 3-West
void left(){
  d=d-1>=0?d-1:3;
}
void right(){
  d=d+1<=3?d+1:0;
}
void push(int,int,int);
void bfs();
int temp;
char start_d;
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      scanf("%d",&temp),ma[i][j]=!temp;
  scanf("%d%d%d%d%c",&x1,&y1,&x2,&y2,&start_d);
  if(start_d=='N')d=0;
  if(start_d=='E')d=1;
  if(start_d=='S')d=2;
  if(start_d=='W')d=3;
  bfs();
  printf("-1");
}
void bfs(){
  h=t=0;
  push(x1,y1,d);
  do{
    xr=q[h].x;yr=q[h].y;d=q[h].d;
    if(xr+dx[d])
  }while(h<=t);
}
