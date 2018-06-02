#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int ntop,top,i=0;
char sym[30];
int num[30];
char in[30];
int pow(int di,int mi){
    int out=1;
    for(int i=1;i<=mi;i++){
        out*=di;
    }
    return out;
}
int npop(char symbol){
    int s=num[ntop--];
    int f=num[ntop];
    if(symbol=='+')num[ntop]=f+s;
    if(symbol=='-')num[ntop]=f-s;
    if(symbol=='*')num[ntop]=f*s;
    if(symbol=='/')num[ntop]=f/s;
    if(symbol=='^')num[ntop]=pow(f,s);
    top--;
    return 0;
}
int npush(){
    num[++ntop]=in[i]-'0';
    return 0;
}
int push(){
    sym[++top]=in[i];
    return 0;
}
int main(){
    int yx[200];
    yx['@']=0,yx['(']=0,yx['[']=0,yx['{']=0;
    yx['+']=1,yx['-']=1;
    yx['*']=2,yx['/']=2;
    yx['^']=3;
    scanf("%s",in);
    in[strlen(in)]='@';
    while(in[i]!='@'){
        if(in[i]-'0'>=0&&in[i]-'9'<=0)npush();
        else if(in[i]=='('||in[i]=='['||in[i]=='{')push();
        else if(in[i]==')'){while(sym[top]!='(')npop(sym[top]);top--;}
        else if(in[i]==']'){while(sym[top]!='[')npop(sym[top]);top--;}
        else if(in[i]=='}'){while(sym[top]!='{')npop(sym[top]);top--;}
        else if(yx[in[i]]>yx[sym[top]])push();
        else {while(yx[in[i]]<=yx[sym[top]])npop(sym[top]);push();}
        i++;
    }
    while(top>0){
        npop(sym[top]);
    }
    printf("%d",num[1]);
    return 0;
}





































