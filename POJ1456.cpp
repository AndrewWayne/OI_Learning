#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 10;
int n, dad[maxn], ranks[maxn], ans;
struct Store{
    int profit, day;
    bool operator <(const Store v)const{
        return profit > v.profit;
    }
} things[maxn];

int find(int x){
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}
void unionn(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu == fv) return;
    dad[fu] = fv;
}
int main(){
    while(~scanf("%d", &n)){
        ans = 0;
        dad[0] = 0;
        ranks[0] = 1e4+10;
        for(int i = 0; i <= 1e4+5; i++)
            dad[i] = i, ranks[i] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &things[i].profit, &things[i].day);

        sort(things+1, things+1+n);

        for(int i = 1; i <= n; i++){
            int root = find(things[i].day);
            if(root != 0)
                unionn(root, root-1), ans += things[i].profit;
        }

        printf("%d\n", ans);
    }
    return 0;
}
