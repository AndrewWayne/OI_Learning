#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxx(a,b) a>b?a:b
using namespace std;
int n,score,ans;
int matrix[550][550];
int main(){
  cin>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n-i；j++){
      cin>>score;
      matrix[i][j+i]=matrix[j+i][i]=score;
    }
  for(int i=1;i<=n;i++){
    sort(matrix[i]+1,matrix[i]+n+1);
    ans=max(ans,matrix[i][n-1]);
  }
  cout<<1<<endl;
  cout<<ans<<endl;
}
