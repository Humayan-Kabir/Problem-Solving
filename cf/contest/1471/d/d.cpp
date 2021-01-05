/* بسم الله الرحمن الرحيم
 * Author: kabir10
 * Time: 2021-01-05 22:06:06
**/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX 1000007

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

void Sieve() {
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (LL i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (LL j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
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
        int individualMax = 0, evenSum = 0;
        map<int,int> maping;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            int modified = 1;
            while(num > 1) {
                int counter = 0, prime = sp[num];
                while(num % prime == 0 && num > 1) {
                    num = num / prime;
                    counter++;
                }
                if(counter & 1) modified = modified * prime;
            }
            maping[modified]++;
        }
        int mx1 = 0, mx2 = 0;
        for(auto it : maping) {
            mx1 = max(mx1, it.second);
            if(it.first > 1 && it.second % 2 == 0) {
                mx2 += it.second;
            }
        }
        if(maping.find(1) != maping.end()) mx2 += maping[1];
        int q;
        cin >> q;
        while(q--) {
            LL w;
            cin >> w;
            if(w == 0LL) {
                cout << mx1 << endl;
            } else {
                cout << max(mx2, mx1) << endl;
            }
        }
    }
    return 0;
}
