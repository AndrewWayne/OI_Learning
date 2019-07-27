/*
 * Author: xiaohei_AWM
 * Date: 7.25
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
int n, n1, cnt[2], top, ans;
bool d[100];
void dfs(int x, int res, int dep){

}
int main(){
    while(n1 = n = read()){
        memset(d, 0, sizeof(d));
        cnt[1] = cnt[0] = 0;
        ans = 0;
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        for(top = 0; n1; top++, n1 >>= 1)
            d[top] = n1 & 1, cnt[d[top]]++;
        //cerr << cnt[1] << " " << cnt[0] << endl;
        ans = top + cnt[1]-1;
        ans = min(ans, top+2+cnt[0]);
        int s = 0;
        for(int i = top-1; i >= 0; i--)
            if(d[i] == 0) s++;

        cout << ans << endl;
    }
    return 0;
}
