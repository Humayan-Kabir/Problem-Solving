/*input
4
1
2
3
4
*/
#include <bits/stdc++.h>
#define mx 1002
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL NcR[mx][mx],fact[mx];
void initialization()
{
	fact[0] = 1; NcR[0][0] = 1;
	for(int i = 1; i<=1000; i++) fact[i] = (fact[i - 1] * i + mod) % mod;
	for(int i = 1; i<=1000; i++)
	{
		NcR[i][0] = 1;
		for(int j = 1; j<=i; j++)
		{
			NcR[i][j] = (NcR[i - 1][j - 1] + NcR[i - 1][j]) % mod;
		}
	}	
}
int main()
{
	ios_base::sync_with_stdio(false);
	initialization();
	LL n;
	cin >> n;
	LL total = 0, ans = 1;
	for(int i = 1; i<=n; i++)
	{
		LL color;
		cin >> color;
		ans = (ans * NcR[total + color - 1][color - 1]) % mod;
		total = total + color;
	}
	cout << ans << endl;
    return 0;
}
