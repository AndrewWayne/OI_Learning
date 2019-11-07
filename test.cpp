//Code by King!
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int MX=1061109567,M=10010;
int n,m,k,p,l,h,num,ans=MX;
int f[M][1010],gao[M],di[M],sh[M],ji[M];
bool oo,ys[M];
int main()
{
//	freopen("testdata (1).in","r",stdin);freopen("ty.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&sh[i],&ji[i]);
		gao[i]=m+sh[i]+1;
	}
	gao[0]=m+1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&p,&l,&h);
		di[p]=l;
		gao[p]=h;
		ys[p]=1;
	}
	memset(f,63,sizeof(f));
	for(int i=di[0]+1;i<gao[0];i++)
	{
		f[0][i]=0;
	}
	for(int hm,i=1;i<=n;i++)
	{
		oo=0;
		for(int nw,j=di[i-1]+1+sh[i];j<gao[i];j++)
		{
			nw=min(j,m);
			if(j-sh[i]>di[i-1])
			{
				f[i][nw]=min(f[i][nw],f[i-1][j-sh[i]]+1);
				f[i][nw]=min(f[i][nw],f[i][j-sh[i]]+1);
				if(f[i][nw]!=MX&&(!oo))
				{
					oo=1;
					if(ys[i]) num++;
				}
			}
		}
		for(int j=1;j<=di[i];j++)
		{
			f[i][j]=MX;
		}
		hm=min(m+1,gao[i-1])-ji[i];
		hm=min(hm,gao[i]);
		for(int j=di[i]+1;j<hm;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j+ji[i]]);
			if(f[i][j]!=MX&&(!oo))
			{
				oo=1;
				if(ys[i]) num++;
			}
		}
		if(!oo)
		{
			printf("0\n%d\n",num);
			break;
		}
	}
	if(oo)
	{
		int hm=min(m+1,gao[n]);
		for(int i=di[n]+1;i<hm;i++)
		{
			ans=min(ans,f[n][i]);
		}
		printf("1\n%d\n",ans);
	}
//	fclose(stdin);fclose(stdout);
	return 0;
}
