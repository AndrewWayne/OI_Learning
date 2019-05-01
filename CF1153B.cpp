/*
 *Author: xiaohei_AWM
 *Date:
 *Mutto: Face to the weakness, expect for the strength.
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
const int maxn = 110;
int n, m, h, a[maxn], b[maxn];
int height[maxn][maxn];
int main(){
    n = read(), m = read(), h = read();
    for(int i = 1; i <= m; i++)
        a[i] = read();
    for(int i = 1; i <= n; i++)
        b[i] = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            height[i][j] = read();
            if(height[i][j])
                height[i][j] = min(a[j], b[i]);
        }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << height[i][j] << " ";
        cout << endl;
    }
    return 0;
}