/*input
3 4
5 3 4
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
LL ara[1200];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	LL n, s, sum = 0, MX = INT_MAX;
	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		cin >> ara[i];
		sum += ara[i];
		MX = min(MX, ara[i]);
	}
	if(sum < s) {
		cout << -1 << endl;
		return 0;
	}
	if(sum == s) {
		cout << 0 << endl;
		return 0;
	}
	LL ans = 0;
	LL low = 0, high = MX;
	while(low <= high) {
		LL mid = (low + high) / 2;
		LL total = 0, flag = 1;
		for(int i = 1; i <= n; i++) {
			total += (ara[i] - mid);
		}
		if(total >= s) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	} 
	cout << ans << endl;
	return 0;
}