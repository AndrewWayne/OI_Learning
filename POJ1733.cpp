#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e9 +10;
const int maxm = 1e4 +10;
struct Query{
    int l, r;
    bool mode;
}query[maxm];
int n, m, top, ranks[4*maxm], dad[4*maxm], sum;
map<int, int> func;
int find(int x){
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}
void unionn(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu == fv) return;
    if(ranks[fu] > ranks[fv])
        dad[fv] = fu;
    else
        dad[fu] = fv, ranks[fv] += (ranks[fu] == ranks[fv]);
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        func.clear();
        for(int i = 1; i <= 4*m; i++){
            dad[i] = i;
            ranks[i] = 0;
        }

        for(int i = 1; i <= m; i++){
            char temp[5];
            scanf("%d%d%s", &query[i].l, &query[i].r, temp);
            query[i].mode = (temp[0] == 'o');//读入

            if(!func[query[i].l-1])
                func[query[i].l-1] = ++sum;
            if(!func[query[i].r])
                func[query[i].r] = ++sum;//离散化
        }

        for(int i = 1; i <= m; i++){
            int u1 = 2 * func[query[i].l-1];
            int u2 = u1 - 1;
            int v1 = 2 * func[query[i].r];
            int v2 = v1 - 1;
            if(query[i].mode){
                unionn(u1, v2);
                unionn(u2, v1);
            }else{
                unionn(u1, v1);
                unionn(u2, v2);
            }
            if( find(u1) == find(u2) ){
                m = i-1;
                break;
            }
        }
        printf("%d\n", m);
    }
    return 0;
}
