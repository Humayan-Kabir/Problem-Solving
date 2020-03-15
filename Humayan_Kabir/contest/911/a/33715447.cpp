/*input
2
3 3
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[mx];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int mn = INT_MAX;
	for(int i = 1; i<=n; i++)
	{
		cin >> ara[i];
		mn = min(ara[i],mn);
	}
	int prev = -1;
	int ans = INT_MAX;
	for(int i = 1; i<=n; i++)
	{
		if(ara[i] == mn && prev == -1) 
		{
			prev = i;
			continue;
		}
		if(ara[i] == mn)
		{
			ans = min(ans,i - prev);
			prev = i;
		}
	}
	cout << ans << endl;
	return 0;
}