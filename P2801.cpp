//老老实实序列分块
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define min(a,b) a<b?a:b
using namespace std;

const int maxn = 1e6+10;
const int maxsize = 5000;
long long n, q, l, r, val, size, start[maxsize], belong[maxn], tag[maxsize], a1[maxn], a2[maxn];
char opt[5];

int getBlock(int x){
    if(belong[x] == 0)
        return belong[x] = (x - 1) / size + 1;
    return belong[x];
}
int getStart(int b){
    if(start[b] == 0)
        return start[b] = (b - 1) * size + 1
    return start[b];
}
int getEnd(int x){
    return min(n, getStart(x + 1) - 1);
}
void init(int x){
    for(int i = getStart(x); i <= getEnd(x); i++)
        a2[i] = a1[i];
    sort(a2 + getStart(x), a2 + getEnd(x) + 1);//O(SlogS)的复杂度
}
void add(int L, int R, long long val){//O(q*(SlogS))
    if(getBlock(L) == getBlock(R)){
        for(int i = L;  i <= R; i++)
            a1[i] += val;
        init(getBlock(L));
    }else{
        for(int i = L; i <= getEnd(getBlock(L)); i++)
            a1[i] += val;//左边零散块
        init(getBlock(L));
        for(int i = getStart(getBlock(R)); i <= R; i++)
            a1[i] += val;//右边零散块
        init(getBlock(R));//O(SlogS)
        for(int i = getBlock(L) + 1; i <= getBlock(R) - 1; i++)
            tag[i] += val;//针对完整块打标记
    }
}
int query(int L, int R, int C){//O(q*(N/S)logS)
    long long ans = 0;
    int block_l = getBlock(L);
    int block_r = getBlock(R);
    if(block_l == block_r){
        for(int i = L; i <= R; i++)
            ans += (a1[i] + tag[block_l] >= C);//零散块直接暴力
    }
    else{
        for(int i = L; i <= getEnd(block_l); i++)
            ans += (a1[i] + tag[block_l] >= C);//左边
        for(int i = R; i >= getStart(block_r); i--)
            ans += (a1[i] + tag[block_r] >= C);//右边
        for(int i = block_l + 1; i <= block_r - 1; i++)
            ans += (&a2[getEnd(i)]) - lower_bound(a2 + getStart(i), a2 + getEnd(i) + 1, C - tag[i]) + 1;//O((N/S)logS)
    }
    return ans;
}


int main(){
    cin>> n >> q;
    size = (int)sqrt(n*log2(n));
    for(int i = 1; i <= n; i++)
        cin >> a1[i];
    int EndBlock = getBlock(n);
    for(int i = 1; i <= EndBlock; i++)//O(NlogS)
        init(i);
    while(q--){
        cin >> opt;
        if(opt[0] == 'M'){
            cin >> l >> r >> val;
            add(l, r, val);
        }else{
            cin >> l >> r >> val;
            cout << query(l, r, val) << endl;
        }
    }
    return 0;
}
