#include <cstdio>
#include <iostream>
using namespace std;
int n,k,e[11];
struct node{
  int id,w;
  bool operator<(node &v) const{
    if(w==v.w)return id<v.id;
    return w>v.w;
  }
}man[20020];
int main(){
  cin>>n>>k;
  for(int i=1;i<=10)
    cin>>e[i];
  for(int i=1;i<=n;i++)
    cin>>man[i].w;
  sort(man+1,man+1+n);
  for(int i=1;i<=n;i++)
    man[i].w+=e[(i-1)%10+1];
  sort(man+1,man+1+n);
  for(int i=1;i<=k;i++)
    cout<<man[i].id<<" ";
  return 0;
}
