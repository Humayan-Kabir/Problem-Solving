#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cube[1000002];
int main()
{
    //ios_base::sync_with_stdio(false);
    for(ll i=1; i<=1000000; i++)
    {
        ll ans=(ll)i*(ll)i*(ll)i;
        cube[i]=ans;
    }

    int t;
    scanf("%d",&t);
    while (t--)
    {
        ll a,b,low=1,high=1000000,foo=0;
        scanf("%lld %lld",&a,&b);
        ll need=(ll)(a*b);
        while (low<=high)
        {
            ll mid=(low+high)/2;
            if(cube[mid]>need)
            {
                high=mid-1;
            }
            else if(cube[mid]<need)
            {
                low=mid+1;
            }
            else
            {
                if(a%mid==0 && b%mid==0)
                   foo=1;
                break;
            }
        }

        if(foo) puts("Yes");
        else puts("No");
    }

    return 0;
}
