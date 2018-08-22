#include <cstdio>
#include <iostream>
using namespace std;
long long n, m,output;
long long base [50050],use[ 50050];
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    base[i]=(n- i)*(n -i-1)/ 2;
  for (int i=1;i<= n&&output !=n ;i++){
    output =(m-base[i]<=0 )?i :(m-base[i]+ i<=n ?m -base[i]+i:n);
    printf("%lld ",output);
    use[output]=1;
  }
  for(int i=n; i >= 1;i--)
    if( !use[i] )
      printf("%lld ",i);
  return 0;
}
