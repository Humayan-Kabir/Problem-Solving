/*input
5
1 1 2 2 3
*/
#include <bits/stdc++.h>
#define mod 998244353
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ara[1002];
	for(int i = 1; i <= n; i++) {
		cin >> ara[i];
	}
	int ans = INT_MAX, t = 0;
	for(int i = 1; i <= 1000; i++) {
		int now = 0;
		for(int j = 1; j <= n; j++) {
			if(ara[j] > i) {
				now += abs(ara[j] - (i + 1));
			}
			else if(ara[j] < i) {
				now += abs(i - 1 - ara[j]);
			}
		}
		if(now < ans) {
			ans = now; t = i;
		}
	}
	cout << t << " "<< ans << endl;
	return 0;
}