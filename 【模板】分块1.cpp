//这是个很fake的分块模板，只是可以块内区间查询，单点修改，主要是为了体验分块思想
//对n进行分块
//目的：实现单点修改，区间查询。
//注意：通过差分可以将其转化为区间修改，单点查询。
//时间复杂度: O(q√n)
#include <cstdio>
#include <iostream>
#include <cmath>
#define min(a,b) a<b?a:b
using namespace std;

const int maxn = 1e5+10;
const int maxsize = (int)sqrt(maxn);
int n, l, r, q, p,  opt, temp, size, c[110], a[maxn];

int getBlock(int x){
    return (x - 1) / size + 1;
}
int getStart(int b){
    return (b - 1) * size + 1;
}
int getEnd(int x){
    return min(n, getStart(x + 1) - 1);
}
void add(int pos,int val){
    a[pos] += val;
    c[getBlock(pos)] += val;
}
int query(int l, int r){
    int temp;
    if(getBlock(l) == getBlock(r)){
        for(int i = l; i <= r; i++){
            temp += a[i];
        }
    }
    else{
        for(int i = l; i <= getEnd(getBlock(l)); i++)
            temp += a[i];
        for(int i = r; i >= getStart(getBlock(r)); i--)
            temp += a[i];
        for(int i = getBlock(l) + 1; i <= getBlock(r) - 1; i++)
            temp += c[i];
    }
    return temp;
}


int main(){
    cin>> n >> q;
    size = (int)sqrt(n);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        c[getBlock(i)] += a[i];
    }
    while(q--){
        cin >> opt;
        if(opt){
            cin >> p >> temp;
            add(p, temp);
        }else{
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }
    return 0;
}
