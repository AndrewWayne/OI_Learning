#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int num[15];
int sum(int from,int to){
	int i;
	int ans=0;
	for(i=from;i<=to;i++){
		ans+=num[i];
	}
}
int main(){
	int i,j,k;
	int n,r;
	int dp[16][16];
	scanf("%d%d",&n,&r);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(k=1;k<=r;k++)
		for(i=k;i<n;i++)
			for(j=k-1;j<i;j++)
				dp[i][k]=max(dp[i][k],dp[j][k-1]*sum(j,i));

	printf("%d",dp[n-1][r]);
}
