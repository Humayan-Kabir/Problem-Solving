#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int n,k,d,dp[1000][3];
long long int MOD=1e9+7;
ll rec(ll sum,ll status)
{
    //cout<<sum<<" ok lets go "<<status<<endl;
    if(sum<0) return 0;
    if(sum==0 && status==1) return 1;
    if(sum==0 && !status) return 0;
    if(dp[sum][status]!=-1) return dp[sum][status];
    ll ret=0;
    for(ll i=1; i<=k; i++)
    {
        if(status || i>=d) ret=(ret+rec(sum-i,1)+MOD)%MOD;
        else if(!status) ret=(ret+rec(sum-i,0)+MOD)%MOD;
    }

    return dp[sum][status]=ret%MOD;
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n>>k>>d;
    cout<<rec(n,0)<<endl;
    return 0;
}
