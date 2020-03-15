/*input
4
1 3 3 7
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);	
	int n;
	cin >> n;
	vector<int> vt;
	for(int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		vt.push_back(num);
	}
	sort(vt.begin(), vt.end());
	if(n == 2) {
		cout << 0 << endl;
		return 0;
	}
	int ans = vt[n - 1] - vt[1];
	int ans2 = vt[n - 2] - vt[0];
	cout << min(ans, ans2) << endl;
	return 0;
}