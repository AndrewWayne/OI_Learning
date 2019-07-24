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
#include<queue>
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
int n, a, b, t;
priority_queue<int, vector<int>, greater<int> > Q;
ll sum;
int main(){
    n = read();
    for(int i=0;i<n;i++){
        t = read();
        Q.push(t);
    }
    sum = 0;
    if(Q.size() == 1){
        sum += Q.top();
        Q.pop();
    }
    while(Q.size() > 1){
        a = Q.top();
        Q.pop();
        b = Q.top();
        Q.pop();
        t = a + b;
        sum += t;
        Q.push(t);//找出两个最小的  合并之后在放入队列中
    }//思路：把切木头思考为从散的合并回去
    printf("%lld\n", sum);
    return 0;
}
