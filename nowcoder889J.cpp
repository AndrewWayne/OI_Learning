/*
 * Author: xiaohei_AWM
 * Date: 8.15
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const ll M=1000000000;
int n,m,i,j,l[300005],r[300005],k;
ll d,ans,s;
struct str{
    int d,x;
}a[100005];
bool cmp(str a,str b)
{
    return a.x<b.x;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&l[i],&r[i]);
        l[i]*=2;
        r[i]*=2;
        a[++k]=(str){1,l[i]+1};
        a[++k]=(str){-2,(1ll*l[i]+r[i])/2+1};
        a[++k]=(str){1,r[i]+1};
    }
    sort(a+1,a+1+k,cmp);
    for(i=1;i<=k;i++)
    {
        for(j=i;a[j].x==a[i].x;j++)
            d+=a[j].d;
        s+=(a[j+1].x-a[j].x)*d;
        ans=max(ans,s);
        i=j;
    }
    cout<<ans;
}
