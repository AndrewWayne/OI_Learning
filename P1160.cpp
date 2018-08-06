#include <cstdio>
#include <iostream>
using namespace std;
struct node{
    int nxt,front;
}tab[100010];
int head,n,k,p,m,x;
void addleft(int i,int k){
  int u=tab[k].front;
  tab[u].nxt=i;
  tab[i].front=u;
  tab[i].nxt=k;
  tab[k].front=i;
}
void addright(int i,int k){
  int u=tab[k].nxt;
  tab[k].nxt=i;
  tab[i].front=k;
  tab[i].nxt=u;
  tab[u].front=i;
}
void delet(int x){
  int u=tab[x].front;
  int v=tab[x].nxt;
  tab[x].front=0;
  tab[x].to=0;
  tab[u].nxt=v;
  tab[v].front=u;
}
int main(){
    cin>>n;
    head=1;
    for(int i=2;i<=n;i++){
      cin>>k>>p;
      if(p==0){
        addleft(i,k);
        if(k==head)
          head=i;
      }
      if(p==1)
        addright(i,k);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
      cin>>x;
      if(x==head)
        head=tab[x].to
      delet(x);
    }
    int x=head;
    while(tab[x].to!=0){
      cout<<x<<" ";
      x=tab[x].to;
    }
    cout<<x<<endl;
    return 0;
}
