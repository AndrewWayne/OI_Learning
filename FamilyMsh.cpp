#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int n,k,index,h,t,a,b,r[101][101],q[101],bo[101],s;
int ans,maxn;
void push(int ind){
	if(bo[ind])return;
	bo[ind]=1;
	t++;
	q[t]=ind;
}
void bfs(int ind){
	h=t=0;
	push(ind);
	do{
		h++;
		s=q[h];
		for(int i=1;i<=n;i++)
			if(r[ind][i])push(i);
	}while(h<=t);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&a,&b),r[a][b]=r[b][a]=1;
	for(int i=1;i<=n;i++){
		if(!bo[i])ans++,bfs(i);
		maxn=max(maxn,t);	
	}
	printf("%d %d",ans,maxn);
}
