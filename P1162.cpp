#include <cstdio>
#include <iostream>
using namespace std;
int map[32][32],bo[32][32];
int h,t,n,x,y;
struct node{
    int x,y;
} q[901];
void bfs(int,int);
void push(int,int);
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&map[i][j]);
    for(int i=0;i<=n+1;i++){
        bfs(i,0);
        bfs(i,n+1);
        bfs(0,i);
        bfs(n+1,i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(bo[i][j])
                printf("%d ",map[i][j]);
            else if(map[i][j]==1)
                printf("1 ");
            else
                printf("2 ");
        }
        printf("\n");
    }
    return 0;

}
void push(int a,int b){
    if(bo[a][b])return;
    bo[a][b]=1;
    q[t].x=a;q[t++].y=b;
}
void bfs(int ax,int ay){
    push(ax,ay);
    h=0;t=1;
    do{
        h++;
        x=q[h].x,y=q[h].y;
        if(x+1<=n+1&&map[x+1][y]!=1)push(x+1,y);
        if(x-1>=0&&map[x-1][y]!=1)push(x-1,y);
        if(y+1<=n+1&&map[x][y+1]!=1)push(x,y+1);
        if(y-1>=0&&map[x][y-1]!=1)push(x,y-1);
    }while(h<=t);
}
