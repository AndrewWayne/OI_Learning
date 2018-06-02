#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
struct node
{
    int x,y,f;
};
node q[10001];
bool b[101][101],ma[101][101],arrive;
int n,m,h,t,x,y,ans;
int x1,y1,x2,y2;
void push(int x, int y)
{
    if (b[x][y]) return;
    b[x][y]=true;
    t++;
    q[t].x=x;  q[t].y=y;  q[t].f=q[h].f+1;
    if (x==x2&&y==y2) cout<<q[t].f-1,arrive=true;
}
void bfs()
{
    memset(b,0,sizeof(b));
    h=t=0;
    push(x1,y1);
    do
    {
        h++;
        x=q[h].x;  y=q[h].y;
        for(int i=x;i<=n+1&&(!ma[i][y]||(i==x2&&y==y2));i++)//right
            push(i,y);
        for(int i=x;i>=  0&&(!ma[i][y]||(i==x2&&y==y2));i--)//left
            push(i,y);
        for(int i=y;i<=n+1&&(!ma[x][i]||(x==x2&&i==y2));i++)//down
            push(x,i);
        for(int i=y;i>=  0&&(!ma[x][i]||(x==x2&&i==y2));i--)//up
            push(x,i);
    }
    while(h<=t&&!arrive);
}

char temp;

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%c",&temp),ma[i][j]=temp=='X';
    while(~scanf("%d%d%d%d",&y1,&x1,&y2,&x2)){
        bfs();
        if(!arrive)
            printf("0");
    }
}
