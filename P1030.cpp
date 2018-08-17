#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char zhoxu[10];
char houxu[10];
int n,l,r;
void xianxu(int l1,int r1,int l2,int r2){
    if(l1==r1){
        printf("%c",zhoxu[l1]);
        return;
    }
    for(int i=0;i+l1<=r1;i++)
        if(zhoxu[i+l1]==houxu[r2]){
            printf("%c",houxu[r2]);
            xianxu(l1,l1+i-1,l2,r2-r1+l1+i-1);
            xianxu(l1+i+1,r1,l2+i,r2-1);
            break;
        }
}
int main(){
    cin>>zhoxu;
    cin>>houxu;
    int len=strlen(houxu);
    xianxu(0,len-1,0,len-1);
    return 0;
}
