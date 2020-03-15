#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[1000007];
int main()
{
    ll n,sum=0,foo=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&ara[i]);
        sum+=ara[i];
        if(ara[i]%2==1) foo=1;
    }
    if(sum%2==1 || foo)
    {
        printf("First\n");
        return 0;
    }
    else printf("Second\n");

    return 0;
}
