/*input
3
*/
#include <bits/stdc++.h>
#define mod 998244353
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[200];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int root = sqrt(root);
	int ans = INT_MAX;
	for(int i = 1; i * i <= n; i++) {
		int now = i + 1;
		int d = (n / i) - 1;
		now += d;
		if(n % i != 0) {
			now += 1;
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}