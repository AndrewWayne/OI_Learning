#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxx(a,b) a>b?a:b
using namespace std;
int n,m,ans=0,top=0;
int u,v,c,dad[310];
struct road{
	int u,v,c;
} roads[90000];
bool cmp(road u,road v){
	return u.c<v.c;
}
int find(int u){
	if(dad[u]!=u)dad[u]=find(dad[u]);
	return dad[u];
}
void unionn(int a,int b){
	int ka=find(a);
	int kb=find(b);
	if(ka!=kb)dad[ka]=kb;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>c;
		roads[++top].u=u;
		roads[top].v=v;
		roads[top].c=c;
	}
	sort(roads+1,roads+1+m,cmp);
	for(int i=1;i<=n;i++)
		dad[i]=i;
	top=0;
	for(int i=1;i<=m;i++){
		if(find(roads[i].u)!=find(roads[i].v)){
			unionn(roads[i].u,roads[i].v);
			ans=maxx(ans,roads[i].c);
			top++;
			if(top==n-1)break;
		}
	}
	printf("%d %d",n-1,ans);
}
