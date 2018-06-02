#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int i,top1,top2;
	char a[255];
	scanf("%s",a);
	for(i=0;i<=strlen(a);i++){
		if(a[i]=='[')
			top1++;
		if(a[i]=='(')
			top2++;
		if(a[i]==']')
			top1--;
		if(a[i]==')')
			top2--;
	}
	if(top1==0&&top2==0)
		printf("OK");
	else
		printf("Wrong");
	return 0;
}
