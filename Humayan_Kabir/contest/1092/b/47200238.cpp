/*input
6
5 10 2 3 14 5
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
	int ara[n + 2];
	for(int i = 1; i <= n; i++) {
		cin >> ara[i];
	}
	int ans = 0;
	sort(ara + 1, ara + n + 1);
	for(int i = 2; i <= n; i+=2) {
		ans += (ara[i] - ara[i - 1]);
	}
	cout << ans << endl;
	return 0;
}