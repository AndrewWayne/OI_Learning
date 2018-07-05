#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
char func[999];
int s,f,top=0;
int stack[999];
int pow(int di,int mi){
    int out=1;
    for(int i=1;i<=mi;i++){
        out*=di;
    }
    return out;
}
void calc(){
    for(int i=0;func[i]!='@';i++){
        if(func[i]-'0'>=0&&func[i]-'9'<=0){
            int k=func[i]-'0';
            i++;
            while(func[i]!='.'){
                k=k*10+(func[i]-'0');
                i++;
            }
            stack[++top]=k;
            continue;
        }
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
}
int main(){
    scanf("%s",func);
    calc();
    printf("%d",stack[1]);
    return 0;
}
