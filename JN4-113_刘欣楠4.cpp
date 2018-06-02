#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,t,ans;
int tt[101][101];
int f[101][101];
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		if(m%c==0)
		tt[m/c+a][b]=d;
		else
		tt[m/c+a+1][b]=d;
		t=max(m/c+a,t);
	}
	for(int i=2;i<=t+1;i++)
		for(int j=1;j<=n;j++)
		{
			if(j>2)
				f[i][j]=max(max(f[i-1][j-2],f[i-1][j-1]),max(max(f[i-1][j],f[i-1][j+1]),f[i-1][j+2]))+tt[i][j];
			else if(j>1)
				f[i][j]=max(max(f[i-1][j],f[i-1][j+1]),max(f[i-1][j+2],f[i-1][j-1]))+tt[i][j];
			else
				f[i][j]=max(max(f[i-1][j],f[i-1][j+1]),f[i-1][j+2])+tt[i][j];				
		}
	for (int i=1; i<=n; i++) ans=max(ans,f[t][i]);
	printf("%d",ans);
	return 0;		
}
