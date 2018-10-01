#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 30030;
int t;
char command;
int dad[maxn],sum[maxn],size[maxn],u,v;
int find(int x){
    if(dad[x] == x) return x;
    int father = find(dad[x]);
    sum[x] += sum[dad[x]];
    return dad[x] = father;
}
inline int c(int i,int j){
    if(find(i)!=find(j))return -1;
    if(sum[i]>sum[j])
        return sum[i] - sum[j] - 1;
    return sum[j] - sum[i] -1;
}
void unionn(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if( fu != fv ){
        sum[fu] += size[fv];
        dad[fu] = fv;
        size[fv] += size[fu];
        size[fu] = 0;
    }
}

int main(){
    scanf("%d\n",&t);
    for(int i = 1; i <= 30000 ; i++)
        dad[i]=i,size[i]=1;
    while(t--){
        scanf("%c %d %d\n",&command,&u,&v);
        if(command == 'M') unionn(u,v);
        if(command == 'C') printf("%d\n",c(u,v));
    }
    return 0;
}
