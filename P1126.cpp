#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int n,m,h,t,xr,yr,d,ans,x1,y1,x2,y2;
bool bo[51][51][4],ma[51][51],arrive=false;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct node{
    int x,y,di,f;
} robots[2501];
//direction:0-North 1-East 2-South 3-West
int left(){
    return d-1>=0?d-1:3;
}
int right(){
    return d+1<=3?d+1:0;
}
void push(int,int,int,int);
void bfs();
int temp;
char start_d;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&temp),ma[i][j]=!temp;
    arrive=false;
    scanf("%d%d%d%d %c",&x1,&y1,&x2,&y2,&start_d);
    if(start_d=='N')d=0;
    if(start_d=='E')d=1;
    if(start_d=='S')d=2;
    if(start_d=='W')d=3;
    bfs();
    if(!arrive)
        printf("-1");
    return 0;
}
void bfs(){
    h=t=0;
    push(x1,y1,d,0);
    while(!arrive&&h<=t){
        h++;
        xr=robots[h].x;yr=robots[h].y;d=robots[h].di;
        if(xr+dx[d]<=n&&xr+dx[d]>=1&&yr+dy[d]<=m&&yr+dy[d]>=1)        push(xr+dx[d],  yr+dy[d],  d,1);
        if(xr+2*dx[d]<=n&&xr+2*dx[d]>=1&&yr+2*dy[d]<=m&&yr+2*dy[d]>=1)push(xr+2*dx[d],yr+2*dy[d],d,2);
        if(xr+3*dx[d]<=n&&xr+3*dx[d]>=1&&yr+3*dy[d]<=m&&yr+3*dy[d]>=1)push(xr+3*dx[d],yr+3*dy[d],d,3);
        push(xr,yr,left(),0);
        push(xr,yr,right(),0);
    }
}
bool able;
void push(int xs,int ys,int ds,int step){
    able=true;
    for(int i=0;i<step;i++){
        able&=ma[xs-dx[ds]*i][ys-dy[ds]*i];
        able&=ma[xs-dx[ds]*i+1][ys-dy[ds]*i];
        able&=ma[xs-dx[ds]*i][ys-dy[ds]*i+1];
        able&=ma[xs-dx[ds]*i+1][ys-dy[ds]*i+1];
    }
    if(able&&!bo[xs][ys][ds]){
        bo[xs][ys][ds]=true;
        t++;
        robots[t].x=xs;robots[t].y=ys;robots[t].di=ds;robots[t].f=robots[h].f+1;
        if(xs==x2&&ys==y2)printf("%d", robots[t].f-1),arrive=1;
    }
}
