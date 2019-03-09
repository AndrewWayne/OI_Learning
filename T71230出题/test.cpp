#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char num1[501],num2[501];
int ans[502];
int a;
int main(){
	cin>>num1;
	cin>>num2;
	int len = max(strlen(num1), strlen(num2));
	for(int i=0;i<len;i++){
		int a=num1[i]-'0' + num2[i]-'0';
		if(a>9){
		   ans[i] += a % 10;
		   ans[i+1]++;
		}else{
		   ans[i]=a;
		}
	}
	for(int i=len-1;i>=0;i--)
		cout<<ans[i];
return 0;
}
