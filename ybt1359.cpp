#include <iostream>
#include <cstdio>
using namespace std;
int map[11][11];//[y][x]
int k=0;
int rightdown[2]={0,0};
int leftup[2]={10,10};//[0] is y,[1]is x
int s=0;
void left(int x,int y);
void right(int x,int y);
void up(int x,int y);
void down(int x,int y);
void bfs(int x,int y){//fill the 0 that can reach with 1 on map.
    map[y][x]=1;
    left(x,y);
    right(x,y);
    up(x,y);
    down(x,y);
}
void left(int x,int y){
    if(--x>=leftup[1]&&!map[y][x])
        bfs(x,y);
}
void right(int x,int y){
    if(++x<=rightdown[1]&&!map[y][x])
        bfs(x,y);
}
void up(int x,int y){
    if(--y>=leftup[0]&&!map[y][x])
        bfs(x,y);
}
void down(int x,int y){
    if(++y<=rightdown[0]&&!map[y][x])
        bfs(x,y);
}
int main(){
    for(int i=1;i<=10;i++)//i is y,j is x
        for(int j=1;j<=10;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==1){
                leftup[0]=leftup[0]<i?leftup[0]:i;
                leftup[1]=leftup[1]<j?leftup[1]:j;
                rightdown[0]=rightdown[0]>i?rightdown[0]:i;
                rightdown[1]=rightdown[1]>j?rightdown[1]:j;
            }
        }
    for(int i=leftup[1];i<=rightdown[1];i++)//the fisrt row. i is x.
        if(map[leftup[0]][i]==0)
            bfs(i,leftup[0]);
    for(int i=leftup[0]+1;i<=rightdown[0]-1;i++){//the 2nd->(n-1)th row. i is y.
        if(map[i][leftup[1]]==0)
            bfs(leftup[1],i);
        if(map[i][rightdown[1]]==0)
            bfs(rightdown[1], i);
    }
    for(int i=leftup[1];i<=rightdown[1];i++)//the last row. i is x.
        if(map[rightdown[0]][i]==0)
            bfs(i,rightdown[0]);
    for(int i=leftup[0];i<=rightdown[0];i++)
        for(int j=leftup[1];j<=rightdown[1];j++)
            if(map[i][j]==0)s++;
    printf("%d",s);
}
