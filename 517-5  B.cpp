/*
 * Author: xiaohei_AWM
 * Date: 9.20
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
/*
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}
*/
const int maxn = 1e5 + 10;
const int maxm = 2e6 + 10;
int n, d, a[maxn], b[maxn], ans, sol[maxn];
map<int, int> ma, mb;//ma[a[i]], mb[b[i]]分别表示之前a[i]的个数，和之前b[i]的个数
map<pii, int> mab;//表示pair<a[i],b[i]>的个数，用于做一次容斥
int last_b, last_a;//分别表示上一次与当前右指针所指的值不一样的数的位置
//int max1[maxm], max2[maxm];
int main(){
    ans = 1;
    n = read();
    for(int i = 1; i <= n; i++){
        d = read(), a[i] = read(), b[i] = read();
        a[i] = d + a[i], b[i] = d - b[i];
    }
    int l = 1, r = 0;//由于一个可行的区间，其内部的所有区间一定都满足条件，而一个不满足条件的区间，一定不会是其他区间的子区间，所以可以使用双指针的方法解决问题。
    //虽然部分分也要通过这个性质来做DP
    for(r = 1; r <= n; r++){
        ma[a[r]]++, mb[b[r]]++;
        mab[make_pair(a[r], b[r])]++;
        if(r > 1 && a[r] != a[r-1]) last_a = r-1;
        if(r > 1 && b[r] != b[r-1]) last_b = r-1;
        while(l <= r){
            int cnt = r-l+1;
            if(last_a < l || last_b < l) break;//这表示这段区间的a或b全是同一个数
            int sum = ma[a[r]] + mb[b[last_a]] - mab[make_pair(a[r], b[last_a])];//若M取a[r]，则N一定为之前的a值与M不同的数的b值
            //做一次容斥后求出选中a[r], b[last_a]能覆盖的区间中的个数，如果正好是区间长度，则表示只要用这两个数就可以解决问题
            if(sum == cnt) break;
            sum = ma[a[last_b]] + mb[b[r]] - mab[make_pair(a[last_b], b[r])];
            if(sum == cnt) break;
            ma[a[l]]--, mb[b[l]]--;
            mab[make_pair(a[l], b[l])]--;//他们没有前途了
            l++;
        }
        ans = max(ans, r - l + 1);
        if(r - l + 1 == ans) sol[ans]++;
    }

    printf("%d %d", ans, sol[ans]);
    return 0;
}
