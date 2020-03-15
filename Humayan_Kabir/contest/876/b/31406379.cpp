/*input
4 3 5
2 7 7 7
*/
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll ara[100007];
vector<ll> vt[100007];
int main(int argc, char const *argv[])
{
    ll n,k,m;
    scanf("%lld %lld %lld",&n,&k,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&ara[i]);
        ll mod=ara[i]%m;
        vt[mod].push_back(ara[i]);
    }
    int foo=0;
    for(int i=0; i<=100000; i++)
    {
        if(vt[i].size()>=k)
        {
            foo=1;
            printf("Yes\n");
            for(int j=0; j<vt[i].size(); j++)
            {
                if(k==0) continue;
                if(j==0) printf("%lld",vt[i][j]);
                else printf(" %lld",vt[i][j]);
                k--;
            }
            printf("\n");
            break;
        }
    }
    if(!foo) printf("No\n");
    return 0;
}
