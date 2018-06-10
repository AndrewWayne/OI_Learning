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
int head[1001],t,n,m,x,y,z;
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
	printf("%d ",dian);
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
	dfs(1);
	return 0;
}
