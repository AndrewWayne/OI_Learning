#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n, m, t[100010], opt[100010];//opt[i] = 0 - and, 1 - or, 2 - xor;
int k = 0;
string option;
int calc(int val, int bit){
	for(int i = 1; i <= n; i++){
		if(opt[i] == 0)
			val &= (t[i] >> bit)&1;
		if(opt[i] == 1)
			val |= (t[i] >> bit)&1;
		if(opt[i] == 2)
			val ^= (t[i] >> bit)&1;
	}
	return val;
}
int main(){
	cerr << (1 << 6) << endl;
	cin >> n >> m;
	int temp;
	for(int i = 1;i <= n; i++){
		cin >> option >> t[i];
		if(option == "AND")
			opt[i] = 0;
		if(option == "OR")
			opt[i] = 1;
		if(option == "XOR")
			opt[i] = 2;
	}

	for(int i = 31; i >= 0; i--){
		if(calc(0, i)){
			k += (1 << i);
			cerr << i << " - " << k << endl;
			continue;
		}
		if(calc(1, i)){
			if( m - (1 << i) >= 0 )
				k += (1 << i), m -= (1 << i);
			cerr << i << " - " << k << endl;
		}

	}
	cout << k << endl;
	return 0;
}
