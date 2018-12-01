#include <cstdio>
#include <iostream>
using namespace std;
int q, l, r;
int main(){
    cin >> q;
    while(q--){
        cin >> l >> r;
        if(l & 1)
            if(r & 1)
                cout << (r-l+1)/2 - r << endl;
            else
                cout << (r-l+1)/2 << endl;
        else
            if(r & 1)
                cout << (r-l+1)/2 - r + l - 1 << endl;
            else
                cout << -(r-l+1)/2 + r << endl;

    }
    return 0;
}
