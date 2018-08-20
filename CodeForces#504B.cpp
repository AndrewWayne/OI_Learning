#include <cstdio>
#include <iostream>
using namespace std;
long long n,k,t;
int main(){
    cin>>n>>k;
    t=!(k&1);
    k=((k>n+(n-1))?0:(k>n+1?k/2-k+1+n-t:k/2-t));
    cout<<k;
    return 0;
}
