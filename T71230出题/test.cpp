#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char num1[501],num2[501];
int numb1[505], numb2[505];
int ans[502];
int a;
int main(){
	cin>>num1;
	cin>>num2;
	int len1 = strlen(num1), len2 = strlen(num2);
	int len = max(len1, len2);
	for(int i = len1-1; i >= 0; i--){
		numb1[len1-i] = (num1[i] - '0');
	}
	for(int i = len2-1; i >= 0; i--)
		numb2[len2-i] = num2[i] - '0';
	for(int i=1;i<=len;i++){
		ans[i] += numb1[i] + numb2[i];
		if(ans[i]>9){
		   ans[i] %= 10;
		   ans[i+1]++;
		}
		cerr << ans[i] << endl;
	}

	for(int i=len;i>=1;i--)
		cout<<ans[i];
return 0;
}
