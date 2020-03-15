/*input
8
hhzarwde
3 2 6 9 4 8 7 1
*/
#include <bits/stdc++.h>
#define mod 998244353
#define mx 100007
using namespace std;
typedef long long int LL;
LL dp[mx][5], ara[mx], MAX = 100000000000000000;
string str;
int n, mark[200];
LL rec(int pos,int pre) {
	if(pre == 4) return MAX;
	if(pos >= n) return 0;
	LL &ret = dp[pos][pre];
	if(ret != -1) return ret;
	if(str[pos] != 'h' && str[pos] != 'a' && str[pos] != 'r' && str[pos] != 'd') {
		ret = rec(pos + 1, pre);
		return ret;
	}
	LL now = MAX;
	if(pre == 3 && mark[str[pos]] == 4) {
		now = min(now, ara[pos] + rec(pos + 1, pre));
	}
	if(pre + 1 == mark[str[pos]]) {
		now = min(now, rec(pos + 1, pre + 1));
	}
	else if(pre > mark[str[pos]]) {
		now = min(now, rec(pos + 1, pre));
	}
	else {
		now = min(now, rec(pos + 1, pre));
	}
	now = min(now, ara[pos] + rec(pos + 1, pre));
	return ret = now;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	mark['h'] = 1;
	mark['a'] = 2;
	mark['r'] = 3;
	mark['d'] = 4;
	cin >> n;
	cin >> str;
	for(int i = 0; i < n; i++) {
		cin >> ara[i];
	}
	memset(dp, -1, sizeof dp);
	cout << rec(0,0) << endl;
	return 0;
}