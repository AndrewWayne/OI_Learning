#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
double source[1000001],temp;
int n;
map<double,int>o2o;
int main(){
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>source[i];
  for(int i=1;i<=n;i++){
    cin>>temp;
    o2o[temp]=i;
  }
  for(int i=1;i<=n;i++)
    cout<<o2o[source[i]]<<" ";
  return 0;
}
