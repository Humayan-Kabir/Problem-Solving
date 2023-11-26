#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		int root = sqrt(n);
		auto calculate = [&](int k) -> long long {
			long long minN = 1e16;
			long long maxN = -1e16;
			long long sum = 0;
			for(int i = 1; i <= n; i++) {
				sum += 1LL * v[i - 1];
				if (i % k == 0) {
					minN = min(minN, sum);
					maxN = max(maxN, sum);
					sum = 0;
				}
			}
			return maxN - minN;	
		};
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			if (n % i == 0) {
				ans = max(ans, calculate(i));
				if (n / i != i) {
					ans = max(ans, calculate(n / i));
				}		
			}
		}
		cout << ans << endl;
	}
	return 0;	
}
