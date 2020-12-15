/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2020-12-07 15:54:48
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mx 300007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void fun(vector<int> &arr, vector<int> &lengthOfMin, int n) {
	
	stack<int> pile;
	for(int i = 1; i <= n; i++) {
		while(!pile.empty() && arr[i] < arr[pile.top()]) {
			pile.pop();
		}
		if(pile.empty()) {
			lengthOfMin[i] = i;
		} else {
			lengthOfMin[i] = i - pile.top();
		}
		pile.push(i);
	}
}

void fun1(vector<int> &arr, vector<int> &lengthOfMin, int n) {
	
	stack<int> pile;
	for(int i = 1; i <= n; i++) {
		while(!pile.empty() && arr[i] <= arr[pile.top()]) {
			pile.pop();
		}
		if(pile.empty()) {
			lengthOfMin[i] = i;
		} else {
			lengthOfMin[i] = i - pile.top();
		}
		pile.push(i);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n + 2);
		vector<int> lengthOfLeft(n + 7, 0);
		vector<int> lengthOfRight(n + 7, 0);
		vector<int> lengthOfMin(n + 7, 0);
		vector<vector<int>> decision(n + 7, {0, 0});

        for(int i = 1; i <= n; i++) cin >> arr[i];
       
	    fun(arr, lengthOfLeft, n);
		reverse(arr.begin(), arr.end());
		fun1(arr, lengthOfRight, n);
		reverse(arr.begin(), arr.end());

		decision[0][0] = INT_MAX;
		decision[n + 1][1] = INT_MIN;

		for(int i = 1; i <= n; i++) {
			lengthOfMin[arr[i]] = max(lengthOfMin[arr[i]], lengthOfLeft[i] + lengthOfRight[n - i + 1] - 1); 
			// debug(lengthOfLeft[i], lengthOfRight[n - i + 1]);
		}

		for(int i = 1; i <= n; i++) {
			// debug(lengthOfLeft[i], lengthOfRight[i]);
			decision[i][0] = min(decision[i - 1][0], lengthOfMin[i]);
		}
		for(int i = n; i >= 1; i--) {
			decision[i][1] = max(decision[i + 1][1], lengthOfMin[i]);
		}
		string ans = "";
		for(int k = 1; k <= n; k++) {
			if(decision[n - k + 1][0] >= k && decision[n - k + 2][1] < k) {
				ans += '1';
			} else {
				ans += '0';
			}
			// debug(decision[n - k + 1][0], decision[n - k + 2][1]);
		}
		cout << ans << endl;
    }
    return 0;
}
