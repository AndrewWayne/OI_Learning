//Date:
//#include<bits/stdc++.h>
#include<cstdio>
//#include<>
//using namespace std;
const int maxn=1001,maxm=100001;
struct Edge{
	int next;
	int to;
}edge[maxm];
int head[maxn],num_edge,n,m,u,v,d;
bool visited[maxn];
void add_edge(int from,int to){
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
void dfs(int i){
	printf("%d ",i);
	visited[i]=true;
	for(int j=head[i];j!=0;j=edge[j].next)
		if(!visited[edge[j].to])
			dfs(edge[j].to);
}
int main(){
	num_edge=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
	    scanf("%d %d",&u,&v);
	    add_edge(u,v);
	    add_edge(v,u);
	}
	dfs(1);
	return 0;
}
