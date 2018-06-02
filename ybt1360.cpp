#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=220;
int n,m,a,b;
int q[maxn],vis[maxn];//'q' is for storing the step that can walk,and 'vis' is to store how many steps.
int main()
{
    queue<int>p;
    scanf("%d%d%d",&n,&a,&b);
    vis[a]=1;
    for(int i=1;i<=n;i++)scanf("%d",&q[i]);
    p.push(a);
    while(!p.empty())
    {
        int now=p.front(),l=now-q[now],r=now+q[now];
        p.pop();
        if(l>=1&&!vis[l]){p.push(l);vis[l]=vis[now]+1;}
        if(r<=n&&!vis[r]){p.push(r);vis[r]=vis[now]+1;}
        if(l==b||r==b)break;
    }
    printf("%d\n",vis[b]-1);
    return 0;
}
