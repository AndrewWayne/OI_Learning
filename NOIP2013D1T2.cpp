#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 1e5 + 10;
const int MOD = 99999997;
int n, a[maxn], b[maxn];
pii ida[maxn], idb[maxn];
int func[maxn], pos[maxn];
ll c[maxn], ans;
inline int lowbit(int x){return x & -x;}
void add(int pos, int val){
    for(int i = pos; i <= n; i += lowbit(i))
        c[i] += val, c[i] %= MOD;
}
ll query(int pos){
    ll res = 0;
    for(int i = pos; i; i -= lowbit(i))
        res += c[i], res %= MOD;
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a+i), ida[i].first = a[i], ida[i].second = i;
    for(int i = 1; i <= n; i++)
        scanf("%d", b+i), idb[i].first = b[i], idb[i].second = i;

    sort(ida+1, ida+1+n);
    for(int i = 1; i <= n; i++)
        a[ida[i].second] = i, func[i] = ida[i].second;

    sort(idb+1, idb+1+n);
    for(int i = 1; i <= n; i++)
        b[idb[i].second] = i;
    for(int i = 1; i <= n; i++)
        b[i] = func[b[i]], pos[b[i]] = i;

    for(int i = n; i >= 1; i--){
        ans += query(pos[i]), ans %= MOD;
        add(pos[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}
