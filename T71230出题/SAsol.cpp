#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define sqr(x) ((x)*(x))
using namespace std;
//自豪的采用了SA？？
const double eps = 1e-3;
const double deltaT = 0.97;
const int maxn = 5e6 + 10;
int n, k;
int p[maxn], st[maxn][30], Log2[maxn];
long long ans;
int slash[maxn];
bool used[maxn];
long long query(int l, int r){
    int res = 0;
    int len = r - l + 1;
    int x = Log2[len];
    res = st[l][x] | st[r - (1<<x) + 1][x];
    return res;
}
int myrand(int x){return rand() % x;}
long long calc(){
    long long result = 0;
    for(int i = 1; i <= k; i++)
        result += query(slash[i-1]+1, slash[i]);
    //cerr << result << endl;
    return result;
}
void SA(double);
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
    srand(time(0));
    //freopen("dp8.in", "r", stdin);
    scanf("%d%d", &n, &k);
    ans = 0;
    for(int i = 1; i <= n ;i++)
        scanf("%d", &p[i]),
        st[i][0] = p[i];
    for(int i = 2; i <= n; i++){
        if((1 << (Log2[i-1]+1)) > i)
            Log2[i] = Log2[i-1];
        else
            Log2[i] = Log2[i-1]+1;
    }
    for(int i = 1; i <= 30; i++){
        for(int j = 1; j + (1<<i) -1 <= n; j++)
            st[j][i] = st[j][i-1] | st[j + (1 << (i-1))][i-1];
    }
    while(Time() < 0.9){
        SA(100000);
        //cerr << ans << endl;
    }
    printf("%lld\n", ans);
    return 0;
}
void SA(double T){
    long long result = ans;
    slash[k] = n;
    for(int i = 1; i < k; i++){
        slash[i] = rand()%(n-1) + 1;
        while(used[slash[i]])
            slash[i] = rand()%(n-1) + 1;
        used[slash[i]] = true;
        //cerr << slash[i] << " ";
    }
    //cerr << endl;
    sort(slash+1, slash+k);
    while(T > eps){
        int pos = rand()%(k-1) + 1;
        int old = slash[pos];
        slash[pos] = rand()%(n-1) + 1;
        while(used[slash[pos]])
            slash[pos] = rand()%(n-1) + 1;
        used[old] = false;
        used[slash[pos]] = true;
        sort(slash+1, slash+k);
        long long temp = calc();
        if(temp > result || exp(result - temp)/T*RAND_MAX > rand())
            result = temp;
        else{
            used[slash[pos]] = false;
            slash[pos] = old;
            used[slash[pos]] = true;
        }
        T *= deltaT;
    }
    for(int i = 1; i < k; i++)
        used[slash[i]] = false;
    ans = max(result, ans);
}
