#include <cstdio>
#include <iostream>
using namespace std;
struct node{
    int left,right;
    char val;
}b_tree[300];
int n,root;
char a,l,r;
void Print(int x){
    if(x==0)return;
    printf("%c",b_tree[x].val);
    Print(b_tree[x].left);
    Print(b_tree[x].right);
}
int main(){
    cin>>n;
    cin>>a>>l>>r;
    root=a;
    b_tree[a].val=a;
    if(l=='*')
        l=0;
    if(r=='*')
        r=0;
    b_tree[a].left=l;
    b_tree[a].right=r;
    for(int i=1;i<n;i++){
        cin>>a>>l>>r;
        if(l=='*')
            l=0;
        if(r=='*')
            r=0;
        b_tree[a]={l,r,a};
    }
    Print(root);
    return 0;
}
