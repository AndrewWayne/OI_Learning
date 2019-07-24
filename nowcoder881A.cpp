/*
 * Author: xiaohei_AWM
 * Date: 7.18
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<queue>
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
int n, p1[maxn], p2[maxn], flag;
deque<int> Q1, Q2;
int main(){
    std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n)){
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        Q1.clear(), Q2.clear();
        flag = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &p1[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &p2[i]);
        for(int i = 1; i <= n; i++){
            while(!Q1.empty() && Q1.back() >= p1[i]) Q1.pop_back();
            Q1.push_back(p1[i]);
            while(!Q2.empty() && Q2.back() >= p2[i]) Q2.pop_back();
            Q2.push_back(p2[i]);
            if(Q1.size() != Q2.size()){
                printf("%d\n", i-1);
                flag = 1;
            }
        }
        if(flag == 0) printf("%d\n", n);
    }
    return 0;
}
