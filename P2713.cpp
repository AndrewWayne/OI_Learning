#include <cstdio>
#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, x, y;
int dad[maxn], died[maxn], num[maxn], ranks[maxn];
char opt;
struct cmp1{
    bool operator() (pair<int, int> a, pair<int, int> b){
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};
__gnu_pbds::priority_queue <pair<int,int> , cmp1> heap[maxn];
int find(int x){
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}
void unionn(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu == fv)
        return ;
    if(ranks[fu] > ranks[fv]){
        dad[fv] = fu;
        heap[fu].join(heap[fv]);
    }
    else{
        dad[fu] = fv;
        heap[fv].join(heap[fu]);
        ranks[fv] += (ranks[fu] == ranks[fv]);
    }

}
int main(){
    cin >> n ;
    for(int i = 1; i <= n; i++){
        cin >> x;
        num[i] = x;
        dad[i] = i;
        heap[i].push(make_pair(i, x));
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> opt >> x;
        if(opt == 'M'){
            cin >> y;
            if(died[x] || died[y] || find(x) == find(y))
                continue;
            else
                unionn(x, y);
        }else{
            if(died[x]){
                cout << 0 << endl;
                continue;
            }
            cout << heap[find(x)].top().second << endl;
            died[heap[find(x)].top().first] = 1;
            heap[find(x)].pop();
        }
    }

    return 0;
}
