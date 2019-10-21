#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxv = 6010;
const int maxn = 1e5 + 10;
typedef long long ll;
int  T, n, top;
ll f[maxn], sz[maxn], w[maxn];
pair<ll, ll> stck[maxn];
void solve1(){
    //cerr << endl;
    memset(f, 0x7f, sizeof(f));
    memset(stck, 0, sizeof(stck));
    f[0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++){
        for(int j = ans; j >= 0; j--){
            if(f[j] <= w[i] * 6)
                f[j+1] = min(f[j] + w[i], f[j+1]),
                ans = max(j+1, ans);
        }
    }
    printf("%lld\n", ans);
}
int main(){
    //freopen("stack.in", "r", stdin);
    cerr << sizeof(int*) << endl;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d", &n);
        printf("Case #%d: ", i);
        solve1();
    }
}
