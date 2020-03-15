/*input
20
*/
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[])
{
    ll n,k,m;
    cin>>n;
    vector<ll> vt;
    for(ll i=max(0*1LL,n-1LL*100); i<=n; i++)
    {
        ll sum=0;
        ll tem=i;
        while(tem)
        {
            sum+=(tem%10);
            tem/=10;
        }
        if((sum+i)==n)
        {
            vt.push_back(i);
        }
    }
    sort(vt.begin(), vt.end());
    cout<<vt.size()<<endl;
    for(int i=0; i<vt.size(); i++)
    {
        if(i==0) cout<<vt[i];
        else cout<<" "<<vt[i]<<endl;
    }
    return 0;
}
