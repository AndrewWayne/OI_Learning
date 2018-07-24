// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <algorithm>
#define max(a,b) a>b?a:b
using namespace std;
int n,stick[66],len,maxlen,sum,top;
bool endss,use[66];
bool cmp(int a,int b){
  return a>b;
}
void dfs(int rest,int sums,int want,int id){
    if(endss)return;
    if(sums*want==sum){
        cout<<want;
        endss=true;
        return;
    }
//    if(sum+rest-want<stick[1])return;
    if(rest==0){dfs(want,sums+1,want,top);return;}
    for(int i=1;i<=top;i++)
        if(!use[i]&&rest-stick[i]>=0){
            use[i]=true;
            dfs(rest-stick[i],sums,want,id+1);
            use[i]=0;
            if(rest-stick[i]==0||rest==want)break;
            while(stick[i]==stick[i+1])i++;
        }
}
int main(){
    endss=false;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len;
        if(len>50)continue;
        sum+=len;
        stick[++top]=len;
    }
    sort(stick+1,stick+1+top,cmp);
    maxlen=stick[top];
    for(int i=maxlen;i<=sum/2;i++)
        if(sum%i==0)dfs(i,0,i,top);
    if(!endss)
        cout<<sum;
    return 0;
}
