/*
 * Author: xiaohei_AWM
 * Date: 5.15
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
const int maxn = 1e5 + 10;
int n, a[maxn];
int LIS(int start, int endss, bool mode){//1 -- LIS, 0 -- LDS
    int Vec[maxn], f[maxn], cnt = 0, res = 0;
    memset(Vec, 0, sizeof(Vec));
    memset(f, 0, sizeof(f));
    f[start] = 1;
    Vec[++cnt] = a[start];
    for(int i = start+1; i <= endss; i++){
        int pos = 0;
        for(int k = 20; k >= 0; k--){
            if(mode){
                if(pos + (1<<k) <= cnt && Vec[pos + (1<<k)] < a[i])
                    pos += 1 << k;
            }else{
                if(pos + (1<<k) <= cnt && Vec[pos + (1<<k)] > a[i])
                    pos += 1 << k;
            }
        }
        f[i] = pos + 1;
        res = max(f[i], res);
        if(f[i] > cnt) Vec[++cnt] = a[i];
        else{
            if(mode){if(Vec[f[i]] > a[i]) Vec[f[i]] = a[i];}
            else{if(Vec[f[i]] < a[i]) Vec[f[i]] = a[i];}
        }
    }
    return res;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    cout << LIS(1, n, 1) << endl;
    return 0;
}
