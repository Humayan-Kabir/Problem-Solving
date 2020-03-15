#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,ara[100001],multiply[3],dp[100001][3],ok[100001][3];
ll MIN=numeric_limits<long long int> :: min();
ll rec(ll pos,ll id)
{
    if(id==3) return 0;
    if(ok[pos][id]!=0) return dp[pos][id];
    if(pos==n) return MIN;
    ll now;
    now=ara[pos]*multiply[id]+rec(pos,id+1);
    now=max(now,rec(pos+1,id));
    ok[pos][id]=1;
    return dp[pos][id]=now;
}
int main()
{
    scanf("%lld",&n);
    for(int i = 0; i<3; i++) scanf("%lld",&multiply[i]);
    for(int i = 0; i<n; i++) scanf("%lld",&ara[i]);
    printf("%lld\n",rec(0,0));
    return 0;
}