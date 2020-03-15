/*input
1
z
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
	string str;
	cin >> str;
	int cur = 1, add = 2;
	while(cur <= n) {
		cout << str[cur - 1];
		cur += add;
		add++;
	}
	cout << endl;
	return 0;
}