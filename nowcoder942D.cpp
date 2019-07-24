/*
 * Author: xiaohei_AWM
 * Date: 6.15
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
const int maxn = 1e6 + 10;
int n, m;
int a[40] = {0, 6, 28, 220, 496, 1184, 2620, 5020, 6232, 8128, 10744, 12285, 17296, 63020, 66928, 67095, 69615, 79750, 100485, 122265, 122368, 141664, 142310, 171856, 176272, 185368, 196724, 280540, 308620, 319550, 356408, 437456, 469028};
int b[40] = {0, 6, 28, 284, 496, 1210, 2924, 5564, 6368, 8128, 10856, 14595, 18416, 76084, 66992, 71145, 87633, 88730, 124155, 139815, 123152, 153176, 168730, 176336, 180848, 203432, 202444, 365084, 389924, 430402, 399592, 455344, 486178};
int main(){
    n = read(), m = read();
    for(int i = 1; i <= 33; i++){
        if(!(a[i] >= n && b[i] <= m)) continue;
        if(a[i] == b[i]) printf("%d\n", a[i]);
        else printf("%d %d\n", a[i], b[i]);
    }
    return 0;
}
