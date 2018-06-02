#include <stdio.h>
#include <string.h>
int max(int a,int b){
    if(a>b)return a;
    else{
        return b;
    }
}
int v[60],w[60],q[60];
int value(int index){
    return v[index]*w[index];
}
int main(){
    int i,j;
    int m,n;
    memset(v,0,sizeof(v));
    memset(w,0,sizeof(w));
    memset(q,0,sizeof(q));
    int sum[32000];
    scanf("%d%d",&n,&m);
    for (i = 0; i < m; ++i)scanf("%d%d%d",&v[i],&w[i],&q[i]);
    for(i=0;i<m;++i){
        int k[2]={0,0};
        int index=0;
        if(q[i])continue;
        for (j = 0; j < m; ++j)
        {
            if(q[j]==i+1)k[++index-1]=j;
            if(index==2)break;
        }
        
        for (j = n; j >= v[i]; --j)
        {
            sum[j]=max(sum[j],sum[j-v[i]]+value(i));
            if(k[0]&&v[i]+v[k[0]]<=j)sum[j]=max(sum[j],sum[j-v[k[0]]-v[i]]+value(i)+value(k[0]));
            if(k[1]&&v[i]+v[k[1]]<=j)sum[j]=max(sum[j],sum[j-v[k[1]]-v[i]]+value(i)+value(k[1]));
            if(k[1]&&k[0]&&v[i]+v[k[1]]+v[k[0]]<=j)sum[j]=max(sum[j],sum[j-v[i]-v[k[0]]-v[k[1]]]+value(i)+value(k[0])+value(k[1]));
        }
    }
    printf("%d",sum[n]);
}

