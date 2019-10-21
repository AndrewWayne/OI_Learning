%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-fhoist-adjacent-loads")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long double ldb;
const int maxn = 51;
int n, m;
char s[maxn][30];
ldb ans;
ldb F[(1 << 20)];//F[j]猜到j状态的概率有多少
bool able[(1 << 20)];
vector<short> Choice[(1 << 20)];
int C[30];//C[i]用于维护出C(m, i)的大小
 //__builtin_popcount()用这个函数来统计位数
int main(){
    //freopen("programmer.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i]);
    if(n == 1){
        printf("0\n");
        return 0;
    }
    //for(int i = 1; i <= n; i++)
    //    printf("%s\n", s[i]);
    m = strlen(s[1]);
    //cerr << m << endl;
    F[0] = 1;
    C[0] = 1;
    for(short i = 1; i <= n; i++) Choice[0].push_back(i);
    bool Upded = false;
    for(int i = 1; i <= n; i++){
        for(register int j = 1; j <= (1 << m) - 1; j++){
            Choice[j].clear();
            Upded = false;
            int len = __builtin_popcount(j);
            len = m - len + 1;
            for(register int k = 0; k <= m-1; k++){
                if((j >> k) & 1){
                    int stat = j ^ (1 << k);
                    if(able[stat]) continue;
                    if(Choice[stat].size() == 0) continue;
                    if(!Upded){
                        for(int l = 0; l < Choice[stat].size(); l++){
                            if(s[Choice[stat][l]][k] == s[i][k])
                                Choice[j].push_back(Choice[stat][l]);
                        }
                        Upded = true;
                    }
                    F[j] += 1.0/(ldb)len * F[stat];
                }
            }
            if(Choice[j].size() == 1){
            //    cerr << j << " " << m - len + 1 << endl;
                able[j] = true;
                ans += F[j] * (1.0)/(ldb)n * (m - len + 1);
            }
            //cerr << j << "------" << F[j] << endl;
        }
        memset(able, 0, sizeof(able));
        memset(F, 0, sizeof(F));
        F[0] = 1;
    }
    printf("%.15Lf\n", ans);
}
