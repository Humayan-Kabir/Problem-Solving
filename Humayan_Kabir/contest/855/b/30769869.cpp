#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,ara[100001],multiply[3],dp[100001][3],ok[100001][3];
inline ll rec(int pos,int id)
{
    if(id==3) return 0LL;
    if(ok[pos][id]!=0) return dp[pos][id];
    ll now1=ara[pos]*multiply[id]+rec(pos,id+1);
    if(pos+1<n)
    now1=max(now1,rec(pos+1,id));
    ok[pos][id]=1;
    return dp[pos][id]=now1;
}
int main()
{
    scanf("%lld",&n);
    for(int i = 0; i<3; i++) scanf("%lld",&multiply[i]);
    for(int i = 0; i<n; i++) scanf("%lld",&ara[i]);
    printf("%lld\n",rec(0,0));
    return 0;
}
