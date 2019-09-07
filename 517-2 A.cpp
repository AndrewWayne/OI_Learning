/*
 * Author: xiaohei_AWM
 * Date: 9.7
 * Motto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
#include<utility>
#include<stack>
#include<functional>
#include<queue>
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
typedef std::map<int,int>::iterator miii;
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
const int maxn = 55;
int n, a[maxn], ans;
map<int, int> f, v;
void divide(int x){
    queue<pii> Q;
    Q.push(make_pair(x, 0));
    while(!Q.empty()){
        pii h = Q.front();
        Q.pop();
        int x = h.first, depth = h.second;
        if(v.count(h.first)){
            if(v[x] > depth){
                v[x] = depth;
                if(x & 1) Q.push(make_pair((x-1) >> 1, depth+1)), Q.push(make_pair((x+1) >> 1, depth+1));
                else if(x >= 0) Q.push(make_pair(x>>1, depth+1));
            }
        }else{
            v[x] = depth;
            if(x & 1) Q.push(make_pair((x-1) >> 1, depth+1)), Q.push(make_pair((x+1) >> 1, depth+1));
            else if(x >= 0) Q.push(make_pair(x>>1, depth+1));
        }
    }
    return;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    v.clear();
    divide(a[1]);
    for(auto i = v.begin(); i != v.end(); i++)
        f[i->first] += i->second;

    for(int i = 2; i <= n; i++){
        v.clear();
        divide(a[i]);
        stack<miii> S;
        for(auto kk = f.begin(); kk != f.end(); kk++){
            int val = kk->first;
            //cerr << val << endl;
            if(!v.count(val)) S.push(kk);
            else kk->second += v[val];
        }
        while(!S.empty()) f.erase(S.top()), S.pop();
    }
    ans = INF;
    for(auto i = f.begin(); i != f.end(); i++){
        ans = min(ans, i->second);
        //cerr << i->first << " " << i -> second << endl;
    }
    cout << ans << endl;
    return 0;
}
