#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef double ldb;
typedef long long ll;
const int maxn = 55;
int n, m;
char s[maxn][30];
ldb ans;
ldb F[(1 << 20) + 5];//F[j]猜到j状态的概率有多少
int popcount[1 << 20];
ll Choice[(1 << 20) + 5];
 //__builtin_popcount()用这个函数来统计位数
 inline int popcountll(ll x){
     int res = popcount[x & ((1 << 16) - 1)];
     x >>= 16;
     for(int i = 1; i <= 3; i++)
        res += popcount[x & ((1 << 16) - 1)],
        x >>= 16;
     return res;
 }
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i]);
    if(n == 1){
        printf("0\n");
        return 0;
    }
    for(int i = 1; i <= (1 << 20) - 1; i++)
        popcount[i] = popcount[i >> 1] + (i & 1);
    m = strlen(s[1]);
    F[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++){
            int stat = 0;
            for(int k = 0; k <= m-1; k++)
                if(s[i][k] == s[j][k]) stat |= (1 << k);
            Choice[stat] |= (1LL << i) | (1LL << j);
        }
    for(int j = (1 << m) - 1; j >= 0; j--){
        for(int k = 0; k <= m-1; k++){
            if((j >> k) & 1){
                Choice[j^(1 << k)] |= Choice[j];
            }
        }
    }
    for(register int j = 0; j <= (1 << m) - 1; j++){
        int len = popcountll((ll)j);
        len = m - len;
        for(register int k = 0; k < m; k++){
            if(!((j >> k) & 1)){
                int stat = j ^ (1 << k);
                F[stat] += F[j] * 1.0/(ldb)len;
            }
        }
    }

    for(int i = 0; i <= (1 << m) - 1; i++){
        int len = popcountll(Choice[i]);
        ans += F[i] * (ldb)len / (ldb)n;//这步基于期望的可加性
    }

    printf("%.15f\n", ans);
    return 0;
}
