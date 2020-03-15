#include<bits/stdc++.h>
using namespace std;
int ara[55],sum[55],dp[55],n;
int rec(int pos)
{
    if(pos>n) return 0;
    int &ret=dp[pos];
    if(ret!=-1) return ret;
    int now1,now2;
    now1=ara[pos]+sum[n]-sum[pos]-rec(pos+1);
    now2=rec(pos+1);
    return ret=max(now1,now2);
}
int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>ara[i];
    for(int i = 1; i<=n; i++) sum[i]=sum[i-1]+ara[i];
    memset(dp,-1,sizeof dp);
    int ret=rec(1);
    cout<<sum[n]-ret<<" "<<ret<<endl;
    return 0;
}
