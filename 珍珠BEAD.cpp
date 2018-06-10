#include <iostream>
#include <cstdio>
#include <string.h>
#define HALFN 2/n;
using namespace std;
int edge[100][100];
bool visited[100];
struct Pearl{
  int n_big,n_small,in_d,out_d;
} pearl[100];
int n,m;
int x,y;
void add_edge(int,int);
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&x,&y);
    edge[x][y]=1;
    pearl[x].in_d++;
    pearl[y].out_d++;
  }
}
void dfs(int i){
  int amount=0;
  visited[i]=true;
  for(int j=1;amount<=pearl[i].out_d;j++){
    if(edge[i][j]&&!visited[j])
      
  }

}
