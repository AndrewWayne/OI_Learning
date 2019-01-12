#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, len, sum[10000], val, cnt;
int main(){
    while(cin >> n){
    val = n * (n+1) /2;
    cerr << val << endl;
    len = 1;
    cnt = 0;
    memset(sum, 0, sizeof(sum));
    for(int i = 2 ; i <= n; i++)
        len *= i;
    len *= n;
    cerr << len << endl;
    for(int i = 1; i <= len; i++)
        sum[i] = sum[i-1] + i;
    for(int i = 1; i <= len; i++)
        for(int j = i; j <= len; j++){
            cerr << sum[j]-sum[i-1] << "#" << i << " " << j <<endl;
            if(sum[j]-sum[i-1] == val)
                cnt++;
        }
    cout << cnt << endl;
    }
    return 0;
}
