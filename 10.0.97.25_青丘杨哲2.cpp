#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,ma[25][25],dp[25][25];
int main()
{
	cin>>n>>m>>a>>b;
	ma[a][b]=1;
	ma[a-1][b-2]=1,ma[a-1][b+2]=1,ma[a+1][b-2]=1,ma[a+1][b+2]=1;
	ma[a-2][b-1]=1,ma[a-2][b+1]=1,ma[a+2][b-1]=1,ma[a+2][b+1]=1;
	dp[1][0]=1;
	for (int i=1;i<=n+1;i++)
	{
		for (int j=1;j<=m+1;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			if (ma[i-1][j-1])
			{
				dp[i][j]=0;
			} 
		}
	}
	cout<<dp[n+1][m+1];
	return 0;
}
