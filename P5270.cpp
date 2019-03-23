// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<assert.h>
using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
#define type int//看情况修改返回类型
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum * 10)+ch-48,ch=nc();
    return sum;
}
int quickPower(int a, int b, int p)//是求a的b次方
{
    int ans = 1 % p;//ans为答案，base为a^(2^n)
    for(; b; b >>= 1){
        if( b & 1 )
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}
const int N = 1e5 + 6;
const int MOD[3] = {1000007, 1111151, 1111181};
int n, T, Q, S[N], R[N], m, len, ans, sum[N], kkk;
vector<int> e[N];//利用vector动态分配内存防止爆炸，e[i][j]表示第i条小串第j位的字符
struct Ha {
    int h[3];//三1e7质数比对，全覆盖long long范围，可用CRT证明
    Ha() {
        memset(h, 0, sizeof(h));
    }
} Hash[N], KEY, now;
vector<Ha> key[N];//利用vector动态分配内存防止爆炸，num[i][j]表示第i条小串第j位之后到结尾的hash值之和
deque<pii> q;//q中的元素pair<int,int>.first表示这个串是否被连接，second表示这个串的前面被剪掉多长
inline void add(Ha &a, int b) {
    for (int i = 0; i < 3; i++){
        a.h[i] = (a.h[i] + quickPower(11313, b, MOD[i]) ) %MOD[i];
    }
}
inline void add(Ha &a, Ha &b) {
    for (int i = 0; i < 3; i++){
        a.h[i] = (a.h[i] + b.h[i])%MOD[i];
    }
}
inline void del(Ha &a, Ha &b) {
    for (int i = 0; i < 3; i++) a.h[i] = (a.h[i] - b.h[i] + MOD[i]) %MOD[i];
}

inline bool comp(Ha a, Ha b) {
    for (int i = 0; i < 3; i++)
        if (a.h[i] != b.h[i])
            return 0;
    return 1;
}
int main() {
    cin >> n >> T >> Q;
    for (int i = 1; i <= T; i++) {
        scanf("%d", &S[i]);
    }
    for (int i = 1; i <= T; i++) add(KEY, S[i]);
    for (int i = 1; i <= n; i++) {
        int len;
        scanf("%d", &len);
        for(int j = 1; j <= len; j++){
            int x;
            scanf("%d", &x);
            e[i].push_back(x);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d", &R[i]);
    for (int i = 1; i <= n; i++) {
        int len = e[i].size();
        key[i].resize(len);
        for (int j = 0; j < len; j++)
            add(key[i][j], e[i][j]);
        for (int j = len - 2; j >= 0; j--)
            add(key[i][j], key[i][j+1]);
    }//循环复杂度为O(L) L表示小串总长度
    for (int i = 1; i <= m && i <= Q; i++) {//m的一个循环进行hash连接比对模拟
        sum[i] = sum[i-1];
        add(now, key[R[i]][0]);
        len += e[R[i]].size();
        q.push_back(make_pair(R[i], 0));//整串连接到后面
        while (len > T) {//当长度超过S的长度
            pii x = q.front();
            q.pop_front();
            del(now, key[x.first][x.second]);//剪掉前面一整个小串
            len -= e[x.first].size() - x.second;
            if (len < T) {//剪多了就用一段后缀补到T
                int k = key[x.first].size() - (T - len);
                q.push_front(make_pair(x.first, k));
                add(now, key[x.first][k]);
                len = T;
            }
        }
        if(len == T && comp(now, KEY))
            ans++;
    }
    if (Q <= m) {
        cout << ans << endl;
        return 0;
    }
    Q -= m;
    for (int i = 1; i <= m && i <= Q; i++) {
        add(now, key[R[i]][0]);
        len += e[R[i]].size();
        q.push_back(make_pair(R[i], 0));
        while (len > T) {
            pii x = q.front();
            q.pop_front();
            del(now, key[x.first][x.second]);
            len -= e[x.first].size() - x.second;
            if (len < T) {
                int k = key[x.first].size() - (T - len);
                q.push_front(make_pair(x.first, k));
                add(now, key[x.first][k]);
                len = T;
            }
        }
        if (comp(now, KEY)) ++kkk;
        sum[i] = kkk;
    }
    cout << ans + kkk * (Q / m) + sum[Q%m] << endl;
    return 0;
}
