#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		int ans = v[0];
		int sum = INT_MIN;
		int pre = -1;
		for(int i = 0; i < n; i++) {
			int pt = v[i] & 1;
			if (sum < 0 || (pt == pre)) {
				sum = v[i];
				pre = pt;
			} else {
				sum += v[i];
				ans = max(ans, sum);
				pre ^= 1;
			}
			ans = max(ans, sum);
		}
		cout << ans << endl; 
	}
	return 0;	
}
