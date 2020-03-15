/*input
1
1
*/
#include <bits/stdc++.h>
#define mod 1000000007
typedef long long int LL;
using namespace std;
LL cycle[1007];
int main(int argc, char const *argv[])
{
	LL n,ara[1007];
	cin >> n;
	for(int i = 1; i<=n; i++) cin >> ara[i];
	LL ans = 2; cycle[1] = 1;
	for(int i = 2; i<=n; i++)
	{
		LL now = 0;
		for(int j = ara[i]; j<=i; j++) now =(1 + now + cycle[j]) % mod;
		ans = (1 + ans + now) % mod;
	    cycle[i] = now;
	}	
	cout << ans << endl;
	return 0;
}