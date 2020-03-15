#include<bits/stdc++.h>
#define mx 2000007
#define mod 1000000007
using namespace std;
typedef long long int LL;
const int N = 20;
int ara[mx], dp[mx], ans[mx];
struct node {
	int p, k, id;
	node() {}
	bool operator < (const node &a) const {
		return k < a.k;
	}
} vt[mx];
void dpFunc(int k, int n) {
	for(int i = n; i >= 1; i--) {
		int next = ara[i] + i + k;
		if(next > n) {
			dp[i] = 1;
		}
		else {
			dp[i] = 1 + dp[next];
		}	
	}
	
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ara[i];
	}
	int q;
	cin >> q;
	for(int  i = 1; i <= q; i++) {
		cin >> vt[i].p >> vt[i].k;
		vt[i].id = i;
	}
	sort(vt + 1, vt + q + 1);
	for(int i = 1, pre = 0; i <= q; i++) {
		if(vt[i].k > 310) {
			int cur = vt[i].p, res = 0;
			while(cur <= n) {
				res++;
				cur += ara[cur] + vt[i].k;
			}
			ans[vt[i].id] = res;
			continue;
		}
		if(pre != vt[i].k) { 
			dpFunc(vt[i].k, n);
			pre = vt[i].k;
		}
		ans[vt[i].id] = dp[vt[i].p];
	}
	for(int i = 1; i <= q; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
