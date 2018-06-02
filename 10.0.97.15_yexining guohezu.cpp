#include<iostream>
using namespace std;
int n,m,i,j,k,a,b,map[22][22]={0},f[22][22]={0};
long long int s=0;
int main()
{
	cin>>n>>m>>a>>b;
	map[a][b]=1;
	if(a-2>=0&&b-1>=0)map[a-2][b-1]=1;
	if(a-1>=0&&b-2>=0)map[a-1][b-2]=1;
	if(a+2<=n&&b-1>=0)map[a+2][b-1]=1;
	if(a+1<=n&&b-2>=0)map[a+1][b-2]=1;
	if(a-2>=0&&b+1<=m)map[a-2][b+1]=1;
	if(a-1>=0&&b+2<=m)map[a-1][b+2]=1;
	if(a+2<=n&&b+1<=m)map[a+2][b+1]=1;
	if(a+1<=n&&b+2<=m)map[a+1][b+2]=1;
	for(i=0;i<=n;i++)
	  for(j=0;j<=m;j++)
	  {
	  	if(i==0&&j==0)f[0][0]=1;
	  	else
		if(map[i][j]==0)
	    f[i][j]=f[i-1][j]+f[i][j-1];
	  };   
	cout<<f[n][m];
	      
}
