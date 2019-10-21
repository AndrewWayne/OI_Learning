#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
const int maxn = 150010;
const int maxm = 310;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
int n, m, d, cnt;
ll F[2][maxn], ax, bx, tx, t[maxm], delta[maxm];//待会儿滚掉--->第i批彩灯时，在j位置的最大快乐值
vector<ll> a[maxm], b[maxm];
deque<pil> Q;
signed main(){
    //freopen("caideng.in", "r", stdin);
    //memset(F, -127, sizeof(F));
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &ax, &bx, &tx);
        if(tx > t[cnt]){
            t[++cnt] = tx;
            delta[cnt] = t[cnt] - t[cnt-1];
        }
        a[cnt].push_back(ax), b[cnt].push_back(bx);
    }
    //cerr << cnt << endl;
    memset(F[1], 0, sizeof(F[1]));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < a[1].size(); j++)
            F[1][i] += b[1][j] - abs(a[1][j] - i);
    }
    //cerr << F[1][49] << endl;
    //cerr << F[1][50] << endl;
    for(int i = 2; i <= cnt; i++){
        memset(F[i&1], -127, sizeof(F[i&1]));
        for(int j = 1; j <= min(ll(n), 1+d*delta[i]); j++){
            while(!Q.empty() && Q.back().second < F[(i&1)^1][j])
                Q.pop_back();
            Q.push_back(make_pair(j, F[(i&1)^1][j]));
        }
        for(int j = 1; j <= n; j++){
            while(!Q.empty() && Q.front().first < j - d*delta[i])
                Q.pop_front();
            F[i&1][j] = Q.front().second;
            //cerr << F[i&1][j] << " ";
            for(int k = 0; k < a[i].size(); k++){
                F[i&1][j] += b[i][k] - abs(a[i][k] - j);
            }
            //cerr << F[i&1][j] << " ";
            if(j+d*delta[i]+1 > n) continue;
            while(!Q.empty() && Q.back().second < F[(i&1)^1][j+d*delta[i]+1])
                Q.pop_back();
            Q.push_back(make_pair(j+d*delta[i]+1, F[(i&1)^1][j+d*delta[i]+1]));
        }
        //cerr << endl;
        //cerr << F[i][j]
        Q.clear();
    }
    ll ans = -llINF;
    for(int i = 1; i <= n; i++) ans = max(F[cnt&1][i], ans);
    printf("%lld", ans);
    return 0;
}
