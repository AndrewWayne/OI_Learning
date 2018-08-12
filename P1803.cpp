#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,ans,right;
struct match{
  int left,right;
  bool operator<(const match &v)const{
    if(right==v.right)
      return left>v.left;
    return right<v.right;
  }
}game[1000100];
int main(){
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>game[i].left<<game[i].right;
  sort(game[i]+1,game+1+n);
  for(int i=1;i<=n;i++)
    if(game[i].left>=right)
      ans++,right=game[i].right;
  cout<<ans;
}
