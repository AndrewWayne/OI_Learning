//思路：寻找最小环，运用tarjan
#include<iostream>
#include<vector>
#include<cstdio>
#include<stack>
using namespace std;
const int maxn=2e5;
vector<int>v[maxn+1];
stack<int>stk;
int n,ans=1e9,dcnt,tim,cnt,dfn[maxn+1],low[maxn+1],belong[maxn+1],size[maxn+1];
bool instack[maxn+1];
void dfs(int u)
{
    dfn[u]=low[u]=++tim;
    instack[u]=1;
    stk.push(u);
    for(int i=0;i<v[u].size();i++)
    {
        int w=v[u][i];
        if(!dfn[w])
        {
            dfs(w);
            low[u]=min(low[u],low[w]);
        }
        else if(instack[w])
            low[u]=min(low[u],dfn[w]);
    }
    int tmp;
    if(dfn[u]==low[u])
    {
        dcnt++;
        while(1)
        {
            tmp=stk.top();
            stk.pop();
            instack[tmp]=0;
            belong[tmp]=dcnt;
            if(tmp==u)
                break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        v[i].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i);
    for(int i=1;i<=n;i++)
        size[belong[i]]++;
    for(int i=1;i<=dcnt;i++)
        if(size[i]>1)
            ans=min(ans,size[i]);
    printf("%d\n",ans);
    return 0;
}
