#include<bits/stdc++.h>
using namespace std;
#define MAXN 10001
#define MAXM 16
int n,k;
int exist[MAXN];
int que[MAXN];
int a[MAXM],b[MAXM];
int main(void)
{
	cin>>n;
	cin>>k;
	for (int i=0;i<k;i++)
		scanf("%d%d",&a[i],&b[i]);
	exist[n]=1;
	que[1]=n;
	int tail=1;
	int head=0;
	while (tail>=head)
	{
		int x=que[++head];
		int y=x,mod=1;
		while (x>0)
		{
			int tmp=x%10;
			x/=10;
			for (int i=0;i<k;i++)
				if (a[i]==tmp)
				{
					int p=y+(b[i]-tmp)*mod; 
					if (exist[p]==0)
					{
						exist[p]=1;
						que[++tail]=p;
					}
				}
			mod*=10;
		}
	}
	cout<<tail;
	return 0;
}


