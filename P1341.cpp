#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a,b,ans[60];
const int maxe=3000,maxp=255;
struct Edge{
    int next;
    int to;
    bool gone;
} edge[maxe];
int l=0x7f,r=-1;
int n,head[maxp],num_edge,du[maxp],jishu=0,jidian[2],top=0,visited[maxp];
void add(int,int);
void dfs(int);
struct hello{
    int index,to;
} e[60];
bool cmp(struct hello x,struct hello y)
{
    return x.to<y.to;
}
void esort(int start){
    int p=head[start];
    int maxn=0;
    for(int i=p;i!=0;i=edge[i].next){
        e[++maxn].index=i;
        e[maxn].to=edge[i].to;
    }
    sort(e+1,e+1+maxn,cmp);
    head[start]=e[1].index;
    for(int i=1;i<=maxn;i++)
        edge[e[i].index].next=e[i+1].index;
}
int main(){
    memset(du,0,sizeof(du));
    cin>>n;
    for(int i=1;i<=n+1;i++)
    {
        cin>>a>>b;
        add(a-0,b-0);
        add(b-0,a-0);
    }
    for(int i=l;i<=r;i++)
        esort(i);
    for(int i=l;i<=r;i++){
        if(du[i]&1){jidian[jishu]=i;jishu++;}
    }
    if(jishu!=2&&jishu!=0){printf("No Solution");return 0;}
    if(jishu==2)dfs(min(jidian[0],jidian[1]));
    dfs(l);
}
void add(int from,int to){
    l=min(l,from);
    r=max(r,to);
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
    du[from]++;
}
void dfs(int start){
    if(top==n+1){
        for(int i=1;i<=top;i++)cout<<(char)ans[i];
        exit(0);
    }
    for(int i=head[start];i!=0;i=edge[i].next)
        if(!edge[i].gone)
        {edge[i].gone=true;dfs(edge[i].to);}
    ans[++top]=start;
}
/*
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> v[201];
int l=1e9,r=0;
vector<int> ans;
int du[201]={0};
void dfs(int c)
{
    ans.push_back(c);
    if(ans.size()==n+1)
    {
        for(int i=0;i<ans.size();i++)cout<<(char)ans[i];
        exit(0);
    }
    for(int i=0;i<v[c].size();i++)
    {
        if(v[c][i])
        {
            int t=v[c][i];
            v[c][i]=0;
            for(int j=0;j<v[t].size();j++)
            {
                if(v[t][j]==c)
                {
                    v[t][j]=0;
                    dfs(t);
                    v[t][j]=c;
                    break;
                }
            }
            v[c][i]=t;
        }
    }
    ans.pop_back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char x,y;cin>>x>>y;
        l=min(l,(int)x);r=max(r,(int)x);
        l=min(l,(int)y);r=max(r,(int)y);
        v[(int)x].push_back((int)y);
        v[(int)y].push_back((int)x);
        du[(int)x]++;du[(int)y]++;
    }
    vector<int> odd;
    for(int i=l;i<=r;i++)sort(v[i].begin(),v[i].end());
    for(int i=l;i<=r;i++)if(du[i]%2)odd.push_back(i);
    if(odd.size()==1||odd.size()>2){cout<<"No Solution";return 0;}
    if(odd.size()==2)dfs(min(odd[0],odd[1]));
    dfs(l);
    return 0;
}
*/
