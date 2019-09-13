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
int t, r, c, h, v, cnt, sum[maxn][maxn];
char mp[maxn][maxn];
int main(){
    scanf("%d", &t);
    for(int kkk = 1; kkk <= t; kkk++){
        cin >> r >> c >> h >> v;
        //cerr << r << " " << c << " " << h << " " << v << endl;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++){
                cin >> mp[i][j];
                if(mp[i][j] == '@'){
                    cnt++;
                    //cerr << i << " " << j << " " << sum[i][j] << endl;
                }
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (mp[i][j] == '@');
            }
        //cerr << (h+1)*(v+1) << endl;
        if(cnt % ((h+1)*(v+1)) != 0){
            printf("Case #%d: IMPOSSIBLE\n", kkk);
            memset(sum, 0, sizeof(sum));
            cnt = 0;
            continue;
        }
        int val = cnt / (h+1) / (v+1);
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                int v1 = sum[i][j];
                //cerr << i << " " << j << endl;
                //cerr << v1 << endl;
                int v2 = sum[r][c] - sum[i][c] - sum[r][j] + sum[i][j];
                int v3 = sum[r][j] - sum[i][j];
                int v4 = sum[i][c] - sum[i][j];
                //cerr << v1 << " " << v4 << " " << v3 << " " << v2 << endl;
                if(v1 == v2 && v2 == v3 && v3 == v4){
                    //cerr << kkk << endl;
                    printf("Case #%d: POSSIBLE\n", kkk);
                    goto endss;
                }
            }
        }
        printf("Case #%d: IMPOSSIBLE\n", kkk);
        cnt = 0;

        endss: memset(sum, 0, sizeof(sum));
    }
    return 0;
}
