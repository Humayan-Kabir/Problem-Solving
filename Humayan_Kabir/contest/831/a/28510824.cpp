#include<bits/stdc++.h>
using namespace std;
const int N=123456;
typedef long long int LL;
int main()
{
    int n;
    cin>>n;
    int ara[n+2];
    int ar[n+2];
    memset(ara,0,sizeof ara);

    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }

    ar[0]=0;
    int tem=ar[1],pos=1;
    for(int i=1;i<=n;i++)
    {
        if(ar[i]<=ar[i-1]) break;

        ara[i]=1;

        pos=i;
        tem=ar[i];

    }

    for(int i=pos;i<=n;i++)
    {
        if(tem!=ar[i]) break;

        ara[i]=1;
        pos=i;
    }

    for(int i=pos+1;i<=n;i++)
    {
        if(ar[i]>=ar[i-1]) break;

        ara[i]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(ara[i]) cnt++;

    if(cnt==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
