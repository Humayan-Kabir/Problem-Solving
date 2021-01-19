/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-19 20:50:26
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX 50007

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

typedef long long int LL;

bool v[MAX];
int len, sp[MAX];
vector<int> primes;

void Sieve() {
	for (int i = 4; i < MAX; i += 2)	v[i] = true;//even numbers have smallest prime factor 2
	for (LL i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (LL j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
    for(int i = 2; i < MAX; i++) {
        if(v[i] == false) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    Sieve();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int pre = 1, counter = 2;
        LL ans = 1, ans2 = 1;
        for(int num : primes) {
            if(abs(num - pre) >= n) {
                ans = ans * num;
                pre = num;
                counter--;
            }
            if(counter == 0) break;
        }
        cout << ans << endl;
    }
    return 0; 
}
