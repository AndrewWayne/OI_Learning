#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
char path[100];//0-62
char pathout[100];
string temp;
stack<string> have;
stack<string> func;
string rand_str()
{
    string str="              ";
    int i;
    for(i=1;i<=12;++i)
    {
        switch((rand()%3))
        {
            case 1:
                str[i]='A'+rand()%26;
                break;
            case 2:
                str[i]='a'+rand()%26;
                break;
            default:
                str[i]='_';
                break;
        }
    }
    return str;
}
int main(int argc, const char * argv []) {
    srand(time(NULL));
    cin>>path;
    freopen(path,"r",stdin);
    freopen("out.cpp","w",stdout);
    while(cin>>temp)
    {
        have.push(temp);
        func.push(rand_str());
        cout<<func.top();
        if(*temp.rbegin()==';')printf("\n");
    }
    while(!have.empty()){
        cout<<"#define "<<func.top()<<" "<<have.top()<<endl;
        func.pop();
        have.pop();
    }
    return 0;
}
