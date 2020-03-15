#include<bits/stdc++.h>
#define mx 200007
typedef long long int LL;
using namespace std;
namespace solve {
	LL a[mx], sum[mx], dpDown[mx], dpUp[mx];
	vector<int> graph[mx];
	void rec(int u, int p) {
		sum[u] = a[u];
		for(int v : graph[u]) {
			if(v == p) continue;
			rec(v, u);
			dpDown[u] += dpDown[v] + sum[v];
			sum[u] += sum[v];
		}
	}
	void dfs(int u, int p) {
		for(int v : graph[u]) {
			if(v == p) continue;
			dpUp[v] = dpDown[u] - dpDown[v] - sum[v] + (sum[1] - sum[v]) + dpUp[u];
			dfs(v, u);
		}
	}
	void takeInput() {
		ios_base::sync_with_stdio(false);
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		rec(1, -1);
		dfs(1, -1);
		LL res = 0;
		for(int i = 1; i <= n; i++) {
			res = max(res, dpDown[i] + dpUp[i]);
			//cerr << dpDown[i] << " ranges2 " << dpUp[i] << endl;
		}
		cout << res << endl;	
	}
}
int main() {
	solve::takeInput();
	return 0;
}
	
