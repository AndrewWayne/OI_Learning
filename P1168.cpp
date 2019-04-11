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
const int maxn = 1e6 + 10;
int n, a[maxn], pos[maxn], mid, mov, cnt, ans[maxn];
pii b[maxn];
struct Node{
    int pre, nxt, val;
} List[maxn];
void insert(int node, int val){
    List[++cnt].val = val;
    List[cnt].pre = node;
    List[cnt].nxt = List[node].nxt;
    List[List[node].nxt].pre = cnt;
    List[node].nxt = cnt;
}
void erase(int node){
    List[List[node].pre].nxt = List[node].nxt;
    List[List[node].nxt].pre = List[node].pre;
}
bool cmp(pii u, pii v){
    if(u.first == v.first)
        return u.second < v.second;
    return u.first < v.first;
}
int main(){
    n = read();
    if(!(n & 1))
        n--;
    mid = (n+1) >> 1;
    for(int i = 1; i <= n ; i++)
        b[i].first = a[i] = read(), b[i].second = i;
    sort(b+1, b+1+n, cmp);
    for(int i = 1; i <= n; i++){
        insert(cnt, b[i].first);
        pos[b[i].second] = cnt;
    }
    for(int i = n; i >= 1; i--){
        if(i & 1){
            if(mov > 0)
                mid = List[mid].nxt;
            if(mov < 0)
                mid = List[mid].pre;
            mov = 0;
            ans[i] = List[mid].val;
        }
        if(pos[i] < mid)
            mov++;
        if(pos[i] > mid)
            mov--;
        erase(pos[i]);
    }
    for(int i = 1; i <= n; i++)
        if(i & 1)
            cout << ans[i] << endl;
    return 0;
}
