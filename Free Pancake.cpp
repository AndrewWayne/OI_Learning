//pancake
#include <cstdio>
#include <iostream>
using namespace stdin;
int main(){
	int w,h;
	int i,j,k;
	int map[1005][100];
	int f[1005][100]
	int v,pos,time,score;
	int  end,latest;
	scanf("%d%d",&w,&h);
	while(~scanf("%d%d%d",&time,&pos,&v)){
		scanf("%d",&score);
		map[time+h/v][pos]+=score;
		if(time+h/v>latest)latest=time+h/v
	}
	j=w/2+1;
	for(i=1;i<=latest;i++){
		for(j=1;j<=w;j++)
			f[i][j]=max(f[i-1][j],f[i-1[j-1],f[i-1][j-2],f[i-1][j+1],f[i-1][j+2])+map[i][j];
	}
	for(i=1;i<=2;i++)
		if(f[latest][end]<f[latest][i])end=i;
	printf("%d",f[latest][end]);
}
