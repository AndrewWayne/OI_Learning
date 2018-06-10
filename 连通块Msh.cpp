#include <iostream>
#define MAXN 101
#define MAXE 1001
using namespace std;
struct E{
	int to,nxt,dis;
} e[MAXE];
int top[MAXN],num_edge=0,n,m,u,v,d;
int ans=0,maxn=0,weight=0; 
bool visited[MAXN];
void add_edge(int,int,int);
void dfs(int);
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		add_edge(u,v,d);
		add_edge(v,u,d);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
		weight=0;
		dfs(i);
		ans++,maxn=max(maxn,weight);
		}
	}
	printf("%d %d",ans,maxn);
}
void add_edge(int from,int to,int dis){
	e[++num_edge].nxt=top[from];
	e[num_edge].to=to;
	e[num_edge].dis=dis;
	top[from]=num_edge;
}
void dfs(int k){
	weight++;
	for(int i=top[k];i!=0;i=e[i].nxt)
		if(!visited[e[i].to])
			dfs(e[i].to);
}
