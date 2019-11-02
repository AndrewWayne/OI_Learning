/*
 * Author: xiaohei_AWM
 * Date: 10.26
 * Motto: Face to the weakness, expect for the strength.
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
#include<stack>
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 6010, maxm = 300;
int n, m, L[maxm][maxn], R[maxm][maxn], val[maxm][maxn];
long long sum[maxn];
long long ans[maxn][maxn];
stack<pii> S;
int main(){
    //memset(f, 0x3f, sizeof(f));
    scanf("%d%d", &n, &m);
    for(int i = 2; i <= n; i++)
        scanf("%lld", &sum[i]), sum[i] += sum[i-1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &val[j][i]);
    for(int i = 1; i <= m; i++){
        while(!S.empty()) S.pop();
        for(int j = 1; j <= n; j++){
            while(!S.empty() && val[i][j] > S.top().first) S.pop();
            if(!S.empty()) L[i][j] = S.top().second + 1;
            else L[i][j] = 1;
            S.push(make_pair(val[i][j], j));
        }
        while(!S.empty()) S.pop();
        //cerr << "OK" << endl;
        for(int j = n; j >= 1; j--){
            while(!S.empty() && val[i][j] > S.top().first) S.pop();
            if(!S.empty()) R[i][j] = S.top().second - 1;
            else R[i][j] = n;
            S.push(make_pair(val[i][j], j));
        }
        for(int j = 1; j <= n; j++){
            ans[L[i][j]][j] += val[i][j];
            ans[j+1][R[i][j]+1] += val[i][j];
            ans[L[i][j]][R[i][j]+1] -= val[i][j];
            ans[j+1][j] -= val[i][j];
        }
    }
    //cerr << m << endl;
    ll sol = -llINF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            ans[i][j] += ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            sol = max(ans[i][j] - (sum[j] - sum[i]), sol);
        }
    }
    cout << sol << endl;
    return 0;
}
