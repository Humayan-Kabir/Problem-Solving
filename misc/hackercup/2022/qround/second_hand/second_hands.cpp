#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
	    int n, k; cin >> n >> k;
        unordered_map<int, int> hashMap;
        bool isValid = (2 * k >= n);
	    for(int i = 0; i < n; i++) {
	        int num; cin >> num;
	        hashMap[num]++;
	        if (hashMap[num] > 2) {
	            isValid = false;
	        }
	    }
	    cout << "Case #" << i << ": " << (isValid ? "YES" : "NO") << "\n";		
	}
}