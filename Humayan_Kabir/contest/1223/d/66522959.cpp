#include<bits/stdc++.h>
using namespace std;
namespace sequenceSorting {
	const int mx = 300007;
	int arr[mx], dist[mx], in[mx], out[mx], vis[mx], Timer = 0;
	void solve() {
		int n; Timer++;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", arr + i);
			if(vis[arr[i]] != Timer) {
				in[arr[i]] = out[arr[i]] = i;
				vis[arr[i]] = Timer; 
			} else {
				out[arr[i]] = i;
			}
		}
		sort(arr + 1, arr + n + 1);
		int ans = 0, counter = 0, dp[n + 1] = {0};
		for(int i = 1; i <= n; i++) {
			if(arr[i] == arr[i - 1]) continue;
			dist[++counter] = arr[i];
		}
		for(int i = 1; i <= counter; i++) {
			int cur = i;
			while(cur + 1 <= counter && in[dist[cur + 1]] > out[dist[cur]]) cur++;
			ans = max(ans, cur - i + 1);
			i = cur;
		} 
		printf("%d\n", counter - ans);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		sequenceSorting::solve();	
	}
	return 0;
}