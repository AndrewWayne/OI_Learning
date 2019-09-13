/*
 * Author: xiaohei_AWM
 * Date: 9.12
 * Motto: Face to the weakness, expect for the strength.
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
/*
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}
*/
int n, m;
int a[31][31], b[31][31];
int mult[2][1000100];
const int dx[8] = {1, -1, 1, -1, 0, 0, 1, -1};
const int dy[8] = {1, -1, -1, 1, 1, -1, 0, 0};
inline int h(){
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            res += (a[i][j] != b[i][j]);
    return max(0, res-1);
}
inline bool same(){
    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            res += (a[i][j] != b[i][j]);
    return res == 0;
}
inline bool check(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool dfs(int x, int y, int depth, int idt){
    if(depth <= idt && same()) return true;
    if(depth + h() > idt) return false;
    for(int i = 0; i < 8; i++){
        if(check(x + dx[i], y + dy[i])){
            swap(a[x][y], a[x+dx[i]][y+dy[i]]);
            mult[0][depth+1] = x + dx[i];
            mult[1][depth+1] = y + dy[i];
            if(dfs(x + dx[i], y + dy[i], depth+1, idt)) return true;
            swap(a[x][y], a[x+dx[i]][y+dy[i]]);
        }
    }
    return false;
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            b[i][j] = read();
    for(int idt = 1; idt <= 20; idt++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(a[i][j] != b[i][j]){
                    if(dfs(i, j, 0, idt)){
                        printf("%d\n", idt);
                        printf("%d %d\n", i, j);
                        for(int k = 1; k <= idt; k++)
                            printf("%d %d\n", mult[0][k], mult[1][k]);
                        return 0;
                    }
                }
    }
    printf("-1\n");
    return 0;
}
