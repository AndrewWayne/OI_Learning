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
int head[1001],t,n,m,x,y,z,q[1001];
void add(int from,int to) 
{
	t++;
	bian[t].next=head[from];
	bian[t].b=to;
	head[from]=t;
}
void push(int x)
{
    if (bo[x]) return;
    bo[x]=true;
    t++;
    q[t]=x;
}
void bfs()
{
    int h=t=0;
    int dian;
    push(1);
    do
    {
    	h++;
    	dian=q[h];
    	printf("%d ",dian);
	    int p=head[dian];
    	while (p!=0)
    	{
	    	push(bian[p].b);
	    	p=bian[p].next;
	    }
    }
    while(h<t);
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
	bfs();
	return 0;
}
