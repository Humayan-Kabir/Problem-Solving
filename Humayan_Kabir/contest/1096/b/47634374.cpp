/*input
2
az
*/
#include <bits/stdc++.h>
#define mod 998244353
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[26];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string str;
	cin >> str;
	char start = str[0], last = str[n - 1];
	int cnt1 = 0, cnt2 = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(str[i] == start) cnt1++;
		else break;
	}
	for(int i = n - 1; i >= 0; i--) {
		if(str[i] == last) cnt2++;
		else break;
	}
	LL ans = 0;
	ans += min(cnt2 + 1, n);
	ans = ans % mod;
	ara[str[0] - 'a']++;
	int dist = 1;
	for(int i = 2; i <= n; i++) {
		if(dist > 1) break;
		int upto = min(n - i + 1, cnt1 + 1);
		ans += upto;
		ans = ans % mod;
		ara[str[i - 1] - 'a']++;
		if(ara[str[i - 1] - 'a'] == 1) dist++;
	}
	cout << ans << endl;
	return 0;
}