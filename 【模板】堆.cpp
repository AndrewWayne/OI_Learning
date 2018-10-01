#include <cstdio>
#include <iostream>
#define swap(u,v) u^=v^=u^=v
using namespace std;
const int maxn=1e6+10;
int heap[maxn],top;
void put(int x){
  heap[++top]=x;
  int k=top;
  while(heap[k>>1]<heap[k]){ // <为大根堆
    swap(heap[k>>1],heap[k]);
    k>>=1;
  }
}
void del(){
  heap[1]=heap[top--];
  int k=1;
  while((k<<1)<=top){
    int next=k<<1;
    if(heap[next+1]>heap[next])next++;// > 为大根堆
    if(heap[k]>=heap[next])return;// >= 为大根堆
    swap(heap[k],heap[next]);
    k=next;
  }
}
int get(){
  return heap[1];
}
int n,p,x;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&p);
    if(p==1){
      scanf("%d",&x);
      put(x);
    }else if(p==2)
      printf("%d\n", get());
    else
      del();
  }
  return 0;
}
