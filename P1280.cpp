#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a,b) a>b?a:b
using namespace std;
struct node{int start,end;} tasks[10010];
int n,k,task,f[10010];
bool cmp(node a,node b){return a.start>b.start;}
int main(){
    memset(f,0,sizeof(f));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&tasks[i].start,&task);
        tasks[i].end=tasks[i].start+task;
    }
    int top=k;
    for(int i=n;i>=1;i--){
        if(tasks[top].start!=i)f[i]=f[i+1]+1;
        else{
            while(tasks[top].start==i){
                if(f[tasks[top].end]>f[i])f[i]=f[tasks[top].end];
                top--;
            }
        }
    }
    printf("%d",f[1]);
    return 0;
}
