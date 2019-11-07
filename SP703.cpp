*
 * Author: xiaohei_AWM
 * Date:
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
const int maxn = 1010;
const int maxl = 202;
int Ts, l, n, c[maxl][maxl], sum, re[maxn], f[maxn][maxl][maxl];//f[i][x][y]表示状态完成第i个请求，一个人在re[i]位置，另外两个一个在x 一个在y
int main(){
    Ts = read();
    while(Ts--){
        l = read(), n = read();
        memset(c, 0, sizeof(c));
        sum = 0x7f7f7f7f;
        for(int i = 1; i <= l; i++)
            for(int j = 1; j <= l; j++)
                c[i][j] = read();
        for(int i = 1; i <= n; i++)
            re[i] = read();
        re[0] = 1;
        memset(f, 0x3f, sizeof(f));
        f[0][2][3] = 0;
        f[0][3][2] = 0;
        for(int i = 1; i <= n; i++)
            for(int x = 1; x <= l; x++){
                for(int y = 1; y <= l; y++){
                    if(x == y) continue;
                    if(re[i] != x && re[i] != y && x != y)
                        f[i][x][y] = min(f[i][x][y], f[i-1][x][y] + c[re[i-1]][re[i]]);
                    if(re[i] != re[i-1] && re[i] != y && re[i-1] != y)
                        f[i][re[i-1]][y] = min(f[i][re[i-1]][y], f[i-1][x][y] + c[x][re[i]]);
                    if(re[i] != x && re[i] != re[i-1] && re[i-1] != x)
                        f[i][x][re[i-1]] = min(f[i][x][re[i-1]], f[i-1][x][y] + c[y][re[i]]);
                }
            }
        for(int x = 1; x <= l; x++)
            for(int y = 1; y <= l; y++)
                sum = min(f[n][x][y], sum);
        printf("%d\n", sum);
    }
    return 0;
}
