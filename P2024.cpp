#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int dad[155000],rrank[155000],n,k,x,y,p,s;
int find(int x){
    return x==dad[x]?x:dad[x]=find(dad[x]);
}
void unionn(int u,int v){
    int fu=find(u),fv=find(v);
    if(fu==fv)
        return;
    if(rrank[fu]<rrank[fv])
        dad[fu]=fv;
    else{
        if(rrank[fu]==rrank[fv])
            rrank[fu]++;
        dad[fv]=fu;
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dad[i]=i;
        dad[i+n]=i+n;
        dad[i+2*n]=i+2*n;
    }
    memset(rrank,0,sizeof(rrank));
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&p,&x,&y);
        s++;
        if(x>n||y>n)continue;
        if(p==1){
            if(find(x)==find(y+n)||find(x+n)==find(y))//不能为补食关系
                continue;
            unionn(x,y);unionn(x+n,y+n);unionn(x+2*n,y+2*n);//是同类
            s--;
        }
        if(p==2){
            if(x==y||find(x)==find(y)||find(y)==find(x+2*n))//不能是同类，且y不能与吃x的在一个群系
                continue;
                unionn(x,y+2*n),unionn(x+n,y),unionn(x+2*n,y+n);//x的同类吃y，x的食物的同类是y，y的食物吃x(诡异的环状关系)
            s--;
        }
    }
    cout<<s;
    return 0;
}
