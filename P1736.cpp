#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 2550
#define MAX(a,b) a>b?a:b
#define 解释 这代码是超级水的暴力
int n,m,ans=0,len,x1,y1,x2,y2;
bool map[MAXN][MAXN];
bool judge(int,int,int,int);
void search(int,int,int);
int main(void){
    int fish;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&fish),map[i][j]=fish==1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(map[i][j]){
                x1=i;
                y1=j;
                for(int k=0;k<=3;k++){
                    len=1;
                    search(x1,y1,k);
                    if(judge(x1,y1,x2,y2))ans=MAX(len,ans);
                }
            }
        }
    printf("%d\n",ans);
    return 0;
}

void search(int x,int y,int di){
    switch (di) {
        case 0:
            if(x-1<1||y-1<1)return;
            if(map[x-1][y-1]){len++;x2=x-1;y2=y-1;search(x-1,y-1,0);}
            break;
        case 1:
            if(x-1<1||y+1>m)return;
            if(map[x-1][y+1]){len++;x2=x-1;y2=y+1;search(x-1,y+1,1);}
            break;
        case 2:
            if(x+1>n||y+1>m)return;
            if(map[x+1][y+1]){len++;x2=x+1;y2=y+1;search(x+1,y+1,2);}
            break;
        case 3:
            if(x+1>n||y-1<1)return;
            if(map[x+1][y-1]){len++;x2=x+1;y2=y-1;search(x+1,y-1,3);}
            break;
    }
}
bool judge(int _x1,int _y1,int _x2,int _y2){
    if(_x1<_x2&&_y1<_y2)
        for(int i=_x1;i<=_x2;i++)
            for(int j=_y1;j<=_y2;j++)
                if(map[i][j]&&i-_x1!=j-_y1)return false;

    if(_x1<_x2&&_y1>_y2)
        for(int i=_x1;i<=_x2;i++)
            for(int j=_y1;j>=_y2;j--)
                if(map[i][j]&&i-_x1!=_y1-j)return false;

    if(_x1>_x2&&_y1<_y2)
        for(int i=_x1;i>=_x2;i--)
            for(int j=_y1;j<=_y2;j++)
                if(map[i][j]&&_x1-i!=j-_y1)return false;

    if(_x1>_x2&&_y1>_y2)
        for(int i=_x1;i>=_x2;i--)
            for(int j=_y1;j>=_y2;j--)
                if(map[i][j]&&_x1-i!=_y1-j)return false;

    return true;
}
