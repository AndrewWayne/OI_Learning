#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,k;
	int h,i,j;
	int num[1000];
	int s[1000],s2[1000];

	scanf("%d%d",&n,&k);
	int f[n][k];
	for(i=0;i<n;i++){
		scanf("%d",num[i]);
		for(j=i;j<n;j++){
			s[j]+=num[i];
			s2[j]+=num[i]*num[i];
		} 
	}
	sort(&num[0],&num[n-1]);
	int p=s[n-1]/n;
	
	for(i=1;i<k;i++){
		for(j=1;j<n;j++){
			f[]
		}
	}
}
