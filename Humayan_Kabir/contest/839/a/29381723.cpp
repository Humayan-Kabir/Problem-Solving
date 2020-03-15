#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        ll num;
        cin>>num;
        sum+=num;
        if(sum>=8)
        {
            sum-=8;
            k-=8;
            cnt++;
        }
        else
        {
           k-=sum;
           sum=0;
           cnt++;
        }

        if(k<=0) break;

    }

    if(k>0)
        cout<<-1<<endl;
    else
    cout<<cnt<<endl;

    return 0;
}
