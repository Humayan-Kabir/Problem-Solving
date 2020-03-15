/*input
3 4 3006 1000
1 2 3
1 2 4 3
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
int n, m, s, e, a[mx], b[mx], dp[302][mx];
set<int> SET[mx];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> s >> e;
	for(int i = 1; i<=n; i++) cin >> a[i];
	for(int i = 1; i<=m; i++)
	{
		cin >> b[i];
		SET[b[i]].insert(i);
	}
	int mxPossible = s / e;
	for(int i = 1; i<=n; i++)
	{
		dp[1][i] = !SET[a[i]].empty() ? *SET[a[i]].begin() : INT_MAX;
	}
	for(int j = 2; j<=mxPossible; j++)
	{
		int mn = INT_MAX;
		for(int i = 1; i<=n; i++)
		{
			auto it = SET[a[i]].upper_bound(mn);
			if(it == SET[a[i]].end()) dp[j][i] = INT_MAX;
			else dp[j][i] = *it;
			mn = min(mn, dp[j - 1][i]);
		}
	}
	int ans = 0;
	for(int j = 1; j<=mxPossible; j++)
	{
		for(int i = 1; i<=n; i++)
		{
			if(dp[j][i] == INT_MAX) continue;
			else if(j * e + i + dp[j][i] <= s)
			{
				ans = max(ans,j);
			} 
		}
	}		
	cout << ans << endl;
	return 0;
}