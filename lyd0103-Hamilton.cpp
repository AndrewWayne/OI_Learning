//爆搜60分
#pragma GCC optimize(3)//O3开关
#include <iostream>
#include <cstring>
#define type int//看情况修改返回类型
#define min(a,b) a<b?a:b
using namespace std;
int n, dis[22][22], ans = 0x7fffffff;//, left_end, right_end;
int f[ (1<<20) ][ 22 ];//, left_len = 0x7fffffff;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    bool minus=false;
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9')&&ch!='-')ch=nc();
    if(ch=='-')minus=true,ch=nc();//判负没必要的时候记得删，影响效率
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return minus?-sum:sum;
}
int main(){
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    n = read();
    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
            dis[i][j] = read();

    for(int k = 0; k < (1 << n); k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                f[k][i] = min(f[k][i], f[k ^ (1 << i)][j] + dis[j][i]);
            }
        }
    }
    ans = f[(1<<n) - 1][n-1];
    /*left_end = n/2;
    right_end = n - left_end + 1;
    dfs1( 1, 0, 0, 1);
    dfs2( 1 << (n-1), n-1, 0, 1);
    */

    cout<< ans;

    return 0;
}
/*inline void dfs1(int stat, int now, int len, int sum){
    if(len )
    if(sum >= left_end ){
        f[stat][now] = min( f[stat][now], len );
        left_len = min( left_len, f[stat][now]);
        return;
    }
    stat |= (1 << now);
    for(register int i = 1; i < n-1; i++)
        if( i != now && !(1 & (stat >> i)) )
            dfs1( stat , i, len + dis[now][i], sum + 1);
}
inline void dfs2(int stat, int now, int len, int sum){
    if( left_len+len >= ans)
        return;
    if(sum >= right_end ){
        ans = min( f[(1 << n) - stat - 1][now] + len, ans );
        return;
    }

    for(register int i = 1; i < n-1; i++)
        if( i != now && !(1 & (stat >> i)) )
            dfs2( stat | (1 << i), i, len + dis[now][i], sum + 1);
}*/
