/*
 * Author: xiaohei_AWM
 * Date:5.24
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<string>
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
ll n, x;
string opt;
int main(){
    cin >> n;
    cin >> opt;
    int len = opt.length();
    for(int i = 0; i < len; i++){
        if(opt[i] == '+'){
            x = opt[++i] - '0';
            n = n + x;
        }else if(opt[i] == '-'){
            x = opt[++i] - '0';
            n = n - x;
        }else if(opt[i] == '*'){
            x = opt[++i] - '0';
            n = n * x;
        }else if(opt[i] == '%'){
            x = opt[++i] - '0';
            n = n % x;
        }else if(opt[i] == '^'){
            x = opt[++i] - '0';
            n = n * n;
        }
    }
    cout << abs(n) << endl;
    return 0;
}
