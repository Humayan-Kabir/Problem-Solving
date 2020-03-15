#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    ios_base::sync_with_stdio(false);
    LL n,k;
    vector<LL> vt;
    cin>>n>>k;
    long long int flag=0;
    LL mn=99999999999999;
    for(int i=0;i<n;i++)
    {
       LL num;
       cin>>num;
       vt.push_back(num);
       mn=min(mn,num);
    }
    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        LL val=vt[i]-mn;
        if(val%k==0)
        {
            flag++;
            ans+=(val/k);
        }
    }
    if(flag==n)
    cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
