#include <cstdio>
#include <iostream>
#include <algorithm>
#define type int//看情况修改返回类型
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}

const int maxn=330;
const int maxm=50050;
struct road{
    int u,v,w;
    bool operator<(const road &r)const{
        return w<r.w;
    }
}city[maxm];
int n,m,ans,dad[maxn],k;
int find(int x){
    return dad[x]==x?x:dad[x]=find(dad[x]);
}
void unionn(int u,int v){
    int fu = find(u);
    int fv = find(v);
    dad[fu]=fv;
}
int main(){
    n=read(),m=read();
    for(int i = 1; i <= m; i++){
        city[i].u = read();
        city[i].v = read();
        city[i].w = read();
    }
    for(int i = 1; i <= n; i++)
        dad[i] = i;
    sort( city+1 , city+1+m );
    for(int i = 1; i <= m; i++){
        int u = city[i].u;
        int v = city[i].v;
        if(find(u)!=find(v)){
            unionn(u,v);
            k++;
            ans = max(ans,city[i].w);
        }
        if( k == n-1 )break;
    }
    printf("%d %d",k,ans);
    return 0;
}
