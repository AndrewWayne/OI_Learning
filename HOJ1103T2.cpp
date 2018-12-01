//爆搜60分
#pragma GCC optimize(3)//O3开关
#include <iostream>
#include <cstring>
#define type int//看情况修改返回类型
#define min(a,b) a<b?a:b
using namespace std;
const int MAXN = 20;
struct Edge{
    int to, nxt;
}edge[500];
int n, m, ans, half, head[MAXN], u, v, nume, finish;
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
void add(int u, int v){
    edge[++nume].nxt = head[u];
    edge[nume].to = v;
    head[u] = nume;
}
int dfs(int x, int stat){//stat为访问此点x之前的状态,sum为当前访问点数(算上x)
    int val = 0;
    if(stat & (1 << x)) return 1;
    stat |= (1 << x);
    for(int p = head[x]; p; p = edge[p].nxt)
        if(!(stat & (1 << edge[p].to)))
            val++;

    if(val == 0)
        return 1;

    for(int p = head[x]; p; p = edge[p].nxt)
        if(!(stat & (1 << edge[p].to)))
            val *= dfs(edge[p].to, stat);

    return val;
}
int main(){
    n = read(), m = read();
    finish = (1 << (n+1)) - 1;
    for(int i = 0; i < m; i++)
        u = read(), v = read(), add(u, v), add(v, u);
    for(int i = 1; i <= n; i++)
        add(0, i);

    for(int i = 1; i <= n; i++)
        ans += dfs(i, 0);

    cout<< ans;

    return 0;
}
