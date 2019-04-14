/*
 *Author: xiaohei_AWM
 *Date:4.13
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
int n, t, d[110], s[110], ans, anst;
int main(){
    anst = 1000000;
    n = read(), t = read();
    for(int i = 1; i <= n; i++){
        s[i] = read(), d[i] = read();
        if(t <= s[i]){
            if(s[i] <= anst){
                ans = i, anst = s[i];
            }
            cerr << i << " " << s[i] << endl;
        }else{
            int x = ceil(1.0*(t-s[i])/d[i]);
            cerr << i << ": "<< x*d[i]+s[i] << endl;
            if(anst > x*d[i] + s[i])
                ans = i, anst = x*d[i] + s[i];
        }
    }
    cout << ans << endl;
    return 0;
}
