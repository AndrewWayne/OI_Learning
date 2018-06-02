#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
void push(int a);
char pop(void);
char stack[20];
int top=0;
int main(){
    int n,r;
    int mod=-1,times=0;
    memset(stack, 0, sizeof(stack));
    scanf("%d%d",&n,&r);
    printf("%d=",n);
    for(int i=0;n!=0;i++){
        times=n/r;
        mod=n-times*r;
        while(mod<0){
            times++;
            mod=n-times*r;
        }
        push(mod);
        n=times;
    }
    while(top>=1)
        printf("%c",pop());
    printf("(base%d)",r);
}
void push(int a){
    if(a<10)stack[++top]='0'+a;
    else stack[++top]='A'+a-10;
}
char pop(){
    return stack[top--];
}
