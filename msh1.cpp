#include <bits/stdc++.h>
using namespace std;
int n,s,ans;
string in;
int main(){
	cin>>in;
	cin>>s;
	in=in+'0';
	int len=in.size();
	for(int j=1;j<=s;j++){
		for(int i=0;i<len-1;i++){
			int d=in[i+1]-in[i];
			if(d<0){
				in.erase(i,1);break;
			}
		}
	}
	len=in.size();
	for(int i=0;i<len-1;i++)
		printf("%c",in[i]);
	system("pause");
}
