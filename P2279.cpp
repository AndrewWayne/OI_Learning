#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, father[1010], grand[1010], depth[1010], node[1010], dis[1010];
bool visit[1010];
bool cmp(int a,int b){
    return depth[a] > depth[b];
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        node[i] = i,dis[i] = 2020;
    father[1] = 1;
    depth[1] = 1;
    for(int i = 2; i <= n; i++){
        scanf("%d",&father[i]);
        depth[i] = depth[father[i]] + 1;
    }
    for(int i = 1; i <= n; i++)
        grand[i] = father[father[i]];

    sort(node+1, node+1+n, cmp);

    for(int i = 1; i <= n; i++){
        dis[node[i]] = min( dis[node[i]], min(dis[grand[node[i]]] + 2, dis[father[node[i]]] + 1));
        if( dis[node[i]] > 2 ){
            dis[grand[node[i]]] = 0;
            ans++;
            dis[grand[grand[node[i]]]] = min( dis[grand[grand[node[i]]]], 2);
            dis[father[grand[node[i]]]] = min( dis[father[grand[node[i]]]], 1);
        }
    }

    printf("%d", ans);

    return 0;
}
