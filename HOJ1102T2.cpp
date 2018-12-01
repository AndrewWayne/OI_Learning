#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int k, half, p[30], num[30];
long long R, maxn, temp, ans;
vector<long long> results;
void dfs1(int, int, long long);
void dfs2(int, int, long long);
int main(){
    scanf("%d%lld", &k, &R);
    for(int i = 1; i <= k; i++)
        scanf("%d", &p[i]), num[i] = (int)(log2(R)/log2(p[i]));

    half = k/2;
    sort(p+1, p+half+1);
    sort(p+half+1, p+k+1);
    dfs1(1, 0, 1);
    sort(results.begin(), results.end());
    dfs2(half+1, 0, 1);
    printf("%lld\n%lld", maxn, ans);
    return 0;
}
void dfs1(int at, int times, long long sum){
    if(sum > R) return;
    if(sum != 1){
        ans++;
        results.push_back(sum);
    }
    if(times + 1 <= num[at] && sum*p[at] <= R)
        dfs1(at, times+1, sum*p[at]);
    for(int i = at+1; i <= half && sum*p[i] <= R; i++)
        dfs1(i, 1, sum*p[i]);
}
void dfs2(int at, int times, long long sum){
    if(sum > R) return;
    if(sum != 1){
        ans++;
        temp = R / sum;
        long long pp = upper_bound(results.begin(), results.end(), temp) - results.begin() - 1;
        ans += pp+1;
        if(pp >= 0)
            maxn = max(maxn, results[pp] * sum);
    }
    if(times + 1 <= num[at] && sum * p[at] <= R)
        dfs2(at, times+1, sum*p[at]);
    for(int i = at+1; i <= k && sum*p[i] <= R; i++)
        dfs2(i, 1, sum*p[i]);
}
