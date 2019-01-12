#include <cstdio>
#include <iostream>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int a, b, c, ans;
int main(){
    cin >> a >> b >> c;
    cout << 3 * min(a+1, min(b, c-1));
    return 0;
}
