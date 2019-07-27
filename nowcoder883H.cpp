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
const int maxn = 1e3 + 10;
struct Node{
    ll x, y;
} nodes[maxn];
int t, n, slash;
bool cmp1(Node u, Node v){
    return u.y < v.y;
}
bool cmp2(Node u, Node v){
    return u.x < v.x;
}
int main(){
    t = read();
    while(t--){
        node temp1, temp2;
        n = read();
        for(int i = 1; i <= n; i++)
            nodes[i].x = read(), nodes[i].y = read();
        sort(nodes+1, nodes+1+n, cmp2);
        int sx = nodes[n/2].x + nodes[n/2+1].x;
        if(sx & 1) sx++;
        sort(nodes+1, nodes+1+n, cmp1);
        int sy = nodes[n/2].y + nodes[n/2+1].y;
        if(sy & 1) sy--;
        temp1.x = ();
        temp2.x = (nodes[n/2].x + nodes[n/2+1].x)
        sort(nodes+1, nodes+1+n, cmp2);
        printf("%lld %lld %lld %lld\n", xx1, yy1, xx2, yy2);
    }
    return 0;
}
