#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm> 
using namespace std;
int min(int a,int b){
	if(a>b)return b;
	else return a;
}
int main(){
	int n,k;
	int i,j;
	int xhd[2003];
	int dp[2003][2003];
	scanf("%d%d",&n,&k);
	for ( i = 1; i <= n; ++i)
		scanf("%d",&xhd[i]);
	for(i=1;i<=k;++i){
		for(j=0;j<=n;j++)
			dp[i][j]=0x3f3f3f3f;
	}
	sort(xhd+1,xhd+1+n);
	for(j=2;j<=n;j++)
		for(i=1;i<=k&&i<=i/2;i++)
			dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+(xhd[j-1]-xhd[j])*(xhd[j-1]-xhd[j]));
	printf("%d\n",dp[k][n]);
}

