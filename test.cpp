#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	freopen("a.in", "w", stdout);
	puts("10");
	int n = 10;
	for(int i = 1; i <= 10; i++){
		printf("%d ", rand()%10 + 1);
	}
	return 0;
}
