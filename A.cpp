#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int num[29],n;
string s;
int main()
{
    cin >> n;
    cin >> s;
    char c;
    if(n==1){
        cout<<"Yes";
        return 0;
    }
    for (int i = 0; i < n;i++)
      c = s[i],num[c - 'a']++;
    int ans = 0;
    for (int i = 0; i < 26;i++)
      if(num[i]>1)
        ans++;
    if(ans>0)
      cout << "Yes";
    else
      cout << "No";
    return 0;
}
