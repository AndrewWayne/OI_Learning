#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,k,sum,ans,top=0;//ans记最小生成树权和，sum记图中边权和 
int u,v,m,dad[110];
struct network{
	int u,v,len;
} net[10000];
int find(int u){
	if(dad[u]!=u)dad[u]=find(dad[u]);
	return dad[u];
}
void unionn(int a,int b){
	int ka=find(a);
	int kb=find(b);
	if(ka!=kb)dad[ka]=kb;
}
bool cmp(network x,network y){
	return x.len<y.len;
}
int main(){
	sum=0;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>u>>v>>m;
		net[++top].u=u;
		net[top].v=v;
		net[top].len=m;
		sum+=m;
	}
	for(int i=1;i<=n;i++){
		dad[i]=i;
	}
	sort(net+1,net+1+k,cmp);
	top=0;
	for(int i=1;i<=k;i++){
		if(find(net[i].u)!=find(net[i].v)){
			unionn(net[i].u,net[i].v);
			ans+=net[i].len;
			top++;
			if(top==n-1)break;
		}
	}
	cout<<sum-ans;
	
}
