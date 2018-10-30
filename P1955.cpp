//本题 hash 做法在BZOJ4195.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int MAXN = 1000100;
int dad[MAXN], ranks[MAXN], t, n, e, i[MAXN], j[MAXN], top, num;
map<int, int> func;
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
        memset(ranks,0,sizeof(ranks));
        top = num = 0;
        func.clear();
        ended = false;

        for(int kk = 1; kk <= n; kk++){
            scanf("%d%d%d", &i[0], &j[0], &e);
            int a = func[i[0]];
            if(a == 0)
                a = ++num, func[i[0]] = dad[a] = a;
            int b = func[j[0]];
            if(b == 0)
                b = ++num, func[j[0]] = dad[b] = b;
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
