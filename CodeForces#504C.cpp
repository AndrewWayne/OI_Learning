#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int maxn=2e5+50;
int n,k,top;
string str;
int main(){
    cin>>n>>k;
    cin>>str;
    for(int i=0;i<n&&k>0;i++){
      if(str[i]=='(')
        if(++top==1){
          k--;
          str.erase(i);
        }
      else
        if(--top==0){
          k--;
          str.erase(i);
          i=0;
        }
    }
    printf("%d",k);
    return 0;
}
