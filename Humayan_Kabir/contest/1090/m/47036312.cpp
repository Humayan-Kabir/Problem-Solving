/*input
8 3
1 2 3 3 2 1 2 2
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
	vector<int> ara; 
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		int num;
		scanf("%d",&num);
		ara.push_back(num);
	}
	int ans = 1;
	for(int i = 0, j = 0; i < n; i++) {
		if(j < i) j = i;
		while( (j + 1) < n && ara[j + 1] != ara[j]) {
			j++;
		}
		ans = max(ans, j - i + 1);
	}
	printf("%d\n", ans);
	return 0;
}