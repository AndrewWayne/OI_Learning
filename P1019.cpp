#include <bits/stdc++.h>//���Լ�д��a>b?a:b������ 
using namespace std;
string words[22];
int use[22],len=0,n;
int chongdie(string,string);
void dfs(string word1,int lenn){
	len=max(lenn,len);//����
	for(int i=0;i<n;i++){
		if(use[i]>=2)continue;
		int c=chongdie(word1,words[i]);//���ص� 
		if(c>0){
			use[i]++;
			dfs(words[i],lenn+words[i].size()-c);
			use[i]--;//����
		}
	}
}
int chongdie(string a,string b){
	for(int i=1;i<min(a.size(),b.size());i++){//������,iΪchong die���� 
		bool ifend=true;
		for(int j=0;j<i;j++)
			if(a[a.size()-i+j]!=b[j])
				ifend=false;
		if(ifend) return i;
	}
	return 0;
}
int main(){
	cin>>n;
	memset(use,0,sizeof(use));
	for(int i=0;i<=n;i++)
		cin>>words[i];
	dfs(' '+words[n],1);//�����-1������ֻ��һ���ַ�����Ҫ��һ�� 
	cout<<len;
}
