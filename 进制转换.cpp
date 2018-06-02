#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int pow(int di,int mi){
	
	int out=1;
	for(int i=1;i<=mi;i++){
		out*=di;
	}
	return out;
}
int main(){
	int i,d,n,t;
	char in[1000],out[1000];
	int value;
	int top,c;
	t=1
	scanf("%d %d %s",&n,&d,&in);
	for(i=0;i<=strlen(in);i++){
		if(in[i]>'9')
			value+=(in[i]-'A'+10)*t;
		else 
			value+=(in[i]-'0')*t;
		t*=d;
	}
	while(value>0){
		c=value%d;
		if(c>9)
			out[++top]='A'+c-10;
		else
			out[++top]='0'+c;
		value/=d;
	}
	for(i=top;i>=1;i--)
		printf("%c",out[i]);
	return 0;
}
