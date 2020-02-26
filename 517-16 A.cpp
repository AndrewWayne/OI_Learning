#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<pair<int,int>, int> piii;
const int maxn = 1e5 + 10;
int c[maxn], n, lim;
int b[maxn], ans[maxn];
piii man[maxn];
bool cmp(piii x, piii y){
    if(x.first.first == y.first.first) return x.first.second > y.first.second;
    return x.first.first < y.first.first;
}
inline int queryid(int x){
    return lower_bound(b+1, b+lim, x) - b;
}
inline int lowbit(int x){return x & -x;}
inline void add(int pos, int val){
    for(int i = pos; i; i -= lowbit(i))
        c[i] += val;
}
int query(int pos){
    int res = 0;
    for(int i = pos; i < lim; i += lowbit(i))
        res += c[i];
    return res;
}
int main(){
    freopen("data.in", "r", stdin);
    freopen("out1.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d", &man[i].first.second, &man[i].first.first), b[i] = man[i].first.second, man[i].second = i;
    sort(man+1, man+1+n, cmp);
    sort(b+1, b+1+n);
    lim = unique(b+1, b+1+n) - b;
    for(int i = 1; i <= n; i++){
        int key = queryid(man[i].first.second);
        ans[man[i].second] = query(key);
        add(key, 1);
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
