/*input
1000 1000 1000 999 999 1000
*/
#include <bits/stdc++.h>
#include<algorithm>
#define fs first
#define sc second 
#define mx 200007
#define PII pair<int,int>
typedef long long int LL;
using namespace std;
int main(int argc, char const *argv[])
{
    int ara[10] = {0, 1, 2, 3, 4, 5};
    int ar[10];
    for(int i = 0; i<6; i++)
    {
    	cin >> ar[i];
    }
    int foo = 0;
    do
    {
       int sum = 0;
       for(int i = 0; i<3; i++) sum+=ar[ara[i]];
       for(int i = 3; i<6; i++) sum-=ar[ara[i]];
       if(sum==0) foo = 1;	
    }
    while(next_permutation(ara,ara+6));
    if(foo) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}