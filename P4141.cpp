/*
 * Author: xiaohei_AWM
 * Date: 6.1
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
const int maxn = 2e3 + 10;
int n, m, w[maxn], f[maxn][maxn], ans[maxn][maxn];
/*
int main(){
    n = read(), m = read();
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        w[i] = read();
        for(int j = m; j >= w[i]; j--){
            f[j] += f[j - w[i]];
            while(f[j] >= 10) f[j] -= 10;
        }
    }
    for(int i = 1; i <= n; i++){
        memcpy(ans[i], f, sizeof(f));
        for(int j = w[i]; j <= m; j++){
            ans[i][j] -= ans[i][j - w[i]];
            while(ans[i][j] < 0)
                ans[i][j] += 10;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%d", ans[i][j] % 10);
        printf("\n");
    }
    return 0;
}
/*/
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        w[i] = read();
    for(int i = 1; i <= n; i++){ // 枚举不取哪个
        f[0][i] = 1;
        for(int j = 1; j <= n; j++){ // 阶段划分
            if(j == i) continue;
            for(int k = m; k >= w[j]; k--){
                f[k][i] += f[k - w[j]][i];
                f[k][i] %= 10;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%d", f[j][i]%10);
        printf("\n");
    }
}
//*/
