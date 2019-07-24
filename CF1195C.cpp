/*
 * Author: xiaohei_AWM
 * Date: 7.17
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
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
int n;//f[i][j]表示选到第i个人，那人是j状态的最大答案
ll  h[3][maxn], f[maxn][3];
int main(){
    n = read();
    for(int i = 1; i <= n; i++) h[1][i] = read();
    for(int i = 1; i <= n; i++) h[2][i] = read();
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 2; j++){
            for(int k = 0; k <= 2; k++){
                if(j == k && j != 0) continue;
                f[i][j] = max(f[i][j], f[i-1][k] + h[j][i]);
            }
        }
    }
    cout << max(f[n][0], max(f[n][1], f[n][2])) << endl;
    return 0;
}
