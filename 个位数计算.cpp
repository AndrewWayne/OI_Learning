#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
char in[30],stack[30],out[30];
int stop=0;
int outtop=-1;
void spush(int &top,char a){
    stack[++top]=a;
}
void pop(int &top){
    out[++outtop]=stack[top];
    top--;
}
int pow(int di,int mi){
    int outs=1;
    for(int i=1;i<=mi;i++){
        outs*=di;
    }
    return outs;
}
int hahahaha(char* func){
    int s,f,stacks[30],top=0;
    for(int i=0;i<strlen(func);i++){
        if(func[i]-'0'>=0&&func[i]-'9'<=0){
            stacks[++top]=func[i]-'0';continue;}
        s=stacks[top];
        f=stacks[--top];
        if(func[i]=='+')
            stacks[top]=f+s;
        if(func[i]=='-')
            stacks[top]=f-s;
        if(func[i]=='*')
            stacks[top]=f*s;
        if(func[i]=='/')
            stacks[top]=f/s;
        if(func[i]=='^')
            stacks[top]=pow(f,s);
    }
    printf("%d",stacks[1]);
    return 0;
}

void Calc(int begin,int end){
    for (int i=begin+1; i<end; i++) {
        if (in[i]=='{') for (int j=i; j<=end; j++) if (in[j]=='}')Calc(i,j);
        if (in[i]=='[') for (int j=i; j<=end; j++) if (in[j]==']')Calc(i,j);
        if (in[i]=='(') for (int j=i; j<=end; j++) if (in[j]==')')Calc(i,j);
        if (in[i]=='^') spush(stop,in[i]);
        if (in[i]=='+'){
            while(stop>0)
                pop(stop);
            spush(stop,in[i]);
        }
        if (in[i]=='-'){
            while(stop>0)
                pop(stop);
            spush(stop,in[i]);
        }
        if (in[i]=='*'){
            while(stop>0||(stack[stop]!='+'&&stack[stop]!='-'))
                pop(stop);
            spush(stop,in[i]);
        }
        if (in[i]=='/'){
            while(stop>0||(stack[stop]!='+'&&stack[stop]!='-'))
                pop(stop);
            spush(stop,in[i]);
        }
        if (in[i]-'0'>=0&&in[i]-'9'<=0) out[++outtop]=in[i];
    }
    while(stop>0)
        pop(stop);
}

int main(){
    scanf("%s",in);
    Calc(-1,strlen(in));
    hahahaha(out);
}
