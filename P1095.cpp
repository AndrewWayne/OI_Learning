#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxx(a,b) a>b?a:b
using namespace std;
int m,s,t,ans=0,f[300010];
int main(){
    cin>> m>>s >> t;
    for(int i=1; i<=t ;i++){
        if(m>=10 )f[i ]=f[i-1]+60,m-=10;
        else f[i ]=f[i-1],m+=4;
    }
    for(int i=1;i<=t; i++){
        f[i ]= maxx(f[i-1]+17,f[i]);
        if( f[i] >=s){printf("Yes\n%d", i); return 0;}
    }
    printf( "No\n%d", f[t]);
    return 0;
}
