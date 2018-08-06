#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,stack[500500],s,top,height;
int main(){
    cin>>n;
    cin>>height;
    stack[++top]=height;
    for(int i=1;i<n;i++){
        cin>>height;
        if(height<stack[top])s++,stack[++top]=height;
        else{
            int pos=lower_bound(stack+1, stack+1+top, height,greater<int>())-stack;//最终放弃手写二分
            if(pos>1)
                pos--;
            s+=top-pos+1;
            top=upper_bound(stack+1, stack+1+top, height, greater<int>())-stack;
            stack[top]=height;
        }
    }
    cout<<s;
    return 0;
}
