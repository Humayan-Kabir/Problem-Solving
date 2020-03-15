#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> foo;
ll ara[100007],mx=100000000000000;
map<ll,ll> mymap;
void stupid(ll k)
{
    ll a=1;
    for(int i=1;i<64;i++)
    {
        foo.push_back(a);
        a=a*k;
        if(a>mx || a<-mx) break;
    }
}

int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1; i<=n; i++) scanf("%lld",&ara[i]);

    if(m==1) foo.push_back(1);

    else if(m==-1)
    {
        foo.push_back(-1);
        foo.push_back(1);
    }

    else stupid(m);

    ll sum=0,ans=0;
    mymap[0]=1;
    for(int i=1;i<=n;i++)
    {
        sum+=ara[i];
        for(int j=0;j<foo.size();j++)
        {
            ll fnd=sum-foo[j];
            if(mymap.find(fnd)!=mymap.end());
            ans+=mymap[fnd];
        }
        mymap[sum]++;
    }

    printf("%lld\n",ans);

    return 0;
}
