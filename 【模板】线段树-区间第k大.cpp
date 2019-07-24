/*
 * Author: xiaohei_AWM
 * Date: 6.6
 * Mutto: Face to the weakness, expect for the strength.
 * 此模板解决区间第k值问题，O(log^3 n)
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
const int maxn = 3e4 + 10;
struct Sege{
    int l, r;
    vector<int> seq;
} Tree[maxn<<2];
int n, m, a[maxn], b[maxn], l, r, k;
void Up(int x){
    int L = Tree[x].l = Tree[x << 1].l;
    int R = Tree[x].r = Tree[x << 1|1].r;
    merge(Tree[x << 1].seq.begin(), Tree[x << 1].seq.end(), Tree[x << 1|1].seq.begin(), Tree[x << 1|1].seq.end(), Tree[x].seq.begin());
}
void Build(int x, int l, int r){//由主定理分析可计算的复杂度为 O(nlogn)
    Tree[x].seq.clear();
    if(l == r){
        Tree[x].l = Tree[x].r = l,
        Tree[x].seq.push_back(a[l]);// O(1)
        return;
    }
    int mid = (l+r) >> 1;
    Build(x << 1, l, mid);
    Build(x << 1|1, mid+1, r);
    Tree[x].seq.resize(Tree[x<<1|1].r - Tree[x<<1].l + 1);// O(n)
    Up(x);
}
int Query(int x, int l, int r, int p){//通过查询范围 [l, r] 中的 x 的排名加二分后实现
    if(l == Tree[p].l && r == Tree[p].r)
        return upper_bound(Tree[p].seq.begin(), Tree[p].seq.end(), x) - Tree[p].seq.begin();//求出 ≤ x的个数
    //显然，由于每一层最多两个节点有效，所以一次 Query 复杂度不会超过 O(log^2 n)
    int mid = (Tree[p].l + Tree[p].r) >> 1;
    if(l >= mid+1) return Query(x, l, r, p << 1|1);
    else if(r <= mid) return Query(x, l, r, p << 1);
    else return Query(x, l, mid, p << 1) + Query(x, mid+1, r, p << 1|1);
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) b[i] = a[i] = read();
    Build(1, 1, n);
    sort(b+1, b+1+n);
    for(int i = 1; i <= m; i++){
        l = read(), r = read(), k = read();
        int j = 0;
        for(int t = 15; t >= 0; t--){
            int jt = j + (1 << t);
            if(jt <= n && Query(b[jt], l, r, 1) < k)
                j = jt;
        }//对于每一个询问采用二分的策略求得答案，需再套一个logn，所以对于在线询问求解[l, r]中第k大值复杂度为O(log^3n) log^3n对于30000这个量级来说约为3357，加上线段树自带一个常数log，该方法求区间第k值实际并不很优
        printf("%d\n", b[j+1]);

    }
    return 0;
}
/*
Example:
6 4
10 5 5 3 4 8
1 3 2
2 4 3
1 5 4
3 6 4
*/
