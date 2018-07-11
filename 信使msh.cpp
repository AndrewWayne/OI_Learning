#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Edge{
	int nxt,to,dis;
} edge[10001];
int top[101],num_e,n,m,a,b,t,dis[101],ans;
bool visited[101];
void add(int from,int to,int dis){
	edge[++num_e].nxt=top[from];
	edge[num_e].to=to;
	edge[num_e].dis=dis;
}
void relax(int point){
	int p=top[point];
	while(p!=0){
		if(visited[edge[p].to]){
			dis[edge[p].to]=min(dis[point]+edge[p].dis,dis[edge[p].to];
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>t;
		add(a,b,t);
		add(b,a,t);
	}
	
	for(int i=1;i<=n;i++)
		max(ans,dis[i]);
}
