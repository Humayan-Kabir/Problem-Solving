/*input
8 3
0 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1
1 1 0 1 1 1 1 1
1 1 1 0 1 1 1 1
1 1 1 1 0 1 1 1
1 1 1 1 1 0 1 1
1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 0
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
int n, k, grid[4002][4002], dp[4002][2], now = 0;
inline int costF(int i,int j)
{
	if(i > j) return 0;
	return (grid[j][j] + grid[i - 1][i - 1] - grid[i - 1][j] - grid[j][i - 1]) / 2;
}

void rec(int l,int r,int kleft,int kright)
{
	if(l > r) return;
	int mid = (l + r) / 2, bestk;
	dp[mid][now] = INT_MAX;
	for(int i = kleft; i<=kright; i++)
	{
		int ret = dp[i][now ^ 1] + costF(i + 1, mid);
		if(ret < dp[mid][now])
		{
			dp[mid][now] = ret;
			bestk = i;
		}
	}
	rec(l,mid - 1,kleft,bestk);
	rec(mid + 1,r,bestk,kright);
}
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&k);
	for(int i = 1; i<=n; i++)
	{
		char ch;
		for(int j = 1; j<=n; j++)
		{
			scanf(" %c",&ch);
			grid[i][j] = grid[i-1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + (ch - '0');
		}
	}
	for(int i = 1; i<=n; i++)
	{
		dp[i][0] = costF(1,i);
	}
	for(int i = 2; i<=k; i++)
	{
		now = now ^ 1;
		rec(1,n,1,n);
	}
	cout << dp[n][now] << endl;
	return 0;
}