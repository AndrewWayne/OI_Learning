#include <bits/stdc++.h>
#define rep(a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){//�������壬���ݹ� 
    int a[22];
    int n,r;
    cin>>n>>r;
    rep(0,r)
    	a[i]=i;
    while(a[0]==0){
    	rep(1,r)
    		cout<<setw(3)<<a[i];
    	cout<<endl;
    	int j=r;
    	while(a[j]==n-r+j)j--;
    	a[j]++;
    	rep(j+1,r)
    		a[i]=a[i-1]+1;//�ƹ�ȥ 
	}
	return 0;
}
