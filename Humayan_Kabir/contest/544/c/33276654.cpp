/*input
3 6 5 1000000007
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
int dp[2][501][501];
int main(int argc, char const *argv[])
{
	for(int i = 0; i<2; i++) dp[i][0][0] = 1;
	int n,m,b,mod;
	cin >> n >> m >> b >> mod;
	int ara[n+2];
	for(int i = 1; i<=n; i++) cin >> ara[i];
	int now = 1;	
	for(int i  = 1; i<=n; i++)
	{
		dp[now][0][0] = 1;
		for(int bug = 0; bug<=b; bug++)
		{
			for(int line = 1; line<=m; line++)
			{
				dp[now][bug][line] = dp[!now][bug][line];
				if(bug - ara[i] >= 0) dp[now][bug][line] = (dp[now][bug][line] % mod + dp[now][bug-ara[i]][line-1] % mod) %mod;
			}
		}
		now = !now;
	}
	now = !now;
	int ans = 0;
	for(int j = 0; j<=b; j++) ans = ( ans % mod + dp[now][j][m] % mod) % mod;
	cout << ans << endl;
			
	return 0;
}