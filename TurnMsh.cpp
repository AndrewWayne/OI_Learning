#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
     int x,y,f;
};
node q[10001];
bool b[101][101],ma[101][101];
int n,m,h,t,x,y,ans;
int x1,y1,x2,y2;
void push(int x, int y)
{
    if (b[x][y]) return;
    b[x][y]=true;
    t++;
    q[t].x=x;  q[t].y=y;  q[t].f=q[h].f+1;
    if (x==x2&&y==y2) cout<<q[t].f-1, exit(0);
}
void bfs()
{
    h=t=0;
    push(x1,y1);
    do
    {
    	h++;
    	x=q[h].x;  y=q[h].y;
    	for(int i=x;i<=n&&!ma[i][y];i++)//right
    		push(i,y);
    	for(int i=x;i>=1&&!ma[i][y];i--)//left
    		push(i,y);
    	for(int i=y;i<=n&&!ma[x][i];i++)//down
    		push(x,i);
    	for(int i=y;i>=1&&!ma[x][i];i--)//up
    		push(x,i);
    }
    while(h<=t);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",ma[i][j]);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	bfs();
	printf("-1");
}
