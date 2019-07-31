/*
 * Author: xiaohei_AWM
 * Date:
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
const int maxn = 1e5 + 10;
int n;
struct HK{
    int a, b, id;
} hk[maxn], hk1[maxn], hk2[maxn];
vector<int> level[maxn];
int mina[maxn], minb[maxn], maxa[maxn], maxb[maxn], sum[maxn], lim;
bool visited[maxn];
bool cmp1(HK hk1, HK hk2){
    return hk1.a > hk2.a;
}
bool cmp2(HK hk1, HK hk2){
    return hk1.b > hk2.b;
}
int query(HK x){
    int pos = 0;
    for(int j = 20; j >= 0; j--){
        int npos = pos + (1 << j);
        if(npos <= lim && mina[npos] > x.a && minb[npos] > x.b)
            pos = npos;
    }
    return pos+1;
}
int main(){
    n = read();
    memset(mina, 0x7f, sizeof(mina));
    memset(minb, 0x7f, sizeof(minb));
    for(int i = 1; i <= n; i++){
        hk2[i].a = hk1[i].a = hk[i].a = read();
        hk2[i].id = hk1[i].id = hk[i].id = i;
    }
    for(int i = 1; i <= n; i++)
        hk2[i].b = hk1[i].b = hk[i].b = read();
    sort(hk1+1, hk1+1+n, cmp1);
    sort(hk2+1, hk2+1+n, cmp2);
    for(int i = 1; i <= n; i++){
        if(!visited[hk1[i].id]){
            int pos = 0;
            for(int j = 20; j >= 0; j--){
                int npos = pos + (1<<j);
                if(npos <= lim && mina[npos] > hk1[i].a && minb[npos] > hk1[i].b)
                    pos = npos;
            }
            pos++;
            lim = max(pos, lim);
            level[pos].push_back(hk1[i].id);
            mina[pos] = min(mina[pos], hk1[i].a);
            maxa[pos] = max(maxa[pos], hk1[i].a);
            minb[pos] = min(minb[pos], hk1[i].b);
            maxb[pos] = max(maxb[pos], hk1[i].b);
            visited[hk1[i].id] = 1;
        }
        if(!visited[hk2[i].id]){
            int pos = 0;
            for(int j = 20; j >= 0; j--){
                int npos = pos + (1<<j);
                if(npos <= lim && mina[npos] > hk2[i].a && minb[npos] > hk2[i].b)
                    pos = npos;
            }
            pos++;
            lim = max(pos, lim);
            level[pos].push_back(hk2[i].id);
            mina[pos] = min(mina[pos], hk2[i].a);
            maxa[pos] = max(maxa[pos], hk2[i].a);
            minb[pos] = min(minb[pos], hk2[i].b);
            maxb[pos] = max(maxb[pos], hk2[i].b);
            visited[hk2[i].id] = 1;
        }
    }
    cerr << endl;
    cerr << lim << endl;
    for(int i = lim; i >= 1; i--)
        sum[i] = sum[i+1] + level[i+1].size();

    for(int i = 1; i <= n; i++){
        int pos = 0;
        int ans = 0;
        for(int j = 20; j >= 0; j--){
            int npos = pos + (1 << j);
            if(npos <= n && hk1[npos].a >= hk[i].a)
                pos = npos;
        }
        ans += n - pos;
        pos = 0;
        for(int j = 20; j >= 0; j--){
            int npos = pos + (1 << j);
            if(npos <= n && hk2[npos].b >= hk[i].b)
                pos = npos;
        }
        ans += n - pos;
        ans -= sum[query(hk[i])];
        cout << ans << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        int ans = 0;
        int pos = 0;
        for(int j = 20; j >= 0; j--){
            int npos = pos + (1 << j);
            if(npos <= lim && maxa[npos] > hk[i].a/2 && maxb[npos] > hk[i].b/2)
                pos = npos;
        }
        cout << sum[pos+1] + level[pos+1].size() << " ";
    }
    cout << endl;
    return 0;
}
