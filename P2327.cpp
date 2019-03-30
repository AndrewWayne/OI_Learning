#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e4 + 10;
int n, a[maxn], f[maxn][8];
bool dfs(int at, int stat){
    int val = a[at];
    for(int i = 0; i <= 2; i++)
        val -= (stat >> i) &1;
    if(val > 2 || val < 0)
        return false;
    int temp = (stat << 1) &7;
    for(int i = 0; i <= val; i++){
        
    }

}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0);
    return 0;
}
