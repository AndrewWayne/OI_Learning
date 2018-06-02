#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define rep(i,l,r) for(i=l;i<=r;i++)
#define read scanf
#define print printf

const int maxn=1001;
const int maxm=10000001;

struct xOy{
    int x,y;
};

char graph[maxn][maxn];
int record[maxm],id[maxn][maxn];
xOy q[maxm];
int front,tail;
int n,m;//size of the board ; question numbers
int datax,datay;

void bfs(int x,int y,int index){
    front=tail=1;
    tail=2;
    q[1]=(struct xOy){x,y};
    xOy head;
    while(front!=tail){
        head=q[front];
        ++front;
        if(id[head.x][head.y])continue;
        id[head.x][head.y]=index;
        record[index]++;
        if(head.x-1>=1 && graph[head.x-1][head.y]!=graph[head.x][head.y])
          q[tail++]=(struct xOy){head.x-1,head.y};
        if(head.y-1>=1 && graph[head.x][head.y-1]!=graph[head.x][head.y])
          q[tail++]=(struct xOy){head.x,head.y-1};
        if(head.x+1<=n && graph[head.x+1][head.y]!=graph[head.x][head.y])
          q[tail++]=(struct xOy){head.x+1,head.y};
        if(head.y+1<=n && graph[head.x][head.y+1]!=graph[head.x][head.y])
          q[tail++]=(struct xOy){head.x,head.y+1};
    }
}

int main(){
    read("%d%d",&n,&m);
    int i,j,index=1;
    rep(i,1,n)
      rep(j,1,n)
        cin>>graph[i][j];
    rep(i,1,n)
      rep(j,1,n)
      {
        bfs(i,j,index);
        if(record[index])index++;
      }
    rep(i,1,m){
        read("%d%d",&datax,&datay);
        print("%d\n",record[id[datax][datay]]);
    }
    return 0;
}
