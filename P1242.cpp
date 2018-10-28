#include <cstdio>
#include <iostream>
using namespace std;
int tower[3][50],tops[3];//0 - A 1 - B 2 - C
int end_tower[3][50],endtop[3];
int n,num;
bool comp(){
    int top = 0;
    for(int i = 0; i < 3; i++){
        top = tops[i];
        if( tops[i] != endtop[i] )
            return false;
        while(top > 0)
            if( tower[i][top] != end_tower[i][top] )
                return false;
    }
    return true;
}
void dfs(){

}
int main(){
    cin >> num;
    for(int i = 0; i < 3; i++){
        cin >> n;
        for(int tops[i] = 1; tops[i] <= n; tops[i]++)
            cin >> tower[i][tops[i]];
    }
    for(int i = 0; i < 3; i++){
        cin >> n;
        endtop[i] = n;
        for(int j = 1; j <= n; j++)
            cin >> end_tower[i][j];
    }
    //然后不会了

    return 0;
}
