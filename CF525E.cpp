#include <cstdio>
#include <iostream>
#include <map>
#pragma GCC optimize(2)
#define ll long long
using namespace std;
map<ll,ll> ma[30];//一个左半边的所有数的和到能出这个和的方案数的映射，供合并
ll fact[21]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};//只需要预处理出够用的阶乘就够了，由于S<=10^16在long long以内，所以我们可以直接打表写1-20的阶乘，显然够了,(告诉我们一个有效剪枝太大的根本不用判要不要加阶乘)
const int maxn=30;
int r,k,half,lim;
ll S,a[maxn],ans;//划重点开long long
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read()
{
    char ch=nc();long long sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}//感谢chen_zhe和World_Best牛顿提供的快读帮助
void dfs1(ll sum,int t,int m){
    if(m==half+1){
        ma[t][sum]++;
        return;
    }
    dfs1(sum,t,m+1);
    if(a[m]+sum<=S)
        dfs1(sum+a[m],t,m+1);
    if(a[m]<=lim&&fact[a[m]]+sum<=S&&t<k)
        dfs1(sum+fact[a[m]],t+1,m+1);
}
void dfs2(ll sum,int t,int m){
    if(m==half){//在第二个方向狂扫到half的时候进行合并操作
        for(int i=0;i<=t;i++)
            if(ma[i].count(sum))ans+=ma[i][sum];//就这一步if卡进去了2s的时限！
        return;}
    if(a[m]<=lim&&sum-fact[a[m]]>=0&&t>=1)
        dfs2(sum-fact[a[m]],t-1,m-1);
    if(a[m]<=sum)
        dfs2(sum-a[m],t,m-1);
    dfs2(sum,t,m-1);
}
int main(){
    lim=19;
    r=read();
    k=read();
    S=read();
    for(int i=1;i<=lim;i++)
        if(fact[i+1]>S)
        {lim=i;break;}
    for(int i=1;i<=r;i++)
        a[i]=read();
    if(r==1){
        if(a[1]==S)ans++;
        if(a[1]<=lim&&fact[a[1]]==S)ans++;
        cout<<ans;
        return 0;
    }
    ans=0;
    half=r>>1;
    for(int i=0;i<=r;i++)
        ma[i].clear();
    dfs1(0,0,1);
    dfs2(S,k,r);
    cout<<ans;
    return 0;
}
