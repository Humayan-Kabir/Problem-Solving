#include<bits/stdc++.h>
#define mx 2017
using namespace std;
typedef long long int LL;
int main()
{
     LL ara[mx];
     int n,one = 0;
     cin >> n;
     for(int i = 1; i<=n; i++)
     {
          cin >> ara[i];
          if(ara[i] == 1) one ++;
     }
     if(one)
     {
          printf("%d\n",n-one);
          return 0;
     }
     int dist = INT_MAX;
     for(int i = 1; i<=n; i++)
     {
          LL g = ara[i];
          for(int j = i; j<=n; j++)
          {
               g = __gcd(ara[j],g);
               if(g == 1)
               {
                    dist = min(dist,j - i);
                    break;
               }
          }

     }
     //cout<< dist <<endl;
     if(dist >= INT_MAX)
     {
          cout<< -1 <<endl;
     }
     else
     {
          cout << dist + n - 1 <<endl;
     }
     return 0;
}
