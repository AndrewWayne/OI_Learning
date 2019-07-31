/*
 * Author: xiaohei_AWM
 * Date: 7.31
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
int n, idt;
int stat[60], func[101];
inline int h() {
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += abs(stat[i] - stat[i + 1]) != 1;
    return cnt;
}
bool dfs(int dep, int maxdep){
    if(h() + dep > maxdep) return false;
    if(h() == 0) return true;
    for(int i = 1; i <= n; i++){
        reverse(stat+1, stat+1+i);
        if(dfs(dep+1, maxdep))
            return true;
        reverse(stat+1, stat+1+i);
    }
    return false;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        stat[i] = read(), func[stat[i]] = 1;
    int top = 1;
    for(int i = 1; i <= 100; i++)
        if(func[i]) func[i] = top, top++;
    for(int i = 1; i <= n; i++)
        stat[i] = func[stat[i]];
    stat[n+1] = n+1;
    for(int i = 1; i <= 2*n - 2; i++){
        if(dfs(0, i)){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
