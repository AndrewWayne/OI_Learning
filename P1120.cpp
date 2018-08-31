#include <cstdio>
#include <iostream>
#include <algorithm>
#define max(a,b) a>b?a:b
using namespace std;
int n,m,stick[66],nnext[66],len,maxlen,sum,top;
bool endss,used[66];
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
bool cmp(int a,int b){
    return a>b;
}
inline void dfs(int k,int last,int rest){//k为拼了几根，last为上一根的编号，rest为这根剩多长
    register int i;
    if(!rest){
        if(k==m){endss=1; return;}
        for(i=1;i<=top;i++)
            if(!used[i]) break;
        used[i]=1;
        dfs(k+1,i,len-stick[i]);
        used[i]=0;
        if(endss) return;
    }
    for(i=lower_bound(stick+last+1,stick+top+1,rest,greater<int>())-stick;i<=top;i++){
        if(!used[i]){
            used[i]=1;
            dfs(k,i,rest-stick[i]);
            used[i]=0;
            if(endss) return;
            if(rest==stick[i] || rest==len) return;
            i=nnext[i];
            if(i==top) return;
        }
    }
}
int main(){
    endss=false;
    n=read();
    for(int i=1;i<=n;i++){
        len=read();
        if(len>50)continue;
        sum+=len;
        stick[++top]=len;
    }
    sort(stick+1,stick+1+top,cmp);
    maxlen=stick[1];
    nnext[top]=top;
    for(int i=top-1;i>0;i--)
        if(stick[i]==stick[i+1]) nnext[i]=nnext[i+1];
        else nnext[i]=i;
    for(len=maxlen;len<=sum/2;len++){
        if(sum%len==0){
            m=sum/len;
            endss=0;
            used[1]=1;
            dfs(1,1,len-stick[1]);
            used[1]=0;
            if(endss){printf("%d\n",len); return 0;}
        }
    }
    if(!endss)
        cout<<sum;
    return 0;
}
