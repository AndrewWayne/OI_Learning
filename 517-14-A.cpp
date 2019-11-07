/*
 * Author: xiaohei_AWM
 * Date: 11.2
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
const int maxn = 3e5 + 10;
int n, ans[maxn], num[maxn], cnt[maxn], sum[maxn], x, mxc, val[maxn];
vector<int> obj;
int main(){
    //freopen("a.in", "r", stdin);
    n = read();
    for(int i = 1; i <= n; i++){
        x = read(), cnt[x]++;
    }
    for(int i = 1; i <= n; i++){
        sum[cnt[i]] += cnt[i];
        val[cnt[i]]++;
        if(cnt[i] > 0) mxc++;
    }
    val[0] = 0;
    for(int i = 1; i <= n; i++){
        sum[i] += sum[i-1];
        val[i] += val[i-1];
        //cerr << sum[i] << " "
    }
    x = 0;
    int x = n;//表示取x次
    for(int k = 1; k <= n; k++){//由于答案单调递减，且第一个一定是n
        //if(k > mxc){ printf("0 "); continue;}
        while(x > 0 && sum[x] + max(mxc-val[x], 0) * x < (ll)x*k )
            x--;
        printf("%d ", x);
    }
    return 0;
}
