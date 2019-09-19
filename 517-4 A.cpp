/*
 * Author: xiaohei_AWM
 * Date: 9.14
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
ll y;
int n, m;
bool edge[100][100];
int lim;
vector<int> bit;
int main(){
    y = readll();
    while(y){
        bit.push_back(y&1);
        lim++;
        y >>= 1;
    }

    int cnt = 0;
    for(int i = 1; i <= lim+2; i++){
        if(i >= 2 && i <= lim && bit[i-2] == 1)
            edge[i][lim+1] = 1, cnt++;
        for(int j = i+1; j <= lim+2; j++){
            if(j != lim+1) edge[i][j] = 1, cnt++;
        }
    }

    printf("%d %d\n", lim+2, cnt);
    for(int i = 1; i <= lim+2; i++)
        for(int j = 1; j <= lim+2; j++)
            if(edge[i][j])
                printf("%d %d\n", i, j);
    return 0;
}
