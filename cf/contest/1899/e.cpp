#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		int mn = INT_MAX;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			mn = min(mn, v[i]);
		}
		int ans = -1;
		for(int i = 0; i < n; i++) {
			if (v[i] == mn) {
				bool ok = true;
				for(int j = i + 1; j < n; j++) {
					if (v[j] < v[j - 1]) ok = false;
				}
				if (ok) {
					ans = i;
				}
				break;

			}
		}
		cout << ans << endl;
	}
	return 0;	
}

