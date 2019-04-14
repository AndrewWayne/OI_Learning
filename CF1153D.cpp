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
const double eps = 1e-3;
const double deltaT = 0.97;
const int maxn = 3e5 + 10;
int n, opt[maxn], fa[maxn], limit, val[maxn], slash[maxn], ans;
vector<int> son[maxn];
vector<int> leaf;
int dfs(int x){
    int v = opt[x]?0:1000000;
    if(val[x] != 0)
        return val[x];
    for(int i = 0; i < son[x].size(); i++){
        int v2 = dfs(son[x][i]);
        v = opt[x]?max(v, v2):min(v,v2);
    }
    return v;
}
int calc(){
    for(int i = 0; i < limit; i++)
        val[leaf[i]] = slash[i+1];
    return dfs(1);
}
void SA(double T){
    int result = ans;
    int k = limit;
    for(int i = 1; i <= limit; i++)
        slash[i] = i;
    random_shuffle(slash+1, slash+1+limit);
    while(T > eps){
        int pos1 = rand()%(k-1) + 1;
        int pos2 = rand()%(k-1) + 1;
        swap(slash[pos1], slash[pos2]);
        int temp = calc();
        if(temp > result || exp(result - temp)/T*RAND_MAX > rand())
            result = temp;
        else{
            swap(slash[pos1], slash[pos2]);
        }
        T *= deltaT;
    }
    ans = max(result, ans);
}
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
    srand(820932745);
    n = read();
    for(int i = 1; i <= n; i++)
        opt[i] = read();
    for(int i = 2; i <= n; i++){
        fa[i] = read();
        son[fa[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        //cerr << son[i].size() << endl;
        if(son[i].size() == 0){
            leaf.push_back(i);
            limit++;
        }
    }
    while(Time() < 1.9){
        SA(100000);
        //cerr << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
