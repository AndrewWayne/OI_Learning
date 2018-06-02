#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main(){
	int ans=0;
	int f[1000][1000];
	memset(f,0,sizeof(f));
	int med[101];
	int time[101];
	int t=0,m=0;
	scanf("%d%d",&t,&m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d",&time[i],&med[i]);
	for(int i=1;i<=m;++i){
		for (int j = t; j >= 0; --j)
		{
			f[i][j]=f[i-1][j];
			if(j>=time[i])f[i][j]=max(f[i][j],f[i-1][j-time[i]]+med[i]);
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=0;j<=t;++j)
			ans=max(ans,f[i][j]);
	printf("%d",ans);
}