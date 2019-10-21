#include <iostream>
 using namespace std;
 int main( )
 {
     int n,m,i,j,p,k;
     int a[100],b[100];
     cin >> n >> m;
     a[0]=n;
     i=0;
     p=0;
     k=0;
     do
     {
         for (j=0;j<i;j++)
             if (a[i]==a[j])
             {
                 p=1;
                 k=j;
                 break;
             }
         if (p)
             break;
         b[i]=a[i]/m;
         cerr << b[i] << " " << a[i] << endl;
         a[i+1]=a[i]%m*10;
         i++;
     }while (a[i]!=0);
     cout << b[0] << ".";
     for (j=1; j<k; j++)
         cout << b[j];
     if (p)
         cout << "(";
     for (j=k;j<i;j++)
         cout << b[j];
     if (p)
         cout << ")";
     cout << endl;
     return 0;
 }
