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
const int MAXN = 1e5 + 10;
struct Tree{
    int h;
    ll c, p;
};
Tree a[MAXN];
bool cmp(Tree a, Tree b){
    return a.h < b.h;
}
struct Tre{
    ll c, p;
};
vector<Tre> vec[MAXN];
int n,h[MAXN],b[MAXN];
ll sum[MAXN],numc[210],numh[MAXN];
int main(){
    while(~scanf("%d",&n)){
        memset(numc, 0, sizeof(numc));
        memset(numh, 0, sizeof(numh));
        ll macost=0;
        for (int i = 1; i <= n; i++){
            scanf("%d%lld%lld", &a[i].h, &a[i].c, &a[i].p);
            macost = max(macost, a[i].c);
        }
        sort(a+1, a+1+n, cmp);
        for (int i = 1; i <= n; i++)
            h[i] = a[i].h;
        int k = 1;
        b[1] = h[1];
        h[1] = 1;
        for (int i = 2; i <= n; i++){
            if (h[i] != b[k]){
                k++;
                b[k] = h[i];
                h[i] = k;
            }else h[i] = k;
        }//离散化
        a[0].h = 0;
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
            a[i].h = h[i];
        for (int i = 1; i <= n; i++)
            sum[a[i].h] = sum[a[i-1].h] + a[i].c*a[i].p;
        for (int i = 1; i <= n; i++)
            numc[a[i].c] += a[i].p;
        for (int i = 1; i <= n; i++)
            numh[a[i].h] += a[i].p;
        for (int i = 1; i <= n; i++)
            vec[a[i].h].push_back({a[i].c, a[i].p});
        ll all = 0;
        for (int i = 1; i <= n; i++)
            all += a[i].p;
        ll ans = llINF;
        for (int i = k; i >= 1; i--){
            int height = i;
            ll cost = sum[k] - sum[height];
            for (int j = 0; j < vec[height].size(); j++)
                numc[vec[height][j].c] -= vec[height][j].p;
            ll num = numh[height];
            if (num > all/2){
                ans = min(ans,cost);
                all -= num;
                continue;
            }
            ll ao = all;
            for (int j = 1; j <= macost; j++)
            if (numc[j] != 0){
                if(num > ao/2){
                    ans = min(ans,cost);
                    break;
                }else if(num > (ao-numc[j])/2){
                    cost += (ll)(ao-2*num+1)*(ll)j;
                    ans = min(ans, cost);
                    break;
                }else{
                    ao -= numc[j];
                    cost += numc[j] * (ll)j;
                }
            }
            all -= num;
            ans = min(ans, cost);
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= k; i++)
            vec[i].clear();
    }
    return 0;
}
