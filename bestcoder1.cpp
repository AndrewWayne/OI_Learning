/*
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 1e3 + 10;
int t, n, a[maxn], b[maxn], p1, p2;
int gcd(int a, int b){
    while(b){int r = b; b = a%b; a = r;}
    return a;
}
int main(){
    t = read();
    while(t--){
        p1 = p2 = 0;
        n = read();
        for(int i = 0; i < n; i++){
            a[i] = read();
            if(a[i] != 0) p1 = i;
        }
        for(int i = 0; i < n; i++){
            b[i] = read();
            if(b[i] != 0) p2 = i;
        }
        if(p1 == p2){
            int k = gcd(a[p1], b[p2]);
            printf("%d/%d\n", a[p1]/k, b[p2]/k);
        }else if(p1 < p2){
            printf("0/1\n");
        }else{
            printf("1/0\n");
        }
    }
    return 0;
}
