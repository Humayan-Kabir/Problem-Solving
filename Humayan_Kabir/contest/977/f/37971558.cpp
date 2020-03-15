/*input
7
3 3 4 7 5 6 8
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[mx];
map<int,int> dp;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
		scanf("%d",&ara[i]);
	int maxIndex = 1, was = -1;
	for(int i = 1; i<=n; i++)
	{
		if(dp.find(ara[i] - 1)==dp.end())
		{
			dp[ara[i]] = 1;
		}
		else 
		{
			dp[ara[i]] = max(dp[ara[i]], dp[ara[i] - 1] + 1);
		}
		if(dp[ara[i]] > was)
		{
			was = dp[ara[i]];
			maxIndex = i;
		}
	}
	int val = ara[maxIndex], start = val - was + 1, foo = 0;
	printf("%d\n",was);
	for(int i = 1;  i<=maxIndex; i++)
	{
		if(ara[i] == start)
		{
			if(foo == 0) printf("%d",i);
			else printf(" %d",i);
			start++;
			foo = 1;
		}
	}
	return 0;
}