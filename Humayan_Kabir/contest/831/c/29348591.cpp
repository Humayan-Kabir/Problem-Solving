#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false); 
    map<ll,ll> mymap;
    ll n,m,sum=0;
    cin>>n>>m;
    vector<ll> vt;
    set<ll> need;
    vector<ll> prefix;
    for(int i=1; i<=n; i++)
    {
        ll mark;
        cin>>mark;
        sum+=mark;
        prefix.push_back(sum);
        mymap[sum]++;
    }

    for(int i=1; i<=m; i++)
    {
        ll remember;
        cin>>remember;
        vt.push_back(remember);
    }

    sort(vt.begin(),vt.end());

    ll initial=vt[0],ans=0;

    for(int i=0; i<prefix.size(); i++)
    {
        need.insert(initial-prefix[i]);
    }

    set<ll> ::iterator it;

    for(it=need.begin();it!=need.end();it++)
    {
       // cout<<" bgjd "<<*it<<endl;
       ll x=*it;
       map<ll,ll> cnt;
       int foo=1;
       for(int j=0;j<vt.size();j++)
       {
         ll d=vt[j]-x;
         cnt[d]++;
         if(cnt[d]>mymap[d])
         {
             foo=0;
             break;
         }
       }
       ans+=foo;
    }

    cout<<ans<<endl;
    return 0;
}
