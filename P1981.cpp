#include <cstdio>
#include <iostream>
using namespace std;
int yx[255],symbol[100010];
int top1,top2;
char sym;
long long int stack[100010];
int main(){
    freopen("xx.in","r",stdin);
    freopen("xx.out","w",stdout);
    yx['+']=1;
    yx['*']=2;
    cin>>stack[++top2];
    stack[top2-1]%=10000;
    while(cin>>sym){
        if(top1==0)
            symbol[++top1]=yx[sym];
        else{
            if(yx[sym]>symbol[top1])
                symbol[++top1]=yx[sym];
            else{
                while(symbol[top1--]>=yx[sym]){
                    if(symbol[top1+1]==1)
                        stack[top2-1]=(stack[top2]+stack[top2-1])%10000;
                    if(symbol[top1+1]==2)
                        stack[top2-1]=(stack[top2]*stack[top2-1])%10000;
                    top2--;
                }
                top1+=2;
                symbol[top1]=yx[sym];
            }
        }
        cin>>stack[++top2];
        stack[top2-1]%=10000;
    }
    while(top1-->0){
        if(symbol[top1+1]==1)
            stack[top2-1]=(stack[top2]+stack[top2-1])%10000;
        if(symbol[top1+1]==2)
            stack[top2-1]=(stack[top2]*stack[top2-1])%10000;
        top2--;
    }
    cout<<stack[1]%10000;
    return 0;
}
