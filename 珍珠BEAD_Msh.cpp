#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;
bool f[100][100];
int big[100];
int small[100];
int n,e,a,b;
int main(){
	int ans=0;
	cin>>n>>e;
	int half_n=n/2;
	for(int i=1;i<=e;i++){
		cin>>a>>b;
		f[a][b]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				f[j][k]=f[j][k]||(f[j][i]&&f[i][k]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]){
				big[i]++;
				small[j]++;
			}
	for(int i=1;i<=n;i++)
		if(big[i]>half_n||small[i]>half_n)ans++;
	printf("%d",ans);
}
