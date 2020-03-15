/*input
ab?a
1
*/
#include <bits/stdc++.h>
#define mod 998244353
#define mx 200007
using namespace std;
typedef long long int LL;
string str;
int len, dp[207][607], k;
deque<char> dq;
int rec(int pos,int preSum) {
	if(pos >= len) {
		if(preSum == k) return 1;
		else return 0; 
	}
	int &ret = dp[pos][preSum];
	if(ret != -1) return ret;
	int now = 0;
	if(str[pos] == '?') {
		now = now | rec(pos + 1, preSum - 1);
		now = now | rec(pos + 1, preSum);
	}
	else if(str[pos] == '*') {
		now = now | rec(pos + 1, preSum - 1);
		now = now | rec(pos + 1, preSum);
		for(int i = 1; i <= 200; i++) {
			if(preSum + i > 600) break;
			now = now | rec(pos + 1, preSum + i);
		}
	}
	else {
		now = now | rec(pos + 1, preSum + 1);
	}
	return ret = now;
}
void fun(int pos, int preSum) {
	if(pos >= len) return;
	int now = 0;
	if(str[pos] == '?') {
		if(rec(pos + 1, preSum - 1)) {
			dq.pop_back();
			fun(pos + 1, preSum - 1);
		}
		else {
			fun(pos + 1, preSum);
		}
	}
	else if(str[pos] == '*') {
		if(rec(pos + 1, preSum - 1)) {
			dq.pop_back();
			fun(pos + 1, preSum - 1);
			return;
		}
		else if (rec(pos + 1, preSum)){
			fun(pos + 1, preSum);
			return;
		}
		else {
			for(int i = 1; i <= 200; i++) {
			if(preSum + i > 600) break;
			if(rec(pos + 1, preSum + i) == 1) {
				int x = i;
				while(x--) {
					dq.push_back(str[pos - 1]);
				}
				fun(pos + 1, preSum + i);
				return;
				break;
			}
		}
		}
	}
	else {
		dq.push_back(str[pos]);
		fun(pos + 1, preSum + 1);
	}
	return;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin >> str;
	cin >> k;
	len = str.length();
	memset(dp, -1, sizeof dp);
	int ans = rec(0,0);
	if(ans == 0) {
		cout << "Impossible" << endl;
	}
	else {
		fun(0,0);
		for(int i = 0; i < dq.size(); i++ ) {
			cout << dq[i];
		}
		cout << endl;
	}
	return 0;
}