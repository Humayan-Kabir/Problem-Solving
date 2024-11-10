#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
typedef long long int LL;

/*
go north (represented by N), moving to (x,y+1)
;
go east (represented by E), moving to (x+1,y)
;
go south (represented by S), moving to (x,y−1)
; or
go west (represented by W), moving to (x−1,y)
.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
		int n, m, v; cin >> n >> m >> v;
		vector<int> vt(n);
		vector<int> p(n);
		vector<int> s(n);
		for(int i = 0; i < n; i++) cin >> vt[i];
		int sum = 0;
		int counter = 0;
		LL mx_result = 0;
		LL ans = -1;
		for(int i = 0; i < n; i++) {
			sum += vt[i];
			mx_result += vt[i];
			p[i] = counter;
			if (sum >= v) {
				++counter; 
				sum = 0;
			}
		}
		if (counter >= m) ans = 0;
		sum = 0; counter = 0;
		for(int i = n - 1; i >= 0; i--) {
			sum += vt[i];
			s[i] = counter;
			if (sum >= v) {
				++counter;
				sum = 0;
			}
		}
		if (counter >= m) ans = 0;
		// debug(p);
		// debug(s);
		auto check = [&](LL mid) -> bool {
			LL cur_sum = 0;
			for(int l = 0, r = 0; r < n; r++) {
				cur_sum += vt[r];
				if (cur_sum < mid) continue;
				while(l <= r && cur_sum - vt[l] >= mid) {
					cur_sum -= vt[l];
					l++;
				}
				if (p[l] + s[r] >= m) {
					// debug(l, r, mid);
					return true;
				}
			}
			return false;
		};
		LL low = 1, high = mx_result;
		while(low <= high) {
			LL mid = (low + high) / 2L;
			if (check(mid)) {
				ans = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
