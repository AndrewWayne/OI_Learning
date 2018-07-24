#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,ans,h,t;
bool ma[101][101],flag;
struct node{
    int x,y,f;
} queue[10010];
int startx,starty,endx,endy;
void push(int iX,int iY,int iF){
    if(iX==endx&&iY==endy){
        flag=true;
        cout<<iF-1;
        return;
    }
    queue[++t].x=iX;
    queue[t].y=iY;
    queue[t].f=iF;
    ma[iX][iY]=false;
}
node pop(){
    return queue[++h];
}
int main(){
    cin>>n;
    char temp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>temp;
            if(temp=='.')
                ma[i][j]=true;
            if(temp=='A'){
                startx=i;
                starty=j;
                ma[i][j]=true;
            }
            if(temp=='B'){
                endx=i;
                endy=j;
                ma[i][j]=true;
            }
        }//cuntu
    h=t=0;
    push(startx,starty,0);
    while(h<=t){
        node nTemp=pop();
        int x=nTemp.x;
        int y=nTemp.y;
        int f=nTemp.f;
        for(int i=1;x+i<=n&&ma[x+i][y];i++)
            push(x+i,y,f+1);
        for(int i=1;x-i>=1&&ma[x-i][y];i++)
            push(x-i,y,f+1);
        for(int i=1;y+i>=1&&ma[x][y+i];i++)
            push(x,y+i,f+1);
        for(int i=1;y-i>=1&&ma[x][y-i];i++)
            push(x,y-i,f+1);
        if(flag)
            return 0;
    }
    cout<<-1;
}
