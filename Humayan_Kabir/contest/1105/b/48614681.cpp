/*input
4 2
abab
*/
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long int LL;
int ans[30];
int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	char cur;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			cnt++; cur = str[i];
		}
		else if(str[i] == cur) {
			cnt++;
		}
		else {
			int id = cur - 'a';
			ans[id] += (cnt / k);
			cnt = 1;
			cur = str[i];
		}
	}
	if(cnt != 0) {
		int id = cur - 'a';
		ans[id] += (cnt / k);
	}
	int mx = 0;
	for(int i = 0; i < 27; i++) {
		mx = max(mx, ans[i]);
	}
	cout << mx << endl;
	return 0;
}