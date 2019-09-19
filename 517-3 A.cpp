/*
 * Author: xiaohei_AWM
 * Date: 9.13
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
const int maxn = 110;
int t, r, c, h, v, cnt, sum[maxn][maxn], H[maxn], V[maxn];
char mp[maxn][maxn];
int calc(int x, int y){
    int res = 0;
    res = sum[H[x+1]][V[y+1]] - sum[H[x+1]][V[y]] - sum[H[x]][V[y+1]] + sum[H[x]][V[y]];
    return res;
}
int main(){
    scanf("%d", &t);
    for(int kkk = 1; kkk <= t; kkk++){
        memset(sum, 0, sizeof(sum));
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        memset(mp, 0, sizeof(mp));
        cnt = 0;
        cin >> r >> c >> h >> v;
        //cerr << r << " " << c << " " << h << " " << v << endl;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++){
                cin >> mp[i][j];
                if(mp[i][j] == '@')
                    cnt++;
                    //cerr << i << " " << j << " " << sum[i][j] << endl;
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (mp[i][j] == '@');
            }
        //cerr << (h+1)*(v+1) << endl;
        if(cnt % ((h+1)*(v+1)) != 0){
            printf("Case #%d: IMPOSSIBLE\n", kkk);
            continue;
        }
        if(cnt == 0){
            printf("Case #%d: POSSIBLE\n", kkk);
            continue;
        }
        int numh = cnt/(h+1);
        int numv = cnt/(v+1);
        int val = cnt / (h+1) / (v+1);
        int s = 0, top = 0;
        for(int i = 1; i <= r; i++){
            s += sum[i][c] - sum[i-1][c];
            if(s == numh) s = 0, H[++top] = i;
        }
        if(top != h+1){
            printf("Case #%d: IMPOSSIBLE\n", kkk);
            continue;
        }
        s = top = 0;
        for(int i = 1; i <= c; i++){
            s += sum[r][i] - sum[r][i-1];
            if(s == numv) s = 0, V[++top] = i;
        }
        if(top != v+1){
            printf("Case #%d: IMPOSSIBLE\n", kkk);
            continue;
        }
        for(int i = 0; i <= h; i++)
            for(int j = 0; j <= v; j++)//看每个块对不对
                if(calc(i, j) != val){
                    printf("Case #%d: IMPOSSIBLE\n", kkk);
                    goto endss;
                }
        printf("Case #%d: POSSIBLE\n", kkk);
        endss: cnt = 0;
    }
    return 0;
}
