#include <iostream>
#define MAXN 101
#define MAXE 1001
using namespace std;
struct E{
	int to,nxt,dis;
} e[MAXE];
int top[MAXN],num_edge=0,n,m,u,v,d;
int h,t,q[MAXN],visited[MAXN];
void add_edge(int,int,int);
void bfs(int);
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		add_edge(u,v,d);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	for(int i=1;i<=n;i++)
		printf("%d ",q[i]);
}
void add_edge(int from,int to,int dis){
	e[++num_edge].nxt=top[from];
	e[num_edge].to=to;
	e[num_edge].dis=dis;
	top[from]=num_edge;
}
void bfs(int k){
	int p;
	h=t=0;
	q[++t]=k;
	do{
		h++;
		p=q[h];
		if(visited[p]==0){
			visited[p]=1;
			if(e[top[p]].nxt){
				q[++t]=e[top[p]].to;
			}
		}
	}while(h<=t);
}
