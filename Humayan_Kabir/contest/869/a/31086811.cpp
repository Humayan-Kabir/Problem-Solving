/*input
3
9 33 69
71 74 100
*/
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[])
{
    map<ll,int> mymap;
    int n;
    cin>>n;
    ll ara1[3000],ara2[3000];
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&ara1[i]);
        mymap[ara1[i]]=1;
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld",&ara2[i]);
        mymap[ara2[i]]=1;
    }
    int ans=0;
    for (int i = 0; i < n; ++i)
    {
        for(int j=0; j<n; j++)
        {
            ll x=ara1[i]^ara2[j];
           // cout<<x<<" xor value "<<i<<" "<<j<<endl;
            if(mymap.find(x)!=mymap.end()) ans++;
          //  cout<<ans<<endl;
        }
    }
    //cout<<ans<<endl;
    if(ans%2==0) cout<<"Karen"<<endl;
    else cout<<"Koyomi"<<endl;
    return 0;
}
