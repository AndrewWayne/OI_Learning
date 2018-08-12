#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=3e4;
long long n,p,inv[maxn];
int main(){
    cin>>n>>p;
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<=n;i++)
        inv[i]=(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;i++)
        printf("%d\n",inv[i]);
    return 0;
}
