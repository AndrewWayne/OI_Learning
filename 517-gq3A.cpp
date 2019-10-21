#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 201;
typedef pair<int, int> pii;
int n, k, sa, sb;
long long a[maxn];
pii K[maxn];
int f[2][maxn][maxn*26];
int limm;
//double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
    //freopen("subset.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++){
        for(K[i].first = 0; a[i] % 5 == 0 && a[i]; a[i] /= 5, K[i].first++);
        for(K[i].second = 0; (a[i] & 1) == 0 && a[i]; a[i] >>= 1, K[i].second++);
        limm = limm + K[i].first;
    }
    int ans = 0;
    memset(f, -127, sizeof(f));
    //for(int i = 1; i <= n; i++)
    //    cerr << K[i].first << " " << K[i].second << endl;
    int pos = 1;
    f[0][0] = 0;
    ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = k; j >= 1; j--){
            for(int k = limm; k >= K[i].first; k--){
                f[j][k] = max(f[j-1][k-K[i].first] + K[i].second, f[j][k]);
            }
            //cerr << i << ":" << j << "----" << key << endl;
        }
        pos ^= 1;
    }
//    ans = 0;
//    for(int i = 1; i <= limm*n; i++){
//        ans = max(max(ans, min(i, f[1][k][i])), f[0][k][i]);
//    }
    for(int i = 1; i <= limm; i++){
        ans = max(ans, min(f[k][i], i));
    }
    cout << ans << endl;
    //cerr << Time() << endl;
    return 0;
}
