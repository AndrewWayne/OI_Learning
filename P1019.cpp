#include <bits/stdc++.h>//用自己写的a>b?a:b就闪退 
using namespace std;
string words[22];
int use[22],len=0,n;
int chongdie(string,string);
void dfs(string word1,int lenn){
	len=max(lenn,len);//打擂
	for(int i=0;i<n;i++){
		if(use[i]>=2)continue;
		int c=chongdie(word1,words[i]);//求重叠 
		if(c>0){
			use[i]++;
			dfs(words[i],lenn+words[i].size()-c);
			use[i]--;//回溯
		}
	}
}
int chongdie(string a,string b){
	for(int i=1;i<min(a.size(),b.size());i++){//防包含,i为chong die长度 
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
	dfs(' '+words[n],1);//比最短-1但开局只有一个字符所以要补一个 
	cout<<len;
}
