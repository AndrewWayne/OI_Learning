#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int pow(int di,int mi){
    int out=1;
    for(int i=1;i<=mi;i++){
        out*=di;
    }
    return out;
}
int main(){
    char func[999];
    int s,f,top=0;
    int stack[999];
    
    scanf("%s",func);
    for(int i=0;i<strlen(func);i++){
        if(func[i]-'0'>=0&&func[i]-'9'<=0){
            stack[++top]=func[i]-'0';continue;}
        
        s=stack[top];
        f=stack[--top];
        if(func[i]=='+')
            stack[top]=f+s;
        if(func[i]=='-')
            stack[top]=f-s;
        if(func[i]=='*')
            stack[top]=f*s;
        if(func[i]=='/')
            stack[top]=f/s;
        if(func[i]=='^')
            stack[top]=pow(f,s);
    }
    printf("%d",stack[1]);
    return 0;
}
