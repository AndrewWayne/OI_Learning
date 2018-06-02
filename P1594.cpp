#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int w[1001],s[1001],sum_w[1001],mins[1001][1001];
int n,wmax,len;
int i,j,k;
int main(){
	scanf("%d%d%d",&wmax,&len,&n);
	double f[n+1];
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		scanf("%d%d",&w[i],&s[i]);
		sum_w[i]=sum_w[i-1]+w[i];
		mins[i][i]=s[i];
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)//j is on the right
			mins[i][j]=min(mins[i][j-1],s[j]);
	for(i=1;i<=n;i++){//devide into i parts
		f[i]=(double)len/s[i];
		for(j=i-1;j>=1;j--){//j is on the left
			if(sum_w[i]-sum_w[j-1]<=wmax)f[i]=min(f[i],f[j-1]+(double)len/mins[j][i]);
			else break;
		}
	}
	printf("%.1lf\n",60*f[n]);
}
