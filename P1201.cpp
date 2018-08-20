#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int n,have,ngi,gift;
string name[20],from,to;
map<string,int> book;
int main(){
  cin>>n
  for(int i=1;i<=n;i++)
    cin>>name[i],book[name[i]]=0;
  for(int i=1;i<=n+1;i++){
    cin>>from;
    cin>>have>>ngi;
    if(ngi==0)continue;
    gift=have/ngi;
    for(int i=1;i<=ngi;i++)
      cin>>to,book[to]+=gift,book[from]-=gift;
  }
  for(int i=1;i<=n;i++)
    cout<<name[i]<<" "<<book[name[i]]<<endl;
  return 0;
}
