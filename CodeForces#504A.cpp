#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=2e5+20;
char str1[maxn],str2[maxn];
int n,m,h,t1,t2;
bool righ=true,has=false;
int main(){
    righ=true;
    cin>>n>>m;
    if(n-m>1)righ=false;
    cin>>str1>>str2;
    for(int i=0;i<n;i++){
      has|=str1[i]=='*';
    }
    if(!has){
      if(n!=m)righ=false;
      righ&=(!strcmp(str1,str2));
      goto finish;
    }
    if(!strcmp(str1,"*")){
        printf("YES");
        return 0;
    }
    t1=n-1,t2=m-1;
    while(str1[h+1]!='*'&&h<=t1&&righ)
        righ&=(str1[h]==str2[h++]);
    while((t2>h)&&(t1>h+1)&&righ)
        righ&=(str1[t1--]==str2[t2--]);
    finish:
    if(righ)
        printf("YES");
    else
        printf("NO");
    return 0;
}
