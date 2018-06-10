#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Edge
{
	int next;
	int b; 
}bian[20001];
bool bo[1001];
int head[1001],t,top,n,m,x,y,anan,an[1001];
void add(int from,int to) 
{
	t++;
	bian[t].next=head[from];
	bian[t].b=to;
	head[from]=t;
}
void dfs(int dian)
{
	if (bo[dian])
	return;
	anan++;
	bo[dian]=1;
	int p=head[dian];
	while (p!=0)
	{
		dfs(bian[p].b);
		p=bian[p].next;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=n;i++)
	{
		if (!bo[i])
		{
			anan=0;
			dfs(i);
			top++;
			an[top]=anan;
		}
	}
	printf("%d\n",top);
	for (int i=1;i<=top;i++)
	printf("%d ",an[i]);
	return 0;
}
