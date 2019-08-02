#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[100010],b[100010];
int n,m,ans=0,k=1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%llu",a+i);
	a[n+1]=10000000000;
	for(int i=1;i<=m;i++)
		scanf("%llu",b+i);
	for(int i=n-1;i>=1;i--)
		if(a[i]>=a[i+1]) a[i]=a[i+1]-1;
	sort(b+1, b+m+1);
	for(int i = m-1; i >= 1; i--)
		if(b[i] >= b[i+1]) b[i] = b[i+1]-1;
	for(int i = 0; i <= n; i++){
		int x = a[i+1] - a[i] - 1;
		while(x > 0 && k <= m){
			if(a[i]<b[k]){
				ans++;
				x--;
			}
			k++;
		}
	}
	printf("%d",ans);
}
