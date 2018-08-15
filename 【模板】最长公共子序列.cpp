#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int func[100100],ANS[100100],n,temp;//离散化...(LIS之前只会n^2抱头痛哭)
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&temp);
    func[temp]=i;
    ANS=0x7ffffff;
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&temp);
    int x=func[temp];
    *lower_bound(ANS+1,ANS+n+1,x)=x;
  }
  printf("%d",lower_bound(b+1,b+n+1,0x7ffffff)-b-1);
  return 0;
}
