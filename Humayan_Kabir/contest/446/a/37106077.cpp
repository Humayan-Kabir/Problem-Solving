/*input
5
1 2 3 4 1
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
int prefix[mx], suffix[mx], ara[mx];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++) cin >> ara[i];
	for(int i = 1; i<=n; i++) 
	{
		if(i == 1) prefix[1] = 1;
		else if(ara[i] > ara[i - 1])
		{
			prefix[i] = prefix[i - 1];
		}
		else 
		{
			prefix[i] = i;
		}
	}	
	for(int i = n; i>=1; i--)
	{
		if(i == n) suffix[i] = n;
		else if(ara[i] < ara[i + 1])
		{
			suffix[i] = suffix[i + 1];
		}
		else suffix[i] = i;
	}
	int ans = 1;
	for(int i = 1; i<=n; i++)
	{
		if(i == 1)
		{
			ans = max(ans,suffix[i + 1] - i + 1);
		}
		else if(i == n)
		{
			ans = max(ans,i - prefix[i - 1] + 1);
		}
		else if(ara[i + 1] - ara[i - 1] > 1)
		{
			ans = max(ans,suffix[i + 1] - prefix[i - 1] + 1);
		}
		else
		{
			ans = max(ans,i - prefix[i - 1] + 1);
			ans = max(ans,suffix[i + 1] - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}