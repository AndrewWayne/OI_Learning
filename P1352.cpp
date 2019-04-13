//It's supposed to die.
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
const int maxn = 6060;
int n, r[maxn], l, k, f[maxn][2], root;
int father[maxn];
std::vector<int> son[maxn];
void dfs(int x){
    f[x][1] = r[x];
    if(son[x].size() == 0)
        return;
    for(auto i = son[x].begin(); i != son[x].end(); i++){
        dfs(*i);
        f[x][1] += f[*i][0];
        f[x][0] += max(f[*i][0], f[*i][1]);
        cerr << "$: " << f[x][1] << " " << f[x][0] << endl;
    }
    return ;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        r[i] = read();
    for(int i = 1; i <= n-1; i++){
        l = read(), k = read(),
        son[k].push_back(l);
        father[l]++;
    }
    for(int i = 1; i <= n; i++)
        if(father[i] == 0){
            root = i;
            break;
        }
    dfs(root);
    cout << max(f[root][1], f[root][0]);
    return 0;
}
