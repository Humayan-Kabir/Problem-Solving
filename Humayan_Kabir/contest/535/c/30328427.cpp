#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    while (n--)
    {
        ll l,t,m;
        cin>>l>>t>>m;
        ll low=l,high=t;
        ll ans=-1;
        while (low<=high)
        {
            ll mid=(low+high)/2;
            ll right_val=a+(mid-1)*b;
            ll y=(mid*(mid-1))/2ll;
            ll x=((l-1)*(l-2))/2ll;
            ll sum=a*(mid-l+1)+b*(y-x);
            if(right_val<=t && sum<=(m*t))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
