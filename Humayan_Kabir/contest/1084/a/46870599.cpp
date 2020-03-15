/*input
2
1 1
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
int ara[120];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ara[i];
	}
	int mn = INT_MAX;
	for(int j = 1; j <= n; j++) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int down = abs(i - j) + abs(i - 1) + abs(j - 1);
			int up = abs(1 - j) + abs(i - 1) + abs(j - i);
			ans += down * ara[i];
			ans += up * ara[i];
		}
		mn = min(mn, ans);
	}
	cout << mn << endl;
	return 0;
}