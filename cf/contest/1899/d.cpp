#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		unordered_map<int,int> counter;
		for(int i = 0; i < n; i++) {
			int num; cin >> num;
			counter[num]++;
		}
		long long ans = 0;
		for(auto it = counter.begin(); it != counter.end(); it++) {
			long long cnt = it->second;
			ans += (1LL * cnt * (cnt - 1)) / 2LL;
		}
		ans += (1LL * counter[2] * counter[1]);
		cout << ans << endl;
	}
	return 0;	
}

