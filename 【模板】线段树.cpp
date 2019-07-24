```cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 100005

struct tree2
{
	tree2 *lson,*rson;
	ll x,lazyp,lazym=1;
}dizhi[M<<1],*root=&dizhi[0];

int n,m,t=1,a[M];
ll P;

void bulid(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->x=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	tree->lson=&dizhi[t++];
	tree->rson=&dizhi[t++];
	bulid(tree->lson,l,mid);
	bulid(tree->rson,mid+1,r);
	tree->x=(tree->lson->x+tree->rson->x)%P;
}

void pushdown(tree2 *tree,int l,int r)
{


}

void change1(tree2 *tree,int l,int r,int x,int y,int d)
{
	if(x<=l&&y>=r)
	{
		if(tree->lazyp)pushdown(tree,l,r);
		tree->x=(tree->x*d)%P;
		tree->lazym=(tree->lazym*d)%P;
		return ;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)change1(tree->lson,l,mid,x,y,d);
	if(y>mid) change1(tree->rson,mid+1,r,x,y,d);
	tree->x=(tree->lson->x+tree->rson->x)%P;
}

void change2(tree2 *tree,int l,int r,int x,int y,int d)
{
	if(x<=l&&y>=r)
	{
		tree->x=(tree->x+d*(r-l+1))%P;
		tree->lazyp=(tree->lazyp+d)%P;
		return ;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)change2(tree->lson,l,mid,x,y,d);
	if(y>mid) change2(tree->rson,mid+1,r,x,y,d);
	tree->x=(tree->lson->x+tree->rson->x)%P;
}

ll query(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
		return tree->x;
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	ll t1=0,t2=0;
	if(x<=mid)t1=query(tree->lson,l,mid,x,y);
	if(y>mid)t2=query(tree->rson,mid+1,r,x,y);
	return (t1+t2)%P;
}

int main()
{
	n=read(),m=read(),P=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	bulid(root,1,n);
	for(int i=1;i<=m;i++)
	{
		int mode=read();
		if(mode==1)
		{
			int a=read(),b=read(),c=read();
			change1(root,1,n,a,b,c);
		}
		if(mode==2)
		{
			int a=read(),b=read(),c=read();
			change2(root,1,n,a,b,c);
		}
		if(mode==3)
		{
			int a=read(),b=read();
			printf("%lld\n",query(root,1,n,a,b)%P);
		}
	}
	return 0;
}
```
