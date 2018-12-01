#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
const int maxa = 40010;
int t, n, a[maxn], anss[maxn], stack[maxa], top, val;
bool used[maxa];
int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        memset(used, 0, sizeof(used));
        top = 0;
        val = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        for(int i = 1; i <= n; i++){
            if(used[a[i]]) continue;
            used[a[i]] = true;
            val++;
            stack[++top] = a[i];
        //    cerr << a[i] <<endl;
            for(int j = 1; j <= top; j++)
                if(stack[j] + a[i] <= a[n] && !used[stack[j] + a[i]])
                    stack[++top] = stack[j] + a[i], used[stack[j] + a[i]] = true;//, cerr << "#" << stack[top] << endl;
        }
        printf("%d\n", val);
    }
    return 0;
}
