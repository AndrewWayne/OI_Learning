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
int head[maxn],num_edge,n,m,u,v,d,t,h;
int p[maxm];
bool visited[maxn];
void add_edge(int from,int to){
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
void push(int i){
	if(visited[i])return;
	visited[i]=true;
	p[++t]=i;
	printf("%d ",i);
}
void bfs(){
	h=t=0;
	push(1);
	do{
		h++;
		int k=p[h];
		for(int j=head[1];j!=0;j=edge[j].next)
			push(edge[j].to);
	}while (h<=t);
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
	bfs();
	return 0;
}
