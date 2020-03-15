/*input
agaa
*/
#include <bits/stdc++.h>
#define mx 2000000
#define mod 1000000007
using namespace std;
namespace todo {
	void fundamental() {
		printf("welcome to namespace\n");
	}
}
typedef long long int LL;
LL dp[mx], cummulative[mx];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	int len  = str.length(), last = -1;
	for(int i = 0; i < len; i++) {
		if(str[i] == 'b') {
			dp[i] = 0;
			last = i;
			cummulative[i] = cummulative[max(0, i - 1)];
			continue;
		}
		if(str[i] != 'a') {
			dp[i] = 0;
			cummulative[i] = cummulative[max(0, i - 1)];
			continue;
		}
		dp[i] = 1;
		if(last != -1) {
			dp[i] = (dp[i] + cummulative[last] + mod) % mod;
		}
		cummulative[i] = (dp[i] + cummulative[i - 1]) % mod;
	}
	LL ans = 0;
	for(int i = 0; i < len; i++) {
		ans = (ans + dp[i] + mod) % mod;
	}
	cout << ans << endl;
	return 0;
}