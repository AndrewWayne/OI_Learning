#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
    char c;
    ll f=1,x=0;
    do
    {
        c=getchar();
        if(c=='-')f=-1;
    }while(c<'0'||c>'9');
    do
    {
        x=x*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return f*x;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 3000011
ll n;
struct Segment_Tree
{
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    struct node
    {
        ll mr,sum;
        node()
        {
            mr=sum=0;
        }
    }t[MAXN<<2|1];
    void pushup(un num)
    {
        rt.mr = max(tr.mr,tr.sum+tl.mr);
        rt.sum = tl.sum+tr.sum;
    }
    void build(ll *a,un l=1,un r=n,un num=1)
    {
        if(l==r)
        {
            rt.mr=rt.sum=a[l];
            return;
        }
        un mid=(l+r)>>1;
        build(a,l,mid,num<<1);build(a,mid+1,r,num<<1|1);
        pushup(num);
    }
    node query(un ql,un qr,un l=1,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)return rt;
        un mid=(l+r)>>1;
        if(qr<=mid)return query(ql,qr,l,mid,num<<1);
        if(ql>mid)return query(ql,qr,mid+1,r,num<<1|1);
        node fl=query(ql,qr,l,mid,num<<1),fr=query(ql,qr,mid+1,r,num<<1|1),now;
        now.mr=max(fr.mr,fr.sum+fl.mr);
        now.sum=fl.sum+fr.sum;
        return now;
    }
}sgt;
ll a[MAXN],b[MAXN];
ll s[MAXN],top=0;
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=1;i<=n;++i)b[i]=read();
    sgt.build(b);
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        while(top>0&&a[s[top]]>=a[i])--top;
        ans=max(ans,sgt.query(s[top]+1,i).mr*a[i]);
        s[++top]=i;
    }
    printf("%lld",ans);
    return 0;
}
