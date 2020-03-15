#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
bool comp(pair<LL,LL> a, pair<LL,LL> b) {
	LL x = a.first - a.second;
	LL y = b.first - b.second;
	return x > y;
}
int main(int argc, char const *argv[])
{
	vector< pair<LL,LL> > vt;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		LL a, b;
		cin >> a >> b;
		vt.push_back({a, b});
	}
	LL ans = 0;
	sort(vt.begin(), vt.end(), comp);
	for(int i = 0; i < n; i++) {
		//cout << vt[i].first << " ... " << vt[i].second << endl;
		ans += vt[i].first * 1LL * i;
		ans += (vt[i].second * 1LL * (n - i - 1));
	}
	cout << ans << endl;
	return 0;
}