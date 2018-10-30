//本题 map 做法在P1955.cpp
//NOI2015 最简单的一次NOI的最简单的一题
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int MAXN = 19260817;
int dad[MAXN], ranks[MAXN], t, n, e, i[MAXN], j[MAXN], top, num;
bool used[MAXN];
bool ended;
int find(int x){
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}
void unionn(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if( fu == fv ) return;
    if(ranks[fu] > ranks[fv])
        dad[fv] = fu;
    else {
        dad[fu] = fv;
        ranks[fv] += (ranks[fu] == ranks[fv]);
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(used,0,sizeof(used));
        top = 0;
        ended = false;

        for(int kk = 1; kk <= n; kk++){
            scanf("%d%d%d", &i[0], &j[0], &e);
            int a = i[0] % 19260817;
            if(!used[a])
                used[a] = 1, ranks[a] = 0, dad[a] = a;
            int b = j[0] % 19260817;
            if(!used[b])
                used[b] = 1, ranks[b] = 0, dad[b] = b;
            if(e == 1)
                unionn(a, b);
            else
                i[++top] = a, j[top] = b;
        }

        while(top--)
            if(find(i[top+1]) == find(j[top+1]) || i[top+1] == j[top+1]){
                ended = true;
                break;
            }

        if(ended)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
