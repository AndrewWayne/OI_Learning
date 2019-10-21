#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x7f7f7f7f;
typedef long long ll;
typedef pair<int, int> pii;
int n, a[maxn], x, y;
ll ans, minv[maxn], dad[maxn], maxv[maxn], size[maxn];
vector<pair<int, pii> > MAXT, MINT;
int find(int x){return dad[x] == x ? x : dad[x] = find(dad[x]);}
void unionn(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    dad[fx] = fy;
    size[fy] += size[fx];
    size[fx] = 0;
}

int main(){

    scanf("%d", &n);
    int minx = INF, rt = n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        //if(a[i] < minx) minx = a[i], rt = i;
    }
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        MAXT.push_back(make_pair(max(a[x], a[y]), make_pair(x, y)));
        MINT.push_back(make_pair(min(a[x], a[y]), make_pair(x, y)));
    }
    sort(MAXT.begin(), MAXT.end());
    for(int i = 1; i <= n; i++) dad[i] = i, size[i] = 1;
    for(auto i = MAXT.begin(); i != MAXT.end(); i++){
        int fu = find(i -> second.first), fv = find(i -> second.second);
        ans += (ll)(i -> first) * size[fu] * size[fv];
        //cerr << size[fu] << " " << size[fv] << endl;
        unionn(fu, fv);
    }
    sort(MINT.begin(), MINT.end());
    for(int i = 1; i <= n; i++) dad[i] = i, size[i] = 1;
    for(int i = MINT.size() - 1; i >= 0; i--){
        int fu = find(MINT[i].second.first), fv = find(MINT[i].second.second);
        ans -= (ll)(MINT[i].first) * size[fu] * size[fv];
        unionn(fu,
            fv);
    }
    printf("%lld\n", ans);
}
