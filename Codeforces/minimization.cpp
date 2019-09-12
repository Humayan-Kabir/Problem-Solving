#include<bits/stdc++.h>
#define mx 300007
#define inf 1e16
typedef long long int LL;
using namespace std;
namespace solve {
	LL ar[mx], dp[5001][5001];
	bool isValid(int i, int j) {
		return (i >= 0 && j >= 0);	 
	}
	void takeInput() {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			cin >> ar[i];
		}
		sort(ar + 1, ar + n + 1);
		int x = n / k, y = x + 1, normal = k - (n % k), extra = (n % k); 
		for(int i = 0; i <= normal; i++) {
			for(int j = 0; j <= extra; j++) {
				dp[i][j] = inf;
				if(isValid(i, j - 1)) {
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + ar[i * x + j * y] - ar[i * x + j * y - y + 1]);
				}
				if(isValid(i - 1, j)) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + ar[i * x + j * y] - ar[i * x + j * y - x + 1]);
				}
				if(dp[i][j] == inf) {
					dp[i][j] = 0;
				}
			}
		}
		cout << dp[normal][extra] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	solve::takeInput();
	return 0;
}
	
