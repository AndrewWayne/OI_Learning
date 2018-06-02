写不来写不来
/*#include <string.h>
#include <iostream>
#include <cstdio>
using namespace std;
long int a[100000];
void qsort(int begin,int end){
  int sb=a[begin];
  int i=begin,j=end;
  while(j>i){
      while(a[j]>=sb&&j>i)
        j--;
      while(a[i]<=sb&&i<j)
        i++;
      exchange(a[i],a[j]);
  }
  exchange(a[begin],a[i]);
  qsort(begin,i-1);
  qsort(i,end);
}
void exchange(long int a,long int b){
  long int temp;
  temp=a;
  a=b;
  b=temp;
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%ld",&a[i]);
  qsort(0,n-1);
  for(int i=0;i<n;i++)
  printf("%d ",a[i]);
  return 0;
}
*/
