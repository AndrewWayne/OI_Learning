#include<cstdio>
#include<algorithm>
using namespace std;

int m,n,map[55][55],f[55][55][55][55];

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++)
	    scanf("%d",&map[i][j]);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)
	    for(int g=1;g<=m;g++)
	      for(int h=1;h<=n;h++)
	      if(i!=g||j!=h||(i+j+g+h==m*2+n*2))
	      f[i][j][g][h]=max(max(f[i-1][j][g-1][h],f[i-1][j][g][h-1]),max(f[i][j-1][g-1][h],f[i][j-1][g][h-1]))+map[i][j]+map[g][h];
	printf("%d",f[m][n][m][n]);
	return 0;
}
