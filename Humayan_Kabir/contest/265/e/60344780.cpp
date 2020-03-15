#include<bits/stdc++.h>
#define mx 200007
typedef long long int LL;
using namespace std;
namespace solve {
	LL c[mx], v[mx], dp[mx];
	void takeInput() {
		int n, q;
		cin >> n >> q;
		for(int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for(int i = 1; i <= n; i++) {
			cin >> c[i]; 
		}
		while(q--) {
			LL x, y;
			cin >> x >> y;
			for(int i = 1; i <= n; i++) {
				dp[i] = -1e17;
				//cout << dp[i] << endl;
			}
			pair<LL,int> mx1, mx2;
			mx1 = mx2 = {-1e17, 0};
			for(int i = 1; i <= n; i++) {
				LL res = v[i] * y;
				if(mx1.second != c[i]) {
					res = max(res, mx1.first + y * v[i]);
				}
				if(mx2.second != c[i]) {
					res = max(res, mx2.first + y * v[i]);
				}
				res = max(res, dp[c[i]] + x * v[i]);
				dp[c[i]] = max(dp[c[i]], res);
				pair<LL,int> cur = {res, c[i]};
				if(res > mx1.first) {
					if(mx1.second == cur.second) mx1 = cur;
					else {
						mx2 = mx1;
						mx1 = cur;
					}
				}
				else if(res > mx2.first && mx1.second != c[i]) {
					mx2 = cur;
				}
			}
			cout << max(0LL, mx1.first) << endl;
		}
	}
}
int main() {
	solve::takeInput();
	return 0;
}
	
