/*input
*/
#include<bits/stdc++.h>
#define mx 10000000
using namespace std;
typedef long long int LL;
int ara[mx];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
    {
        int num;
        scanf("%d",&num);
        ara[num]++;
    }
    int ans =  0;
    for(int i = 0; i<mx; i++)
    {
        ara[i + 1] = ara[i]/2 + ara[i + 1];
        ans+=(ara[i] % 2);
    }
    cout << ans << endl;
    return 0;
}