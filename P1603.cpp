#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string num[30]={"0","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int func_num[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
string word;
bool flag;
int n,top,a[7];
int main(){
    for(int i=1;i<=6;i++){
        cin>>word;
        for(int i=1;i<=26;i++)
            if(!word.compare(num[i])){
                a[++top]=func_num[i];
                break;
            }
    }
    sort(a+1,a+1+top);
    for(int i=1;i<=top;i++){
        if(flag)
            printf("%.2d",a[i]);
        else
            if(a[i]!=0){
                printf("%d",a[i]);
                flag=true;
            }
    }
    if(!flag)printf("0");
    return 0;
}
