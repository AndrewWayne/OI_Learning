#include<bits/stdc++.h>
using namespace std;
int i,n,k,j;
int x,y,t,h,maxn;
int q[1000],ans;
bool a[1000][1000],b[1000];
void push(int x)
{    
	if(!b[x])
	{
		b[x]=true;
		t++;
		q[t]=x;
	}
}
void bfs(int x)
{  
	h=t=0;
	push(x);
	do
	{
		h++;
		for(int j=1;j<=n;j++)
		if(a[q[h]][j])push(j);
	}
	while(h<=t);
	maxn=max(maxn,t);
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x][y]=a[y][x]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i]){ans++;bfs(i);}
	}
    cout<<ans<<" "<<maxn;
}
