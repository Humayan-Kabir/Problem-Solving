/*input
4 3
9 2
0 1
*/
#include <bits/stdc++.h>
#define mod 998244353
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[200];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int w, h;
	cin >> w >> h;
	int u, v;
	cin >> u >> v;
	ara[v] = u;
	cin >> u >> v;
	ara[v] = u;
	int ans = w;
	for(int i = h; i>=0; i--) {
		ans+=i;
		if(ara[i] > 0) {
			ans -= ara[i];
			ans = max(0, ans);
		}
	}
	cout << ans << endl;
	return 0;
}