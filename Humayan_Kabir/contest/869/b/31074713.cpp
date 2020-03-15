/*input
2 4
*/
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[])
{
    ll a,b;
    cin>>a>>b;
    ll x=b-a;
    if (x==0)
    {
        cout<<1<<endl;
        return 0;
        /* code */
    }
    ll mod=b%10*1LL;
    for (ll i = 1; i < min(x,500*1LL); ++i)
    {
        ll y=(b-i)%10*1LL;
        mod=(mod*y)%10*1LL;
    }
    cout<<mod<<endl;
    return 0;
}
