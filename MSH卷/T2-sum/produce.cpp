#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  srand((unsigned)time(NULL));
  freopen("sum.in","w",stdout);
  int n,k;
  n=rand()%1000+1;
  k=rand()%1000+1;
  cout<<n<<" "<<k;
  return 0;
}
