/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2022-08-27 21:06:44
 * SUST CSE '15
**/
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

int main() {
 	ios_base::sync_with_stdio(false); cin.tie(nullptr);
 	int t; cin >> t;
 	while(t--) {
 		int n; cin >> n;
 		vector<int> a(n);
 		vector<int> b(n);
 		for(int i = 0; i < n; i++) cin >> a[i];
 		for(int i = 0; i < n; i++) cin >> b[i];
 		vector<int> minAns(n);
 		vector<int> maxAns(n);
 		vector<int> next(n);
 		for(int i = 0, j = 0; i < n; i++) {
 			while(j < i && b[j] < a[i]) j++;
 			minAns[i] = b[j] - a[i];
 		}
 		for(int i = n - 1; i >= 0; i--) {
 			if (i == n - 1) {
 				next[i] = i;                                                                                                                                                                   
 			} else if (b[i] >= a[i + 1]) {
 				next[i] = next[i + 1];
 			} else {
 				next[i] = i;
 			}
 			maxAns[i] = b[next[i]] - a[i];
 		}
 		for(int i = 0; i < n; i++) {
 			if (i > 0) cout << " ";
 			cout << minAns[i];
 		}
 		cout << "\n";
 		for(int i = 0; i < n; i++) {
 			if (i > 0) cout << " ";
 			cout << maxAns[i];
 		}
 		cout << "\n";
 	}   
    return 0;
}