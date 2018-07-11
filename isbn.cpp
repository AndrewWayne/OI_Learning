#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int ans,code[10],vic;
string a;
int main()
{
	freopen("isbn.in","r",stdin);
	freopen("isbn.out","w",stdout);
	cin>>a;
	code[1]=a[0]-'0';
	code[2]=a[2]-'0';
	code[3]=a[3]-'0';
	code[4]=a[4]-'0';
	code[5]=a[6]-'0';
	code[6]=a[7]-'0';
	code[7]=a[8]-'0';
	code[8]=a[9]-'0';
	code[9]=a[10]-'0';
	vic=a[12]-'0';
	for(int i=1;i<=9;i++) ans+=code[i]*i;
	ans%=11;
	if(ans==vic) printf("Right");
	else 
	{
		for(int i=0;i<=11;i++) printf("%c",a[i]);
		printf("%d",ans);
	}
	return 0;
}
