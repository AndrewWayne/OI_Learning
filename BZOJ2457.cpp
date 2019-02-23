#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;
int n,Min[maxn], Max[maxn], nxt[maxn], ans; // nxt[i]表示i位置之后和elemet[i]数值相同的的最后一个元素的位置+1
bool stat; // stat = 0递减, stat = 1 递增
pii elemet[maxn];
bool cmp(pii a, pii b){
    return a.first < b.first;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> elemet[i].first, elemet[i].second = i;
    sort(elemet+1, elemet+1+n, cmp);
    for(int i = n; i >= 1; i--){
        if(nxt[i] == 0)
            nxt[i] = i+1, Min[i] = elemet[i].second, Max[i] = elemet[i].second;
        if(elemet[i-1].first == elemet[i].first)
            nxt[i-1] = nxt[i], Min[i-1] = min(elemet[i-1].second, Min[i]), Max[i-1] = max(elemet[i-1].second, Max[i]);
    }
    int key = Min[1];//初始状态递减
    ans = 1;//每将一个递增转变为递减则答案加一
    for(int i = nxt[1]; i <= n; i = nxt[i]){
        int a = Max[i]; int b = Min[i];
        if(!stat) if(a < key) key = b; else key = a, stat ^= 1;
        else if(b > key) key = a; else key = b, stat ^= 1, ans++;
    }
    cout << ans << endl;
    return 0;
}
