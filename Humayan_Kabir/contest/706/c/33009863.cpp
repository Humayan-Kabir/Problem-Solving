/*input
2
3 3
aaa
aa
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
string str[mx][2];
LL n,dp[mx][2],cost[mx];
LL LL_Max = 1000000000000000000;
LL rec(int pos,int type)
{
	if(pos == n) return 0;
	LL &ret = dp[pos][type];
	if(ret != -1) return ret;
	LL now = LL_Max;
	if(pos == 0)
	{
		now = rec(pos+1,0);
		now = min(now,cost[pos] + rec(pos+1,1));
	}
	else
	{
		if(str[pos][0] >= str[pos - 1][type]) now = rec(pos + 1, 0);
		if(str[pos][1] >= str[pos - 1][type]) now = min(now, cost[pos] + rec(pos+1,1));
	}
	return ret = now;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n; i++) cin >> cost[i];
	for(int i = 0; i<n; i++) cin >> str[i][0];
	for(int i = 0; i<n; i++) 
	{
		string tem;
		for(int j = str[i][0].size() - 1; j>=0 ; j--)
			tem+=str[i][0][j];
		str[i][1] = tem;

	}	
	memset(dp,-1,sizeof dp);	
    LL ans = rec(0,0);
    if(ans >= LL_Max) cout << -1 <<endl;
    else cout << ans << endl;
	return 0;
}