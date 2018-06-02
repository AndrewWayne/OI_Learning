#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int main(){
    long int b,b1,p,p1,k,s=1;
    scanf("%ld%ld%ld",&b,&p,&k);
    b1=b;
    p1=p;
    b=b%k;
    if(p==0){
        s=1%k;
        printf("%ld^%ld mod %ld=%ld",b1,p1,k,s);
        return 0;
    }
    while(p>0){
        if(p%2==1)s=(s*b)%k;
        p=p/2;
        b=(b*b)%k;
    }
    printf("%ld^%ld mod %ld=%ld",b1,p1,k,s);
    return 0;
}
