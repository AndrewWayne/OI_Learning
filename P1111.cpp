#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXM = 1e5+10;
const int MAXN = 1e3+10;
struct Road{
    int u, v, t;
    bool operator<(const Road &y)const{
        return t < y.t;
    }
} roads[MAXM];
int n, m, dad[MAXN], ranks[MAXN], sum;
int find(int x){
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}

void unionn(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu == fv) return;
    ranks[fu] > ranks[fv] ? dad[fv] = fu : dad[fu] = fv, ranks[fv] += (ranks[fu] == ranks[fv]);
 }

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d%d", &roads[i].u, &roads[i].v, &roads[i].t);
    for(int i = 1; i <= n; i++)
        dad[i] = i, ranks[i] = 0;

    sort(roads+1, roads+1+m);

    for(int i = 1; i <= m && sum < n-1; i++){
        if( find(roads[i].u) == find(roads[i].v) )
            continue;
        unionn(roads[i].u, roads[i].v);
        sum++;
        if(sum == n-1){
            printf("%d", roads[i].t);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
