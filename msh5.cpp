#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#define minn(a,b) a<b?a:b
using namespace std;
int n;
string num[25];
bool cmp(string a,string b){
	printf("yeah");
	return a+b>b+a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%s",&num[i]);
	for(int i=1;i<=n;i++){
		printf("%s",&num[i]);
	}
	sort(&num[1],&num[n],cmp);
	for(int i=1;i<=n;i++){
		printf("%s",&num[i]);
	}
	return 0;	
}
