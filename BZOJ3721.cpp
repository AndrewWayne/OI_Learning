#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
#define inf 2000000000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int mn1[1000005],mn2[1000005],mx1[1000005],mx2[1000005];
int n,m,K;
int a[1000005];
ll sum[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	mn1[0]=mn2[0]=inf;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		mn1[i]=mn1[i-1];
		mn2[i]=mn2[i-1];
		if(a[i]&1)mn1[i]=min(mn1[i],a[i]);
		else mn2[i]=min(mn2[i],a[i]);
	}
	for(int i=n;i;i--)
	{
		mx1[i]=mx1[i+1];
		mx2[i]=mx2[i+1];
		if(a[i]&1)mx1[i]=max(mx1[i],a[i]);
		else mx2[i]=max(mx2[i],a[i]);
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int K=read();
		if(sum[K]&1)printf("%lld\n",sum[K]);
		else
		{
			ll ans=-1;
			if(mn1[K]!=inf&&mx2[K+1])ans=max(ans,sum[K]-mn1[K]+mx2[K+1]);
			if(mn2[K]!=inf&&mx1[K+1])ans=max(ans,sum[K]-mn2[K]+mx1[K+1]);
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
