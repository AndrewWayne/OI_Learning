// luogu-judger-enable-o2
#include <cstdio>
#include <bitset>
#include <algorithm>
#define MAX(a,b) a>b?a:b
using namespace std;
const int maxn=2018;
int a[30],n,m,ans;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
void dfs(int sum, int id, bitset<maxn> ret){//sum为当前取用砝码数，id为当前用了第几个砝码，ret用于存储当前可以称出哪些质量
    if(sum == n - m + 1){
        ans = MAX(ans,(int)ret.count());
        return;
    }
    for(register int i = id; i <= sum + m; i++)
        dfs(sum + 1, i + 1, ret << a[i] | ret);//合并原来（所有能称出的重量+a[i]）和（所有原来能称出的质量）这两个集合（Orz pantw）
}
int main(){
    n=read(),m=read();
    for(int i = 1; i <= n; ++i)
        a[i]=read();
    bitset<maxn> b;
    b[0] = 1;
    dfs( 1, 1, b );
    printf("%d\n", --ans);//由于不包括0所以-1
    return 0;
}
/*
//60分爆搜
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n,m,a[30],b[30],ans,half,top;
map < int , int > weight[5000];
void dfs1(register int sum,register int m,int id){
    weight[id][sum] = 520;
    if( m == half+1) return;//half=3/4n
    dfs1( sum , m+1 , id );
    if( b[m] )return;
    dfs1( sum + a[m] , m + 1 , id );
}
bool dfs2(register int sum,register int m,register int want, int id){
    bool ret=false;
    if(weight[id][ want-sum ] == 520)
        return true;
    if( m == n+1) return false;
    ret |= dfs2( sum , m+1 ,want ,id);
    if( b[m] ) return ret;
    if( sum + a[m] <= want)
        ret |= dfs2( sum + a[m] , m+1 ,want ,id);
    return ret;
}
int sum(int id){
    register int result=0,maxn=0;
    dfs1( 0, 1 , id );
    for(register int i = 1; i <= n; i++)
        if(!b[i])
            maxn += a[i];
    for(register int i = 1; i <= maxn; i++)
        if(dfs2(0, half+1 ,i , id))result++;
    return result;
}
void solution(register int num,register int id){
    if(num == m){
        ans = max( ans , sum( ++top ) );
        return;
    }
    for(register int i = id; i <= n ; i++)
        if( !b[i] ){
            b[i] = true;
            solution( num + 1 , i );
            b[i] = false;
        }
}
int main(){
    cin>> n >> m;
    half=n*3/4;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solution( 0 , 1 );//复杂度应该是O(C(n,m)*(2^(3/4*n)+2^(1/4*n)*sum(ai)))
    cout << ans;
    return 0;
}
*/
