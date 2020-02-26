#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e4 + 10;
int l, n, m, d[maxn];
bool check(int x){
    int cnt = 0;
    int len = 0;
    for(int i = 1; i <= n+1; i++){
        int j = i-1;
        while(d[i] - d[j] < x && i <= n+1){ i++, cnt++;}
        if(cnt > m) return false;
    }
    return true;
}
int main(){
    scanf("%d%d%d", &l, &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", d+i);
    d[n+1] = l;
    int len = 0;
    for(int i = 30; i >= 0; i--){
        if(check(len + (1 << i)))
            len += (1 << i);
    }
    printf("%d\n", len);
    return 0;
}
