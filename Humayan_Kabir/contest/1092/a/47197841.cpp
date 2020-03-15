/*input
3
7 3
4 4
6 2
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
	int t, n, k;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int cnt = n;
		while(1) {
			for(int i = 1; i <= k; i++) {
				char ch = 'a' + (i - 1);
				cout << ch;
				cnt--;
				if(cnt == 0) break;
			}
			if(cnt <= 0) break;
		}
		cout << endl;
	}
	return 0;
}